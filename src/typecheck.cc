#include "typecheck.h"

namespace fx {

bool TypeChecker::isSubtype(AstNodePtr a, AstNodePtr b) {
    return a->Type() == b->Type();
}

TypeCheckResult TypeChecker::checkBinaryOp(Env &env, AstNodePtr ptr) {
    Operator *op = dynamic_cast<Operator*>(ptr.get()); assert(op);
    AstNodePtr lhs = op->lhs, rhs = op->rhs;
    synthesize(env, lhs); synthesize(env, rhs);
    if (!isSubtype(lhs, rhs)) {
        return TypeCheckResult(fmt::format("{} incompatible type ({}) with ({})",
                    op->loc(), lhs->TyStr(), rhs->TyStr()));
    }
    TypeCheckResult result;
    if ((result = check(env, lhs)) != TypeOk) return result;
    if ((result = check(env, rhs)) != TypeOk) return result;
    if ((op->Type()).nil()) {
        op->ty = lhs->ty;
    }
    return TypeOk;
}

TypeCheckResult TypeChecker::checkCall(Env &env, AstNodePtr call) {
    Call *nn = dynamic_cast<Call*>(call.get()); assert(nn);
    AstNodePtr fndecl = env.lookup_func(nn->nominal());
    if (!fndecl) {
        return TypeCheckResult(fmt::format("{} Undefine Call:{}", call->loc(), call->nominal()));
    }
    FuncDecl *fn = dynamic_cast<FuncDecl*>(fndecl.get());
    auto sArgs = fn->args(), dArgs = nn->args();
    if (sArgs.size() != dArgs.size()) {
        return TypeCheckResult(fmt::format("{} Call {} incompatible params", nn->loc(), nn->nominal()));
    }
    for (size_t idx = 0; idx < sArgs.size(); idx++) {
        auto sArg = sArgs[idx], dArg = dArgs[idx];
        TypeCheckResult result = check(env, dArg);
        if (result != TypeOk) return result;
        if (sArg->Type() != dArg->Type()) {
            return TypeCheckResult(fmt::format("{} Call {} incompatible type ({}) ({})",
                        nn->loc(), nn->nominal(), sArg->TyStr(), dArg->TyStr()));
        }
    }
    return TypeOk;
}

TypeCheckResult TypeChecker::check(Env &env, AstNodePtr any) {
    switch(any->kind) {
        case Kind::DeclList:
            return checkDecls(env, any);
        case Kind::CallFunc:
            return checkCall(env, any);
        case Kind::ReturnStmt:
            return checkReturn(env, any);
        case Kind::VarDecl:
            return TypeOk;
        case Kind::Constant:
            return TypeOk;
        case Kind::BinaryOperator:
            return checkBinaryOp(env, any);
        case Kind::If:
            return checkIf(env, any);
        case Kind::VarRef:
            return TypeOk;
        default:
            return TypeCheckResult(fmt::format("{} check Unknown {}", any->loc(), any->dump()));
    }
    return TypeOk;
}

TypeCheckResult TypeChecker::checkDecls(Env &env, AstNodePtr declList) {
    Decls *decls = dynamic_cast<Decls*>(declList.get()); assert(decls);
    TypeCheckResult result = TypeOk;
    FuncDecl *fn;
    for (auto n : decls->decls) {
        switch (n->kind) {
            case Kind::FuncDecl:
                if (!(fn = dynamic_cast<FuncDecl*>(n.get()))) break;
                env.put(n);
                result = checkFuncDecl(env, n);
                if (result != TypeOk) {
                    Logging::info("[error]: {}\n", result.errmsg);
                }
                break;
            default:
                Logging::error("{} Unknown AstNode:{}\n", n->loc(), n->dump());
                break;
        }
    }
    return result;
}

TypeCheckResult TypeChecker::checkAssign(Env &env, AstNodePtr assign) {
    return TypeOk;
}

TypeCheckResult TypeChecker::checkStmts(Env &env, AstNodePtr stmts) {
    Stmts *nn = dynamic_cast<Stmts*>(stmts.get()); assert(nn);
    TypeCheckResult result = TypeOk;
    for (auto n : *nn) {
        if ((result = check(env, n)) != TypeOk) return result;
    }
    return TypeOk;
}

TypeCheckResult TypeChecker::checkIf(Env &env, AstNodePtr If) {
    IfStmt *nn = dynamic_cast<IfStmt*>(If.get()); assert(nn);
    TypeCheckResult result = TypeOk;
    if ((result = check(env, nn->cond_)) != TypeOk) return result;

    return TypeOk;
}

TypeCheckResult TypeChecker::checkReturn(Env &env, AstNodePtr Return) {
    ReturnStmt *nn = dynamic_cast<ReturnStmt*>(Return.get()); assert(nn);
    return check(env, nn->stmt);
}

TypeCheckResult TypeChecker::checkFuncDecl(Env &env, AstNodePtr n) {
    FuncDecl *fn = dynamic_cast<FuncDecl*>(n.get()); assert(fn);
    Env nenv = env;
    for (auto arg : fn->args()) env.put(arg);
    bool foundReturn = false;
    TypeCheckResult result;
    for (auto n : fn->body()) {
        result = TypeOk;
        switch(n->kind) {
            case Kind::ReturnStmt:
                synthesize(env, n); foundReturn = true;
                if ((result = checkReturn(env, n)) != TypeOk) return result;
                if (fn->Type() != n->Type())
                    return TypeCheckResult(fmt::format("{} incompatible type", n->loc()));
                break;
            case Kind::VarDecl:
                 env.put(n); break;
            default:
                 result = check(env, n);
        }
        if (result != TypeOk) return result;
    }
    return foundReturn && !fn->Type().is(TypeID::Void) ?
        TypeOk : TypeCheckResult("No Value return in non-void function");
}

void TypeChecker::synthesize(const Env &env, ReturnStmt *n) {
    if (n->synthesized) return ;
    if (!n->stmt->synthesized) {
        synthesize(env, n->stmt);
        n->ty = n->stmt->Type();
    }
    n->synthesized = true;
}

void TypeChecker::synthesize(const Env &env, Val *n) {
    if (n->synthesized) return ;
    if (n->is(Kind::VarRef)) {
        if (AstNodePtr decl = env.lookup_var(n->nominal())) {
            n->ty =  decl->Type();
        }
    }
    n->synthesized = true;
}

void TypeChecker::synthesize(const Env &env, Call *n) {
    if (AstNodePtr decl = env.lookup_func(*(n->name_))) {
        n->ty = decl->Type();
    }
    n->synthesized = true;
}

void TypeChecker::synthesize(const Env &env, AstNodePtr n) {
    if (Call* nn = dynamic_cast<Call*>(n.get())) {
        synthesize(env, nn);
    }
    if (ReturnStmt *nn = dynamic_cast<ReturnStmt*>(n.get())) {
        synthesize(env, nn);
    }
    if (Val* nn = dynamic_cast<Val*>(n.get())) {
        synthesize(env, nn);
    }
}










}
