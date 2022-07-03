
#ifndef ASTNODE_H
#define ASTNODE_H


#include <stdint.h>
#include <vector>
#include <string>
#include <memory>
#include <fmt/core.h>
#include "type.h"
#include "env.h"
#include "util.h"

namespace fx {

class AstNode;
typedef std::shared_ptr<AstNode> AstNodePtr;
typedef std::vector<AstNodePtr> NodeVec;
typedef std::vector<AstNodePtr> Args;
typedef std::vector<AstNodePtr> Exprs;


class AstNode {

public:
    enum class Kind : uint8_t {
        Invalid, Nil, CallFunc, Constant,
        FuncDecl, VarRef, VarDecl, Expr, BinaryOperator,
        ReturnStmt, DeclList
    };
    Kind kind = Kind::Invalid;

    AstNode(Kind k): kind(k) {}
    AstNode(Kind k, Ty ty): kind(k), ty(ty) {}
    AstNode(): kind(Kind::Invalid) {}

    bool is(Kind k) { return kind == k; }
    std::string sexp() { return  fmt::format("({})", dump()); }
    void print();
    virtual ~AstNode() { };

    static std::string eval(AstNodePtr n) {
        return n && n->kind != Kind::Nil ? n->sexp() : "(Nil)";
    };
    Ty Type() const { return ty; }
    std::string tyname() { return ty.type_name(); }
    bool synthesized() const { return m_synthesized;}
    virtual bool synthesize(const Env &env) { return false; }
    virtual std::string dump() { return "abstract"; };

protected:
    // type annotation
    Ty ty;
    bool m_synthesized;
};

typedef AstNode::Kind NodeKind;

struct Decls: public AstNode {
    Decls(): AstNode(Kind::DeclList) {}

    virtual std::string dump() {
        std::string str;
        for (auto n : decls) str += n->sexp();
        return str;
    }
    ~Decls() {
        Logging::debug("~Decls({})\n", dump());
    }
    void append(struct AstNode* n) {
        if (n != nullptr) {
            decls.push_back(AstNodePtr(n));
        }
    }
    NodeVec decls;
};

struct Expr: public AstNode {
    Expr(): AstNode(Kind::Expr) {}

    virtual std::string dump() {
        return "expr";
    }
    ~Expr() {
        Logging::debug("~Expr({})\n", dump());
    }
};

struct Val: public AstNode {
    std::string *raw_data;

    Val() = delete;
    Val(NodeKind kind, std::string *val) : AstNode(kind), raw_data(val) {}
    Val(NodeKind kind, Ty ty, std::string *val) : AstNode(kind, ty), raw_data(val) {}

    ~Val() {
        Logging::debug("~Val({})\n", dump());
        if (raw_data != nullptr) {
            delete raw_data;
        }
    }

    virtual std::string dump() {
        std::string str;
        switch (kind) {
            case NodeKind::Constant: str = "Constant"; break;
            case NodeKind::VarRef: str = "VarRef"; break;
            case NodeKind::VarDecl: str = "VarDecl"; break;
            default: str = "unknown";
        }
        if (raw_data != nullptr) {
            str = fmt::format("{}@{}@{}", str, *raw_data, Type().type_name());
        }
        return str;
    }
};

struct VarDecl: public AstNode {
    std::string *raw_data;
    std::string *var_name;
    std::string *type_name;

    VarDecl() = delete;
    VarDecl(std::string *name, std::string *type, std::string *data)
        : AstNode(NodeKind::VarDecl, Ty(*type)),
        raw_data(data), var_name(name), type_name(type) { }

    std::string name() {
        return var_name != nullptr ? *var_name: "Nil";
    }
    std::string type() {
        return type_name != nullptr ? *type_name: "Nil";
    }

    ~VarDecl() {
        Logging::debug("~VarDecl({})\n", dump());
        if (raw_data != nullptr) delete raw_data;
        if (var_name != nullptr) delete var_name;
        if (type_name != nullptr) delete type_name;
    }
    virtual std::string dump() {
        return fmt::format("VarDecl@{}@{}", *var_name, Type().type_name());
    }
};

struct BinaryOperator: public AstNode {
    AstNodePtr lhs;
    AstNodePtr rhs;
    Kind kind  = NodeKind::BinaryOperator;

