
#ifndef TYPE_CHECK_H_
#define TYPE_CHECK_H_

#include <string>
#include <map>
#include "astnode.h"

namespace fx {

struct TypeCheckResult {
    std::string errmsg;

    TypeCheckResult() : errmsg("") {}
    TypeCheckResult(const char *msg) : errmsg(msg) {}
};

struct Env : public std::map<std::string, Ty> {
};

const TypeCheckResult TypeOk = TypeCheckResult("Ok");

class TypeChecker {

public:
    TypeCheckResult check(Env env, Decls decls);
private:
    bool isSubtype(AstNodePtr a, AstNodePtr b);
    TypeCheckResult checkBinaryOp(AstNodePtr ptr);
};


} // namespace fx

#endif
