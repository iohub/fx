
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
using Stmts = NodeVec;
using DeclList = NodeVec;
using json = nlohmann::json;

class AstNode {

public:
    enum class Kind : uint8_t {
        Invalid, Nil, CallFunc, Constant,
        FuncDecl, VarRef, VarDecl, Expr, BinaryOperator, UnaryOperator,
        ReturnStmt, If, Assign, DeclList, Undefine
    };
    enum class OpKind: uint8_t {
        Invalid,
        LT, LE, EQ, GT, GE, NEQ, // binaryop
        MUL, DIV, ADD, SUB // unaryop
    };
    Kind kind = Kind::Invalid;

    AstNode(Loc loc, Kind k): loc_(loc), kind(k) {}
    AstNode(Loc loc, Kind k, Ty ty): loc_(loc), kind(k), ty(ty) {}
    AstNode(Loc loc): loc_(loc), kind(Kind::Invalid) {}

    bool is(Kind k) const { return kind == k; }
    std::string sexp() { return  fmt::format("({})", dump()); }
    std::string loc() const;
    void print();
    virtual ~AstNode() { };

    static std::string tostr(AstNodePtr n);
    static json node_tojson(AstNodePtr n);
    static json vec_tojson(Args *args);

    Ty Type() const { return ty; }
    std::string TyStr() { return ty.str(); }
    virtual std::string nominal() { return ""; }
    virtual std::string dump() { return "astnode"; };
    virtual json tojson(json parent=json()) { return parent; }

    friend class TypeChecker;

protected:
    Loc loc_;
    // type annotation
    Ty ty;
    bool synthesized;
};

typedef AstNode::Kind Kind;
typedef AstNode::OpKind OpKind;

struct Decls: public AstNode {
    Decls(Loc loc): AstNode(loc, Kind::DeclList) {}
    virtual std::string dump();
    virtual json tojson(json parent);

    ~Decls() {
        Logging::debug("~Decls({})\n", dump());
    }
    void append(struct AstNode* n);
    DeclList decls;
};

struct Val: public AstNode {
    std::string *raw_data;

    Val(Loc loc, Kind kind, std::string *val) : AstNode(loc, kind), raw_data(val) {}
    Val(Loc loc, Kind kind, Ty ty, std::string *val) : AstNode(loc, kind, ty), raw_data(val) {}

    ~Val() {
        Logging::debug("~Val({})\n", dump());
        if (raw_data) delete raw_data;
    }

    virtual std::string dump();
    virtual json tojson(json parent);
    virtual std::string nominal() { return raw_data ? *raw_data : "Nil"; }
};

struct VarDecl: public AstNode {
    std::string *raw_data;
    std::string *var_name;
    std::string *type_name;

    VarDecl(Loc loc, std::string *name, std::string *type, std::string *data)
        : AstNode(loc, Kind::VarDecl, Ty(*type)),
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
    virtual std::string nominal() { return var_name? *var_name: "Nil"; }
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

    Stmts body() const { return body_ ? *body_ : Stmts(); }
    Args args() const { return args_ ? *args_ : Args(); }

    Args *args_;
    Stmts *body_;
    std::string *name;
};

struct Call: public AstNode {
    virtual std::string dump();
    virtual json tojson(json parent);
    virtual std::string nominal() { return name_ ? *name_ : "Nil"; }

    Call(Loc loc) : AstNode(loc, Kind::CallFunc) {}
    ~Call();

    Args args() {
        return args_ ? *args_ : Args();
    }

    Args *args_;
    std::string *name_;
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
    Stmts *body;
    ForStmt(Loc loc) : AstNode(loc) {}

    virtual std::string dump();
    virtual json tojson(json parent);
    ~ForStmt();
};

struct IfStmt: public AstNode {
    AstNodePtr cond_;
    Stmts* then_;
    Stmts* else_;
    IfStmt(Loc loc, AstNode* conditional, Stmts* then, Stmts* _else):
        AstNode(loc, Kind::If), cond_(conditional), then_(then), else_(_else) {}
    ~IfStmt();

    virtual std::string dump();
    virtual json tojson(json parent);
};

struct AssignStmt: public AstNode {
    AstNodePtr var_;
    AstNodePtr val_;

    AssignStmt(Loc loc, AstNode* var, AstNode* val) :
        AstNode(loc, Kind::Assign), var_(var), val_(val) {}
    ~AssignStmt();

    virtual std::string dump();
    virtual json tojson(json parent);
};

}; // end namespace


#endif