    BinaryOperator(Val *l, Val *r) : lhs(l), rhs(r) {}

    virtual std::string dump() {
        return fmt::format("binaryop[{}{}]", eval(lhs), eval(rhs));
    }

    ~BinaryOperator() {
        Logging::debug("~BinaryOperator({})\n", dump());
    }
};

struct FuncDecl: public AstNode {
    FuncDecl() = delete;
    FuncDecl(std::string *name, std::string *type)
        : AstNode(Kind::FuncDecl, Ty(*type)), name(name) { }

    std::string nominal() {
        return name != nullptr ? *name : "Nil";
    }

    virtual std::string dump() {
        std::string str = (name != nullptr) ? "FuncDecl@" + *name : "FuncDecl";
        if (args != nullptr) {
            for (auto itr: *args) str += itr->sexp();
        }
        if (body != nullptr) {
            for (auto itr: *body) str +=  itr->sexp();
        }
        return fmt::format("({})", str);
    }
    ~FuncDecl() {
        Logging::debug("~FuncDecl({})\n", dump());
        if (args != nullptr) {
            delete args;
        }
        if (body != nullptr) {
            delete body;
        }
        if (name != nullptr) {
            delete name;
        }
    }

    NodeVec *args;
    Exprs *body;
    std::string *name;
};

struct Call: public AstNode {
    Call() : AstNode(Kind::CallFunc) {}

    virtual std::string dump() {
        std::string str = (name != nullptr) ? "call:" + *name : "call";
        if (args != nullptr) {
            for (auto itr: *args) str += itr->sexp();
        }
        return fmt::format("({})", str);
    }

    virtual bool synthesize(const Env &env) {
        Ty ty = env.lookup(*name);
        if (!ty.is(TypeID::Nil)) {
            this->ty = ty;
        }
        return !ty.is(TypeID::Nil);
    };

    ~Call() {
        Logging::debug("~callNode({})\n", dump());
        if (args != nullptr) delete args;
        if (name != nullptr) delete name;
    }

    Args *args;
    std::string *name;
};

struct ReturnStmt: public AstNode {
    ReturnStmt(): AstNode(Kind::ReturnStmt) {}
    ReturnStmt(Ty ty)
        : AstNode(Kind::ReturnStmt, ty) { }

    virtual std::string dump() {
        if (stmt) {
            return fmt::format("ReturnStmt:{}", stmt->sexp());
        }
        return "ReturnStmt";
    }

    virtual bool synthesize(const Env &env) {
        if (synthesized()) return true;
        if (!stmt->synthesized()) {
           stmt->synthesize(env);
           ty = stmt->Type();
        }
        m_synthesized = true;
        return true;
    }

    ~ReturnStmt() {
        Logging::debug("~ReturnStmt({})\n", dump());
    }

    AstNodePtr stmt;
};


struct ForStmt: public AstNode {
    AstNodePtr init_stmt;
    AstNodePtr cond_stmt;
    AstNodePtr next_stmt;
    Exprs *body;

    virtual std::string dump() {
        std::string str;
        if (body != nullptr) {
            for (auto n: *body) str += n->sexp();
        }
        return fmt::format("ForStmt<{}{}{}>[{}]",
                eval(init_stmt), eval(cond_stmt), eval(next_stmt), str);
    }
    ~ForStmt() {
        Logging::debug("~ForStmt({})\n", dump());
        if (body != nullptr) delete body;
    }
};

struct IfStmt: public AstNode {
    AstNodePtr cond_stmt;
    Exprs* then_exprs;
    Exprs* else_exprs;

    virtual std::string dump() {
        std::string then_str, else_str;
        if (then_exprs != nullptr) for (auto n: *then_exprs) then_str += n->sexp();
        if (else_exprs != nullptr) for (auto n: *else_exprs) else_str += n->sexp();

        return fmt::format("IfStmt<{}>,then[{}],else[{}]",
                eval(cond_stmt), then_str, else_str);
    }
    ~IfStmt() {
        Logging::debug("~IfStmt({})\n", dump());
        if (then_exprs != nullptr) delete then_exprs;
        if (else_exprs != nullptr) delete else_exprs;
    }
};

}; // end namespace


#endif

