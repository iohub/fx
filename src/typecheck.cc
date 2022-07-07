#include "typecheck.h"

namespace fx {

bool TypeChecker::isSubtype(AstNodePtr a, AstNodePtr b) {
    return a->Type() == b->Type();
}

TypeCheckResult TypeChecker::checkBinaryOp(AstNodePtr ptr) {
    if (!ptr) {
        return TypeCheckResult("reference to nil");
    }
    Operator *op = dynamic_cast<Operator*>(ptr.get());
    if (!op) {
        return TypeCheckResult("Invalid Operator");
    }
    AstNodePtr lhs = op->lhs, rhs = op->rhs;
    if (!isSubtype(lhs, rhs)) {
        return TypeCheckResult(fmt::format("incompatible type {} with {} in Operator",
                    lhs->Type().type_name(), rhs->Type().type_name()));
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
                // env[fn->nominal()] = fn->Type();
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
    if (fn->args) {
        for (auto arg : *(fn->args)) {
            env.put(arg);
        }
    }
    bool foundReturn = false;
    if (fn->body) {
        for (auto n : *(fn->body)) {
            if (n->is(NodeKind::ReturnStmt)) {
                if (!n->synthesized) synthesize(env, n);
                foundReturn = true;
                if (n->Type() != fn->Type()) {
                    return TypeCheckResult(fmt::format("function:{} incompatible type: Cann't return ({}) with ({})",
                                fn->nominal(), fn->tyname(), n->tyname()));
                }
            }
        }
    }
    return foundReturn && !fn->Type().is(TypeID::Void) ?
        TypeOk : TypeCheckResult("No Value return in non-void function");
}

bool TypeChecker::synthesize(const Env &env, ReturnStmt *n) {
    if (n->synthesized) return true;
    if (!n->stmt->synthesized) {
        synthesize(env, n->stmt);
        n->ty = n->stmt->Type();
    }
    n->synthesized = true;
    return true;
}

bool TypeChecker::synthesize(const Env &env, Call *n) {
    Ty ty = env.lookup(*(n->name));
    if (!ty.is(TypeID::Nil)) {
        n->ty = ty;
    }
    n->synthesized = true;
    return !ty.is(TypeID::Nil);
};

bool TypeChecker::synthesize(const Env &env, AstNodePtr n) {
    if (Call* nn = dynamic_cast<Call*>(n.get())) {
        synthesize(env, nn);
    }
    if (ReturnStmt *nn = dynamic_cast<ReturnStmt*>(n.get())) {
        synthesize(env, nn);
    }
    return true;
};














}
