
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
    static TypeCheckResult check(Env &env, Decls *decls);

private:
    static bool isSubtype(AstNodePtr a, AstNodePtr b);
    static TypeCheckResult checkBinaryOp(AstNodePtr ptr);
    static TypeCheckResult checkFuncDecl(Env &env, AstNodePtr ptr);
    static TypeCheckResult checkAssign(Env &env, AstNodePtr assign);

    static bool synthesize(const Env &env, AstNodePtr n);
    static bool synthesize(const Env &env, ReturnStmt *n);
    static bool synthesize(const Env &env, Call *n);
};


} // namespace fx

#endif
