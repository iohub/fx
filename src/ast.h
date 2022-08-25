
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


struct AstNode : std::enable_shared_from_this<AstNode> {
    enum class Kind : uint8_t {
        Invalid, Nil, Undefine,
        CallFunc, Constant, FuncDecl, VarRef, Value, VarDecl,
        Expr, BinaryOperator, BinaryCmp, UnaryOperator, ReturnStmt,
        If, Assign, LetAssign, For, DeclList, Matrix
    };
    enum class OpKind: uint8_t {
        Invalid,
        LT, LE, EQ, GT, GE, NEQ, // binaryop
        MUL, DIV, ADD, SUB // unaryop
    };

    AstNode(Loc loc, Kind k): loc_(loc), kind(k) {}
    AstNode(Loc loc, Kind k, Ty ty): loc_(loc), kind(k), ty(ty) {}
    AstNode(Loc loc): loc_(loc), kind(Kind::Invalid) {}

    bool is(Kind k) const { return kind == k; }
    std::string sexp() { return  _f("({})", dump()); }
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

    // member
    Kind kind = Kind::Invalid;
    Loc loc_;
    Ty ty;
    bool synthesized = false;
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
    std::string raw_data;

    Val(Loc loc, Kind kind, std::string val) : AstNode(loc, kind), raw_data(val) {}
    Val(Loc loc, Kind kind, Ty ty, std::string val) : AstNode(loc, kind, ty), raw_data(val) {}

    ~Val() { Logging::debug("~Val({})\n", dump()); }

    virtual std::string dump();
    virtual json tojson(json parent);
    virtual std::string nominal() { return raw_data; }
};

struct VarDecl: public AstNode {
    std::string var_name;

    VarDecl(Loc loc, std::string name, std::string type)
        : AstNode(loc, Kind::VarDecl, Ty(type)), var_name(name) { }

    std::string name() { return var_name; }

    ~VarDecl();
    virtual std::string dump();
    virtual json tojson(json parent);
    virtual std::string nominal() { return var_name; }
};

struct LetAssign: public AstNode {
    AstNodePtr var;
    AstNodePtr val;
    LetAssign(Loc loc, AstNodePtr var, AstNodePtr val) :
        AstNode(loc, Kind::LetAssign), var(var), val(val) {}
    ~LetAssign();

    virtual std::string dump();
    virtual json tojson(json parent);
};

struct BinaryExpr: public AstNode {
    AstNodePtr lhs;
    AstNodePtr rhs;
    Kind kind;
    OpKind op;

    BinaryExpr(Loc loc, Kind nodeKind, Ty ty, std::string opname, AstNode *l, AstNode *r);
    virtual std::string dump();
    virtual json tojson(json parent);

    ~BinaryExpr() {
        Logging::debug("~BinaryExpr({})\n", dump());
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
    enum class TargetTy : uint8_t {
        HOST, // cpu
        DEVICE // gput kernel
    };
    FuncDecl(Loc loc, std::string name, std::string type)
        : AstNode(loc, Kind::FuncDecl, Ty(type)), name(name) { }

    virtual std::string nominal() {
        return name;
    }

    virtual std::string dump();
    virtual json tojson(json parent);
    ~FuncDecl();

    Stmts body() const { return body_ ? *body_ : Stmts(); }
    Args args() const { return args_ ? *args_ : Args(); }

    Args *args_ = nullptr;
    Stmts *body_ = nullptr;
    std::string name;
    TargetTy tty = TargetTy::HOST;
};

struct Call: public AstNode {
    virtual std::string dump();
    virtual json tojson(json parent);
    virtual std::string nominal() { return name_; }

    Call(Loc loc) : AstNode(loc, Kind::CallFunc, TypeID::Nil) {}
    ~Call();

    Args args() {
        return args_ ? *args_ : Args();
    }

    Args *args_;
    std::string name_;
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
    AstNodePtr init_stmt; // maybe nullptr
    AstNodePtr cond_stmt; // maybe nullptr
    AstNodePtr next_stmt; // maybe nullptr
    Stmts *body;
    ForStmt(Loc loc) : AstNode(loc, Kind::For) {}
    ~ForStmt();

    virtual std::string dump();
    virtual json tojson(json parent);
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

struct Matrix: public AstNode {
    // x0, x1, x3 ;
    // r0, r1, r3 ;
    // x == 3, y == 2
    uint16_t xsize_ = 0;
    uint16_t ysize_ = 0;

    Matrix(Loc loc, std::string tname, uint16_t xsize, uint16_t ysize) :
        AstNode(loc, Kind::Matrix, Ty(tname)), xsize_(xsize), ysize_(ysize) {}
    ~Matrix() {}

    virtual std::string dump();
    virtual json tojson(json parent);
};

}; // end namespace


#endif

