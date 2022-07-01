
#ifndef ASTNODE_H_
#define ASTNODE_H_


#include <stdint.h>
#include <vector>
#include <string>
#include <memory>
#include <fmt/core.h>
#include "type.h"

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
        Func, Var, Expr, BinaryOperator,
        ReturnStmt,
    };
    Kind kind = Kind::Invalid;

    AstNode(Kind k): kind(k) {}
    AstNode(Kind k, Ty::ID t): kind(k), ty(t) {}
    AstNode(Kind k, Ty ty): kind(k), ty(ty) {}
    AstNode(): kind(Kind::Invalid) {}

    std::string str() { return  fmt::format("({})", raw_str()); }
    void print();
    virtual ~AstNode() { };

    static std::string eval(AstNodePtr n) {
        return n && n->kind != Kind::Nil ? n->str() : "(Nil)";
    };
    Ty Type() const { return ty; }

private:
    virtual std::string raw_str() { return "abstract"; };
    // type annotation
    Ty ty;
};

typedef AstNode::Kind NodeKind;

struct Decls: public AstNode {
    Kind kind = Kind::Func;

    virtual std::string raw_str() {
        std::string str;
        for (auto n : decls) str += n->str();
        return str;
    }
    ~Decls() {
        fmt::print("~Decls({})\n", raw_str());
    }
    void append(struct AstNode* n) {
        if (n != nullptr) {
            decls.push_back(AstNodePtr(n));
        }
    }
    NodeVec decls;
};

struct Expr: public AstNode {
    Kind kind = Kind::Expr;

    virtual std::string raw_str() {
        return "expr";
    }
    ~Expr() {
        fmt::print("~Expr({})\n", raw_str());
    }
};

struct Val: public AstNode {
    std::string *raw_data;

    Val() = delete;
    Val(NodeKind kind, std::string *val) : AstNode(kind), raw_data(val) {}
    Val(NodeKind kind, Ty ty, std::string *val) : AstNode(kind, ty), raw_data(val) {}

    ~Val() {
        fmt::print("~Val({})\n", raw_str());
        if (raw_data != nullptr) {
            delete raw_data;
        }
    }

    virtual std::string raw_str() {
        std::string str;
        switch (kind) {
            case NodeKind::Constant: str = "Constant"; break;
            case NodeKind::Var: str = "Var"; break;
            default: str = "unknown";
        }
        if (raw_data != nullptr) {
            str = fmt::format("{}@{}", str, *raw_data);
        }
        return str;
    }
};

struct VarDecl: public AstNode {
    std::string *raw_data;

    VarDecl() = delete;
    VarDecl(NodeKind kind, std::string *val) : AstNode(kind), raw_data(val) {}
    VarDecl(NodeKind kind, Ty ty, std::string *val) : AstNode(kind, ty), raw_data(val) {}

    ~VarDecl() {
        fmt::print("~VarDecl({})\n", raw_str());
        if (raw_data != nullptr) {
            delete raw_data;
        }
    }

    virtual std::string raw_str() {
        std::string str = "VarDecl";
        if (raw_data != nullptr) {
            str = fmt::format("{}@{}", str, *raw_data);
        }
        return str;
    }
};

struct BinaryOperator: public AstNode {
    AstNodePtr lhs;
    AstNodePtr rhs;
    Kind kind  = NodeKind::BinaryOperator;

    BinaryOperator(Val *l, Val *r) : lhs(l), rhs(r) {}

    virtual std::string raw_str() {
        return fmt::format("binaryop[{}{}]", eval(lhs), eval(rhs));
    }

    ~BinaryOperator() {
        fmt::print("~BinaryOperator({})\n", raw_str());
    }
};

struct FuncDecl: public AstNode {
    Kind kind = Kind::Func;

    virtual std::string raw_str() {
        std::string str = (name != nullptr) ? "FuncDecl@" + *name : "FuncDecl";
        if (args != nullptr) {
            for (auto itr: *args) str += itr->str();
        }
        if (body != nullptr) {
            for (auto itr: *body) str +=  itr->str();
        }
        return fmt::format("({})", str);
    }
    ~FuncDecl() {
        fmt::print("~FuncDecl({})\n", raw_str());
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
    Kind kind = NodeKind::CallFunc;

    virtual std::string raw_str() {
        std::string str = (name != nullptr) ? "call:" + *name : "call";
        if (args != nullptr) {
            for (auto itr: *args) str += itr->str();
        }
        return fmt::format("({})", str);
    }

    ~Call() {
        fmt::print("~callNode({})\n", raw_str());
        if (args != nullptr) delete args;
        if (name != nullptr) delete name;
    }

    Args *args;
    std::string *name;
};

struct ReturnStmt: public AstNode {
    Kind kind = NodeKind::ReturnStmt;

    virtual std::string raw_str() {
        if (stmt) {
            return fmt::format("ReturnStmt:{}", stmt->str());
        }
        return "ReturnStmt";
    }

    ~ReturnStmt() {
        fmt::print("~ReturnStmt({})\n", raw_str());
    }

    AstNodePtr stmt;
};


struct ForStmt: public AstNode {
    AstNodePtr init_stmt;
    AstNodePtr cond_stmt;
    AstNodePtr next_stmt;
    Exprs *body;

    virtual std::string raw_str() {
        std::string str;
        if (body != nullptr) {
            for (auto n: *body) str += n->str();
        }
        return fmt::format("ForStmt<{}{}{}>[{}]",
                eval(init_stmt), eval(cond_stmt), eval(next_stmt), str);
    }
    ~ForStmt() {
        fmt::print("~ForStmt({})\n", raw_str());
        if (body != nullptr) delete body;
    }
};

struct IfStmt: public AstNode {
    AstNodePtr cond_stmt;
    Exprs* then_exprs;
    Exprs* else_exprs;

    virtual std::string raw_str() {
        std::string then_str, else_str;
        if (then_exprs != nullptr) for (auto n: *then_exprs) then_str += n->str();
        if (else_exprs != nullptr) for (auto n: *else_exprs) else_str += n->str();

        return fmt::format("IfStmt<{}>,then[{}],else[{}]",
                eval(cond_stmt), then_str, else_str);
    }
    ~IfStmt() {
        fmt::print("~IfStmt({})\n", raw_str());
        if (then_exprs != nullptr) delete then_exprs;
        if (else_exprs != nullptr) delete else_exprs;
    }
};

}; // end namespace


#endif

