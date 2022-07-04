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
                if (!(fn = dynamic_cast<FuncDecl*>(n.get()))) {
                    break;
                }
                env[fn->nominal()] = fn->Type();
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


TypeCheckResult TypeChecker::checkFuncDecl(Env &env, AstNodePtr n) {
    FuncDecl *fn = dynamic_cast<FuncDecl*>(n.get());
    if (!fn) {
        return TypeCheckResult("Invalid FuncDecl");
    }
    Env nenv = env;
    if (fn->args != nullptr) {
        for (auto arg : *(fn->args)) {
            VarDecl* var = dynamic_cast<VarDecl*>(arg.get());
            if (var) {
                nenv[var->name()] = var->Type();
            }
        }
    }
    bool foundReturn = false;
    if (fn->body != nullptr) {
        for (auto n : *(fn->body)) {
            if (n->is(NodeKind::ReturnStmt)) {
                foundReturn = true;
                if (!n->synthesized()) n->synthesize(env);
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



}


