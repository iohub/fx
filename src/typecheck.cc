#include "typecheck.h"

namespace fx {

bool TypeChecker::isSubtype(AstNodePtr a, AstNodePtr b) {
    return a->Type() == b->Type();
}

TypeCheckResult TypeChecker::checkBinaryOp(Env &env, AstNodePtr ptr) {
    Operator *op = dynamic_cast<Operator*>(ptr.get());
    if (!op) {
        return TypeCheckResult("Invalid Operator");
    }
    AstNodePtr lhs = op->lhs, rhs = op->rhs;
    synthesize(env, lhs); synthesize(env, rhs);
    if (!isSubtype(lhs, rhs)) {
        return TypeCheckResult(fmt::format("Operator location:{} incompatible type ({}) with ({})",
                    op->location(), lhs->Type().type_name(), rhs->Type().type_name()));
    }
    if ((op->Type()).nil()) {
        op->ty = lhs->ty;
    }
    return TypeOk;
}

TypeCheckResult TypeChecker::checkCall(Env &env, AstNodePtr call) {
    Call *nn = dynamic_cast<Call*>(call.get());
    if (!nn) {
        return TypeCheckResult("Invalid Call");
    }
    AstNodePtr fndecl = env.lookup_func(nn->nominal());
    if (!fndecl) {
        return TypeCheckResult(fmt::format("Undefine Call:{}", nn->nominal()));
    }
    FuncDecl *fn = dynamic_cast<FuncDecl*>(fndecl.get());
    if ((fn->args()).size() != (nn->args()).size()) {
        return TypeCheckResult(fmt::format("Call {} {} missing params", nn->nominal(), nn->location()));
    }
    for (auto arg: nn->args()) {
        AstNodePtr decl = env.lookup_var(arg->nominal());
        if (!decl) {
            return TypeCheckResult(fmt::format("Undefine Call arg:{}{}", arg->nominal(), arg->location()));
        }
    }
    return TypeOk;
}

TypeCheckResult TypeChecker::check(Env &env, Decls *decls) {
    TypeCheckResult result = TypeOk;
    FuncDecl *fn;
    for (auto n : decls->decls) {
        switch (n->kind) {
            case NodeKind::FuncDecl:
                if (!(fn = dynamic_cast<FuncDecl*>(n.get()))) break;
                env.put(n);
                result = checkFuncDecl(env, n);
                if (result != TypeOk) {
                    Logging::info("[error]: {}\n", result.errmsg);
                }
                break;
            default:
                Logging::info("Unknown AstNode:{}\n", uint8_t(n->kind));
                break;
        }
    }
    return result;
}

TypeCheckResult TypeChecker::checkAssign(Env &env, AstNodePtr assign) {
    return TypeOk;
}

TypeCheckResult TypeChecker::checkFuncDecl(Env &env, AstNodePtr n) {
    FuncDecl *fn = dynamic_cast<FuncDecl*>(n.get());
    if (!fn) {
        return TypeCheckResult("Invalid FuncDecl");
    }
    Env nenv = env;
    for (auto arg : fn->args()) env.put(arg);
    bool foundReturn = false;
    TypeCheckResult result;
    for (auto n : fn->body()) {
        result = TypeOk;
        if (n->is(NodeKind::ReturnStmt)) {
            synthesize(env, n);
            foundReturn = true;
            if (n->Type() != fn->Type()) {
                result = TypeCheckResult(fmt::format("function:{} location:{}, incompatible type: Cann't return ({}) with ({})",
                            fn->nominal(), fn->location(), fn->tyname(), n->tyname()));
            }
        } else if (n->is(NodeKind::BinaryOperator)) {
            result = checkBinaryOp(env, n);
        } else if (n->is(NodeKind::VarDecl)) {
            env.put(n);
        } else if (n->is(NodeKind::CallFunc)) {
            result = checkCall(env, n);
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
    if (n->is(NodeKind::VarRef)) {
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
