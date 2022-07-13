#include "typecheck.h"
#include "util.h"

namespace fx {

bool TypeChecker::isSubtype(AstNodePtr a, AstNodePtr b) {
    return a->Type() == b->Type();
}

TypeCheckResult TypeChecker::checkBinaryOp(Env &env, AstNodePtr ptr) {
    BinaryExpr *op = dynamic_cast<BinaryExpr*>(ptr.get()); assert(op);
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
    nn->ty = fndecl->Type();
    nn->synthesized = true;
    return TypeOk;
}

TypeCheckResult TypeChecker::checkFor(Env &env, AstNodePtr For) {
    ForStmt *nn = dynamic_cast<ForStmt*>(For.get()); assert(nn);
    TypeCheckResult result;
    if ((result = check(env, nn->init_stmt)) != TypeOk) return result;
    if ((result = check(env, nn->cond_stmt)) != TypeOk) return result;
    if ((result = check(env, nn->next_stmt)) != TypeOk) return result;

    if (nn->cond_stmt && nn->cond_stmt->ty != TypeID::Bool &&
            !(nn->cond_stmt->is(Kind::Nil))) {
        return TypeCheckResult(fmt::format("{} incompatible conditional type:{} bool",
                    nn->loc(), nn->cond_stmt->TyStr()));
    }
    if (nn->body) {
        for (AstNodePtr p : *(nn->body)) {
            if ((result = check(env, p)) != TypeOk) {
                return result;
            }
        }
    }

    return TypeOk;
}

TypeCheckResult TypeChecker::checkVarRef(Env &env, AstNodePtr val) {
    Val *nn = dynamic_cast<Val*>(val.get()); assert(nn);
    TypeCheckResult result;
    Ty ty = synthesize(env, nn);

    return TypeOk;
}

TypeCheckResult TypeChecker::check(Env &env, AstNodePtr any) {
    if (!any) return TypeOk;
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
        case Kind::Assign:
            return checkAssign(env, any);
        case Kind::For:
            return checkFor(env, any);
        case Kind::VarRef:
            return checkVarRef(env, any);
        case Kind::Nil:
            return TypeOk;
        default:
            return TypeCheckResult(fmt::format("{} check Unknown kind:{},{}",
                        any->loc(), uint16_t(any->kind), any->dump()));
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
                env.put_func(n);
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
    AssignStmt* nn = dynamic_cast<AssignStmt*>(assign.get()); assert(nn);
    Ty varty, valty;
    if ((varty = synthesize(env, nn->var_)).unresolved()) {
        return TypeCheckResult(fmt::format("{} variable unresolved type", nn->var_->loc()));
    }
    if ((valty = synthesize(env, nn->val_)).unresolved()) {
        return TypeCheckResult(fmt::format("{} value unresolved type", nn->val_->loc()));
    }
    if (!(nn->var_)->is(Kind::VarRef)) {
        return TypeCheckResult(fmt::format("{} only allow assign to variable", nn->var_->loc()));
    }
    TypeCheckResult result;
    if ((result = check(env, nn->val_)) != TypeOk) {
        return result;
    }
    if (nn->var_->Type() != nn->val_->Type()) {
        return TypeCheckResult(fmt::format("{} cann't assign {} with {}",
                    nn->var_->loc(), nn->var_->TyStr(), nn->val_->TyStr()));
    }
    return TypeOk;
}

TypeCheckResult TypeChecker::checkStmts(Env &env, Stmts *stmts) {
    if (!stmts) return TypeOk;
    TypeCheckResult result = TypeOk;
    for (auto n : *stmts) {
        if ((result = check(env, n)) != TypeOk) return result;
    }
    return TypeOk;
}

TypeCheckResult TypeChecker::checkIf(Env &env, AstNodePtr If) {
    IfStmt *nn = dynamic_cast<IfStmt*>(If.get()); assert(nn);
    TypeCheckResult result = TypeOk;
    if ((result = check(env, nn->cond_)) != TypeOk) return result;
    if ((result = checkStmts(env, nn->then_)) != TypeOk) return result;
    if ((result = checkStmts(env, nn->else_)) != TypeOk) return result;

    return TypeOk;
}

TypeCheckResult TypeChecker::checkReturn(Env &env, AstNodePtr Return) {
    ReturnStmt *nn = dynamic_cast<ReturnStmt*>(Return.get()); assert(nn);
    return check(env, nn->stmt);
}

TypeCheckResult TypeChecker::checkFuncDecl(Env &env, AstNodePtr n) {
    FuncDecl *fn = dynamic_cast<FuncDecl*>(n.get()); assert(fn);
    Defer defer([&]() { env.enter(); }, [&]() { env.leave(); });

    for (auto arg : fn->args()) env.put_var(arg);
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
                 env.put_var(n); break;
            default:
                 result = check(env, n);
        }
        if (result != TypeOk) return result;
    }
    return foundReturn && !fn->Type().is(TypeID::Void) ?
        TypeOk : TypeCheckResult("No Value return in non-void function");
}

Ty TypeChecker::synthesize(Env &env, ReturnStmt *n) {
    if (n->synthesized) return n->ty;
    if (!n->stmt->synthesized) {
        synthesize(env, n->stmt);
        n->ty = n->stmt->Type();
    }
    n->synthesized = true;
    return n->ty;
}

Ty TypeChecker::synthesize(Env &env, Val *n) {
    if (n->synthesized) return n->ty;
    if (n->is(Kind::VarRef)) {
        AstNodePtr decl = env.lookup_var(n->nominal());
        n->ty =  decl ? decl->Type() : TypeID::UnResolved;
    }
    n->synthesized = true;
    return n->ty;
}

Ty TypeChecker::synthesize(Env &env, Call *n) {
    if (n->synthesized) return n->ty;
    if (AstNodePtr decl = env.lookup_func(n->nominal())) {
        n->ty = decl->Type();
    }
    n->synthesized = true;
    return n->ty;
}

Ty TypeChecker::synthesize(Env &env, BinaryExpr *n) {
    if (n->synthesized) return n->ty;
    if (!(n->ty).nil()) return n->ty;
    Ty lty = synthesize(env, n->lhs);
    Ty rty = synthesize(env, n->rhs);
    n->ty = lty.unresolved() ? lty : rty;
    n->synthesized = true;
    return n->ty;
}

Ty TypeChecker::synthesize(Env &env, AstNodePtr n) {
    if (Call* nn = dynamic_cast<Call*>(n.get())) {
        return synthesize(env, nn);
    }
    if (ReturnStmt *nn = dynamic_cast<ReturnStmt*>(n.get())) {
        return synthesize(env, nn);
    }
    if (Val* nn = dynamic_cast<Val*>(n.get())) {
        return synthesize(env, nn);
    }
    if (BinaryExpr * nn = dynamic_cast<BinaryExpr*>(n.get())) {
        return synthesize(env, nn);
    }
    return TypeID::UnResolved;
}










}
