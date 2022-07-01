#include "typecheck.h"

namespace fx {

bool TypeChecker::isSubtype(AstNodePtr a, AstNodePtr b) {
    return a->Type() == b->Type();
}

TypeCheckResult TypeChecker::checkBinaryOp(AstNodePtr ptr) {
    if (!ptr) {
        return TypeCheckResult("pass nil to checkBinaryOp");
    }
    BinaryOperator *op = dynamic_cast<BinaryOperator*>(ptr.get());
    if (!op) {
        return TypeCheckResult("pass nil to checkBinaryOp");
    }
    if (!isSubtype(op->lhs, op->rhs)) {
        return TypeCheckResult("incompatible type in BinaryOperator");
    }
    return TypeOk;
}

TypeCheckResult TypeChecker::check(Env env, Decls decls) {
    for (auto n : decls.decls) {
    }
    return TypeOk;
}


}


