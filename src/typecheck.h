
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

    TypeCheckResult check(BinaryExpr *cmp);
    TypeCheckResult check(FuncDecl *func);
    TypeCheckResult check(AssignStmt *assign);
    TypeCheckResult check(Val *val);
    TypeCheckResult check(Call *call);
    TypeCheckResult check(ReturnStmt *Return);
    TypeCheckResult check(Decls *declList);
    TypeCheckResult check(IfStmt *If);
    TypeCheckResult check(ForStmt *For);
    TypeCheckResult check(LetAssign *LetA);
    TypeCheckResult checkStmts(Stmts *stmts);

    Ty synthesize(AstNodePtr n);
    Ty synthesize(ReturnStmt *n);
    Ty synthesize(Call *n);
    Ty synthesize(Val *n);
    Ty synthesize(BinaryExpr *n);
};


} // namespace fx

#endif
