
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
    class Env {
    public:
        AstNodePtr lookup_var(std::string const &nominal) {
            return vars_.lookup(nominal);
        }
        AstNodePtr lookup_func(std::string const &nominal) {
            return funs_.lookup(nominal);
        }
        void put_var(AstNodePtr node) {
            vars_.put(node->nominal(), node);
        }
        void put_func(AstNodePtr node) {
            funs_.put(node->nominal(), node);
        }
        void enter() {
            vars_.enter(); funs_.enter();
        }
        void leave() {
            vars_.leave(); funs_.leave();
        }
    private:
        Scope<AstNodePtr> vars_;
        Scope<AstNodePtr> funs_;
    };

    Env env;
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
