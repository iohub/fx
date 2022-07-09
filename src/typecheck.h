
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
    static TypeCheckResult check(Env &env, AstNodePtr any);

private:
    static bool isSubtype(AstNodePtr a, AstNodePtr b);
    static TypeCheckResult checkBinaryOp(Env &env, AstNodePtr op);
    static TypeCheckResult checkFuncDecl(Env &env, AstNodePtr func);
    static TypeCheckResult checkAssign(Env &env, AstNodePtr assign);
    static TypeCheckResult checkCall(Env &env, AstNodePtr call);
    static TypeCheckResult checkReturn(Env &env, AstNodePtr Return);
    static TypeCheckResult checkDecls(Env &env, AstNodePtr declList);
    static TypeCheckResult checkIf(Env &env, AstNodePtr If);

    static void synthesize(const Env &env, AstNodePtr n);
    static void synthesize(const Env &env, ReturnStmt *n);
    static void synthesize(const Env &env, Call *n);
    static void synthesize(const Env &env, Val *n);
};


} // namespace fx

#endif
