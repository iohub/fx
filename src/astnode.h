
#ifndef ASTNODE_H
#define ASTNODE_H


#include <stdint.h>
#include <vector>
#include <string>
#include <memory>
#include <fmt/core.h>
#include <nlohmann/json.hpp>
#include "type.h"
#include "location.h"
#include "util.h"

namespace fx {

class AstNode;
typedef std::shared_ptr<AstNode> AstNodePtr;
typedef std::vector<AstNodePtr> NodeVec;
using Args = NodeVec;
using Exprs = NodeVec;
using json = nlohmann::json;

class AstNode {

public:
    enum class Kind : uint8_t {
        Invalid, Nil, CallFunc, Constant,
        FuncDecl, VarRef, VarDecl, Expr, BinaryOperator, UnaryOperator,
        ReturnStmt, DeclList, Undefine
    };
    enum class OpKind: uint8_t {
        Invalid,
        LT, LE, EQ, GT, GE, NEQ, // binaryop
        MUL, DIV, ADD, SUB // unaryop
    };
    Kind kind = Kind::Invalid;

    AstNode(Loc loc, Kind k): loc(loc), kind(k) {}
    AstNode(Loc loc, Kind k, Ty ty): loc(loc), kind(k), ty(ty) {}
    AstNode(Loc loc): loc(loc), kind(Kind::Invalid) {}

    bool is(Kind k) const { return kind == k; }
    std::string sexp() { return  fmt::format("({})", dump()); }
    void print();
    virtual ~AstNode() { };

    static std::string tostr(AstNodePtr n);
    static json node_tojson(AstNodePtr n);
    static json vec_tojson(Args *args);

    Ty Type() const { return ty; }
    std::string tyname() { return ty.type_name(); }
    virtual std::string nominal() { return ""; }
    virtual std::string dump() { return "astnode"; };
    virtual json tojson(json parent=json()) { return parent; }

    friend class TypeChecker;

protected:
    Loc loc;
    // type annotation
    Ty ty;
    bool synthesized;
};

typedef AstNode::Kind NodeKind;
typedef AstNode::OpKind OpKind;

struct Decls: public AstNode {
    Decls(Loc loc): AstNode(loc, Kind::DeclList) {}
    virtual std::string dump();
    virtual json tojson(json parent);

    ~Decls() {
        Logging::debug("~Decls({})\n", dump());
    }
    void append(struct AstNode* n);
    NodeVec decls;
};

struct Val: public AstNode {
    std::string *raw_data;

    Val(Loc loc, NodeKind kind, std::string *val) : AstNode(loc, kind), raw_data(val) {}
    Val(Loc loc, NodeKind kind, Ty ty, std::string *val) : AstNode(loc, kind, ty), raw_data(val) {}

    ~Val() {
        Logging::debug("~Val({})\n", dump());
        if (raw_data) delete raw_data;
    }

    virtual std::string dump();
    virtual json tojson(json parent);
    virtual std::string nominal();
};

struct VarDecl: public AstNode {
    std::string *raw_data;
    std::string *var_name;
    std::string *type_name;

    VarDecl(Loc loc, std::string *name, std::string *type, std::string *data)
        : AstNode(loc, NodeKind::VarDecl, Ty(*type)),
        raw_data(data), var_name(name), type_name(type) { }

    std::string name() {
        return var_name ? *var_name: "Nil";
    }
    std::string type() {
        return type_name ? *type_name: "Nil";
    }

    ~VarDecl();
    virtual std::string dump();
    virtual json tojson(json parent);
};

struct Operator: public AstNode {
    AstNodePtr lhs;
    AstNodePtr rhs;
    Kind kind;
    OpKind op;

    Operator(Loc loc, Kind nodeKind, OpKind opKind, AstNode *l, AstNode *r) :
        lhs(l), rhs(r), op(opKind), AstNode(loc, nodeKind) {}

    Operator(Loc loc, Kind nodeKind, Ty ty, std::string *opname, AstNode *l, AstNode *r);

    virtual std::string dump();
    virtual json tojson(json parent);

    ~Operator() {
        Logging::debug("~Operator({})\n", dump());
    }
};

namespace detail {
    const static std::map<std::string, OpKind> OperatorMappings {
        {"+", OpKind::ADD},
        {"-", OpKind::SUB},
        {"*", OpKind::MUL},
        {"/", OpKind::DIV},
        {"<", OpKind::LT},
        {"<=", OpKind::LE},
        {"==", OpKind::EQ},
        {"!=", OpKind::NEQ},
        {">", OpKind::GT},
        {">=", OpKind::GE},
    };
};

struct FuncDecl: public AstNode {
    FuncDecl(Loc loc, std::string *name, std::string *type)
        : AstNode(loc, Kind::FuncDecl, Ty(*type)), name(name) { }

    virtual std::string nominal() {
        return name ? *name : "Nil";
    }

    virtual std::string dump();
    virtual json tojson(json parent);
    ~FuncDecl();

    NodeVec *args;
    Exprs *body;
    std::string *name;
};

struct Call: public AstNode {
    virtual std::string dump();
    virtual json tojson(json parent);

    Call(Loc loc) : AstNode(loc, Kind::CallFunc) {}
    ~Call();

    Args *args;
    std::string *name;
};

struct ReturnStmt: public AstNode {
    ReturnStmt(Loc loc): AstNode(loc, Kind::ReturnStmt) {}
    ReturnStmt(Loc loc, Ty ty)
        : AstNode(loc, Kind::ReturnStmt, ty) { }
    ~ReturnStmt();

    virtual std::string dump();
    virtual json tojson(json parent);

    AstNodePtr stmt;
};

struct ForStmt: public AstNode {
    AstNodePtr init_stmt;
    AstNodePtr cond_stmt;
    AstNodePtr next_stmt;
    Exprs *body;
    ForStmt(Loc loc) : AstNode(loc) {}

    virtual std::string dump();
    virtual json tojson(json parent);
    ~ForStmt();
};

struct IfStmt: public AstNode {
    AstNodePtr cond_;
    Exprs* then_;
    Exprs* else_;
    IfStmt(Loc loc, AstNode* conditional, Exprs* then, Exprs* _else):
        AstNode(loc), cond_(conditional), then_(then), else_(_else) {}
    ~IfStmt();

    virtual std::string dump();
    virtual json tojson(json parent);
};

struct AssignStmt: public AstNode {
    AstNodePtr var_;
    AstNodePtr val_;

    AssignStmt(Loc loc, AstNode* var, AstNode* val) : AstNode(loc), var_(var), val_(val) {}
    ~AssignStmt();

    virtual std::string dump();
    virtual json tojson(json parent);
};

}; // end namespace


#endif

