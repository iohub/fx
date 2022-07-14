
#ifndef TYPE_CHECK_H_
#define TYPE_CHECK_H_

#include <string>
#include <map>
#include "astnode.h"
#include "env.h"

namespace fx {

struct TypeCheckResult {
    std::string errmsg;

    TypeCheckResult() : errmsg("") {}
    TypeCheckResult(std::string msg) : errmsg(msg) {}

    bool operator==(const TypeCheckResult& b) { return errmsg == b.errmsg; }
    bool operator!=(const TypeCheckResult& b) { return  errmsg != b.errmsg; }
};


const TypeCheckResult TypeOk = TypeCheckResult("Ok");

class TypeChecker {
public:
    TypeCheckResult check(AstNodePtr any);

private:
    Env<AstNodePtr, AstNodePtr> env;
    bool isSubtype(AstNodePtr a, AstNodePtr b);
    TypeCheckResult checkBinaryOp(AstNodePtr op);
    TypeCheckResult checkFuncDecl(AstNodePtr func);
    TypeCheckResult checkAssign(AstNodePtr assign);
    TypeCheckResult checkVarRef(AstNodePtr var);
    TypeCheckResult checkCall(AstNodePtr call);
    TypeCheckResult checkReturn(AstNodePtr Return);
    TypeCheckResult checkDecls(AstNodePtr declList);
    TypeCheckResult checkIf(AstNodePtr If);
    TypeCheckResult checkFor(AstNodePtr For);
    TypeCheckResult checkStmts(Stmts *stmts);

    Ty synthesize(AstNodePtr n);
    Ty synthesize(ReturnStmt *n);
    Ty synthesize(Call *n);
    Ty synthesize(Val *n);
    Ty synthesize(BinaryExpr *n);
};


} // namespace fx

#endif
