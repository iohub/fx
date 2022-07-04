
#include "astnode.h"

namespace fx {

void AstNode::print() {
    std::string tab = "";
    std::string ctree = sexp();
    std::string out = "";
    for (char c: ctree) {
        if (c == '(') {
            tab.push_back('\t');
            out += "\n" + tab;
        } else if (c == ')') {
            tab.pop_back();
        } else {
            out.push_back(c);
        }
    }
    fmt::print("{}\n", out.c_str());
}

json Decls::tojson(json parent) {
    for (auto n : decls)
        parent.push_back(n->tojson(json()));
    return parent;
}

void Decls::append(AstNode *n) {
    if (n) decls.push_back(AstNodePtr(n));
}


std::string Val::dump() {
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

json Val::tojson(json parent) {
    std::string str;
    switch (kind) {
        case NodeKind::Constant: str = "Constant"; break;
        case NodeKind::VarRef: str = "VarRef"; break;
        case NodeKind::VarDecl: str = "VarDecl"; break;
        default: str = "unknown";
    }
    json child;
    child["data"] = raw_data != nullptr ? *raw_data : "Nil";
    child["type"] = Type().type_name();
    parent[str] = child;
    return parent;
}

VarDecl::~VarDecl() {
    Logging::debug("~VarDecl({})\n", dump());
    if (raw_data != nullptr) delete raw_data;
    if (var_name != nullptr) delete var_name;
    if (type_name != nullptr) delete type_name;
}

std::string VarDecl::dump() {
    return fmt::format("VarDecl@{}@{}", *var_name, Type().type_name());
}

json VarDecl::tojson(json parent) {
    json child;
    child["varname"] = var_name != nullptr ? *var_name : "Nil";
    child["type"] = Type().type_name();
    parent["VarDecl"] = child;
    return parent;
}

std::string Operator::dump() {
    return fmt::format("binaryop[{}{}]", tostr(lhs), tostr(rhs));
}

json Operator::tojson(json parent) {
    json child;
    child["lhs"] = node_tojson(lhs);
    child["rhs"] = node_tojson(rhs);
    child["node_kind"] = kind;
    child["op_kind"] = op;
    parent["Operator"] = child;
    return parent;
}

std::string FuncDecl::dump() {
    std::string str = (name != nullptr) ? "FuncDecl@" + *name : "FuncDecl";
    if (args != nullptr) {
        for (auto itr: *args) str += itr->sexp();
    }
    if (body != nullptr) {
        for (auto itr: *body) str +=  itr->sexp();
    }
    return fmt::format("({})", str);
}

json FuncDecl::tojson(json parent) {
    json child;
    child["name"] = name != nullptr ? *name : "Nil";
    child["args"] = vec_tojson(args);
    child["body"] = vec_tojson(body);
    parent["FuncDecl"] = child;
    return parent;
}

FuncDecl::~FuncDecl() {
    Logging::debug("~FuncDecl({})\n", dump());
    if (args != nullptr) delete args;
    if (body != nullptr) delete body;
    if (name != nullptr) delete name;
}

std::string Call::dump() {
    std::string str = (name != nullptr) ? "call:" + *name : "call";
    if (args != nullptr) {
        for (auto itr: *args) str += itr->sexp();
    }
    return str;
}

json Call::tojson(json parent) {
    json child;
    child["args"] = vec_tojson(args);
    parent["Call"] = child;
    return parent;
}

bool Call::synthesize(const Env &env) {
    Ty ty = env.lookup(*name);
    if (!ty.is(TypeID::Nil)) {
        this->ty = ty;
    }
    return !ty.is(TypeID::Nil);
};

Call::~Call() {
    Logging::debug("~callNode({})\n", dump());
    if (args != nullptr) delete args;
    if (name != nullptr) delete name;
}

std::string Decls::dump() {
    std::string str;
    for (auto n : decls) str += n->sexp();
    return str;
}

std::string ReturnStmt::dump() {
    if (stmt) {
        return fmt::format("ReturnStmt:{}", stmt->sexp());
    }
    return "ReturnStmt";
}

json ReturnStmt::tojson(json parent) {
    json child;
    child["value"] = stmt ? stmt->tojson() : json();
    parent["ReturnStmt"] = child;
    return parent;
}

bool ReturnStmt::synthesize(const Env &env) {
    if (synthesized()) return true;
    if (!stmt->synthesized()) {
       stmt->synthesize(env);
       ty = stmt->Type();
    }
    m_synthesized = true;
    return true;
}

ReturnStmt::~ReturnStmt() {
    Logging::debug("~ReturnStmt({})\n", dump());
}

std::string ForStmt::dump() {
    std::string str;
    if (body != nullptr) {
        for (auto n: *body) str += n->sexp();
    }
    return fmt::format("ForStmt<{}{}{}>[{}]",
            tostr(init_stmt), tostr(cond_stmt), tostr(next_stmt), str);
}

json ForStmt::tojson(json parent) {
    json child;
    child["body"] = vec_tojson(body);
    child["init"] = node_tojson(init_stmt);
    child["conditional"] = node_tojson(cond_stmt);
    child["next_stmt"] = node_tojson(next_stmt);
    parent["ForStmt"] = child;
    return parent;
}

ForStmt::~ForStmt() {
    Logging::debug("~ForStmt({})\n", dump());
    if (body != nullptr) delete body;
}

std::string IfStmt::dump() {
    std::string then_str, else_str;
    if (then_ != nullptr) for (auto n: *then_) then_str += n->sexp();
    if (else_ != nullptr) for (auto n: *else_) else_str += n->sexp();

    return fmt::format("IfStmt<{}>,then[{}],else[{}]",
            tostr(cond_), then_str, else_str);
}

json IfStmt::tojson(json parent) {
    json child;
    child["conditional"] = node_tojson(cond_);
    child["then"] = vec_tojson(then_);
    child["else"] = vec_tojson(else_);
    parent["IfStmt"] = child;
    return parent;
}

IfStmt::~IfStmt() {
    Logging::debug("~IfStmt({})\n", dump());
    if (then_ != nullptr) delete then_;
    if (else_ != nullptr) delete else_;
}

std::string AstNode::tostr(AstNodePtr n) {
    return n && n->kind != Kind::Nil ? n->sexp() : "(Nil)";
}

json AstNode::node_tojson(AstNodePtr n) {
    return n && n->kind != Kind::Nil ? n->tojson(json()) : "(Nil)";
}

json AstNode::vec_tojson(Args *args) {
    json argList;
    if (args) for (auto n: *args) argList.push_back(n->tojson());
    return argList;
}

AssignStmt::~AssignStmt() {
    Logging::debug("~IfStmt({})\n", dump());
}

std::string AssignStmt::dump() {
    return fmt::format("AssignStmt<{},{}>", tostr(var_), tostr(val_));
}

json AssignStmt::tojson(json parent) {
    json child;
    child["var"] = node_tojson(val_);
    child["val"] = node_tojson(val_);
    parent["AssignStmt"] = child;
    return parent;
}



}

