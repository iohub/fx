#include <stdio.h>
#include <fstream>
#include <iostream>
#include <memory>

#include <fmt/core.h>
#include <CLI/CLI.hpp>
#include <nlohmann/json.hpp>

#include "exception.h"
#include "util.h"
#include "astnode.h"
#include "parser.hh"
#include "typecheck.h"
#include "codegen.h"

#include "antlr4-runtime.h"
#include "fxLexer.h"
#include "fxParser.h"
#include "fxVisitor.h"

using namespace fx;
using json = nlohmann::json;

Logging::Level Logging::level;


class  AstVisitor : public fxVisitor {
public:
    AstVisitor() { ast = new Decls(Loc()); }

    virtual antlrcpp::Any visitProgram(fxParser::ProgramContext *ctx) {
        for (auto *child : ctx->children) {
            AstNode* n = visit(child);
            if (n) ast->append(n);
        }
        return (AstNode*)&ast;
    }

    virtual antlrcpp::Any visitFuncDef(fxParser::FuncDefContext *ctx) {
        Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
        std::string ident = ctx->ID()->toString();
        std::string tyname = ctx->type_()->toString();
        FuncDecl *fn = new FuncDecl(loc, ident, tyname);
        // has args
        if (ctx->children.size() == 6) {
            fn->args_ = visit(ctx->children.at(3));
        }
        fn->body_ = visit(ctx->children.back());
        return (AstNode*) fn;
    }

    virtual antlrcpp::Any visitTopDef(fxParser::TopDefContext *ctx) {
        for (auto *child : ctx->children) {
            AstNode* n = visit(child);
            if (n) ast->append(n);
        }
        return (AstNode*) nullptr;
    }

    virtual antlrcpp::Any visitClassDef(fxParser::ClassDefContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitFieldDecl(fxParser::FieldDeclContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitMethodDef(fxParser::MethodDefContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitArg(fxParser::ArgContext *ctx) {
        Args *args = new Args();
        for (auto *child : ctx->children) {
            if (child->getText() != ",") {
                AstNode *n = visit(child);
                args->push_back(AstNodePtr(n));
            }
        }
        return args;
    }

    virtual antlrcpp::Any visitVarDef(fxParser::VarDefContext *ctx) {
        std::string tyname = ctx->type_()->getText();
        std::string ident = ctx->ID()->toString();
        Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
        VarDecl *n = new VarDecl(loc, ident, tyname);
        return (AstNode *)n;
    }

    virtual antlrcpp::Any visitBlock(fxParser::BlockContext *ctx) {
        Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
        Stmts *retval = new Stmts();
        for (auto *e : ctx->stmt()) {
            AstNode *ev = visit(e);
            if (ev) retval->push_back(AstNodePtr(ev));
        }
        return retval;
    }

    virtual antlrcpp::Any visitDecl(fxParser::DeclContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitAss(fxParser::AssContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitStmt(fxParser::StmtContext *ctx) {
        Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
        for (auto *e : ctx->children) {
            AstNode *ev = visit(e);
            if (ev != nullptr) return ev;
        }
        return (AstNode*) nullptr;
    }

    virtual antlrcpp::Any visitInt(fxParser::IntContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitStr(fxParser::StrContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitBool(fxParser::BoolContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitVoid(fxParser::VoidContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitClassName(fxParser::ClassNameContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitItem(fxParser::ItemContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitRelOp(fxParser::RelOpContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitBinOp(fxParser::BinOpContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitAndExpr(fxParser::AndExprContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitIDExpr(fxParser::IDExprContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitConstExpr(fxParser::ConstExprContext *ctx) {
        return visit(ctx->constant());
    }

    virtual antlrcpp::Any visitParamList(fxParser::ParamListContext *ctx) {
        Args *args = new Args();
        for (auto *e: ctx->expr()) visit(e);
        return args;
    }

    virtual antlrcpp::Any visitCallExpr(fxParser::CallExprContext *ctx) {
        Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
        Call *caller = new Call(loc);
        caller->name_ = ctx->ID()->getText();
        caller->args_ = visit(ctx->paramList());
        return (AstNode*) caller;
    }

    virtual antlrcpp::Any visitRelOpExpr(fxParser::RelOpExprContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitBinOpExpr(fxParser::BinOpExprContext *ctx) {
        Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
        AstNode* lhs = visit(ctx->expr().at(0));
        AstNode* rhs = visit(ctx->expr().at(1));
        BinaryExpr *binExpr = new BinaryExpr(loc, Kind::BinaryOperator,
                TypeID::Nil, ctx->binOp()->getText(), lhs, rhs);
        return (AstNode *)binExpr;
    }

    virtual antlrcpp::Any visitOrExpr(fxParser::OrExprContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitConstant(fxParser::ConstantContext *ctx) {
        for (auto *e : ctx->children) {
            AstNode *ev = visit(e);
            if (ev) return ev;
        }
        return (AstNode*) nullptr;
    }

    virtual antlrcpp::Any visitConstBool(fxParser::ConstBoolContext *ctx) {
        Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
        return (AstNode*) new Val(loc, Kind::Constant, TypeID::Bool, ctx->getText());
    }

    virtual antlrcpp::Any visitConstInt(fxParser::ConstIntContext *ctx) {
        Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
        return (AstNode*) new Val(loc, Kind::Constant, TypeID::Int, ctx->getText());
    }

     virtual antlrcpp::Any visitConstStr(fxParser::ConstStrContext *ctx) {
        Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
        return (AstNode*) new Val(loc, Kind::Constant, TypeID::Str, ctx->getText());
     }

    virtual antlrcpp::Any visitBoolean(fxParser::BooleanContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitIfStmt(fxParser::IfStmtContext *ctx) {
        Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
        Stmts *then = nullptr, *_else = nullptr;
        if (!ctx->block().empty()) then = visit(ctx->block().at(0));
        if (ctx->block().size() > 1) _else = visit(ctx->block().at(1));
        IfStmt *retval = new IfStmt(loc, nullptr, then, _else);
        return (AstNode*) retval;
    }

    virtual antlrcpp::Any visitReturnStmt(fxParser::ReturnStmtContext *ctx) {
        Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
        if (ctx->expr()->isEmpty()) {
            return (AstNode *) new ReturnStmt(loc);
        }
        AstNode * val = visit(ctx->expr());
        ReturnStmt *retval = new ReturnStmt(loc, val->Type());
        retval->stmt = AstNodePtr(val);
        return (AstNode*) retval;
    }

public:
    Decls *ast;
};

Decls* parse(const std::string &fname){
    std::ifstream ifs;
    ifs.open(fname);
    antlr4::ANTLRInputStream input(ifs);
    fxLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    fxParser parser(&tokens);
    antlr4::tree::ParseTree *top = parser.program();
    AstVisitor visitor;
    visitor.visit(top);
    ifs.close();
    return visitor.ast;
}

void compile(const std::string &fname) {
    AstNodePtr wrap(parse(fname));
    TypeChecker checker;
    fmt::print("ast:\n{}\n", wrap->dump());
    wrap->print() ;
    return ;

    TypeCheckResult result = checker.check(wrap);
    json jsonExp = wrap->tojson();
    // Logging::info("typed ast (json format):\n{}\n", jsonExp.dump());
    // wrap->print();
    // Logging::info("TypeCheckResult {}\n", result.errmsg);
    CodeGen gen(fname);
    try {
        gen.emit(wrap);
        // Logging::info("llvm ir:{}\n", gen.llvm_ir());
        gen.dump(fname + ".ll");
    } catch (CodeGenException *ex) {
        Logging::error("catch codegen exception {}", ex->what());
    }
}

int main(int argc, const char *argv[]) {
    Logging::level = Logging::Level::INFO;

    CLI::App app{"fx compiler"};
    std::string fname;
    app.add_option("-f,--file", fname, "source file");
    CLI11_PARSE(app, argc, argv);
    parse(fname);

    // print pretty json
    // std::cout << std::setw(2) << jsonExp << std::endl;
    // visualize onsite: https://vanya.jp.net/vtree
    try {
        compile(fname);
    } catch (ParseException *ex) {
        Logging::error("catch parse exception {}", ex->what());
    }

    return 0;
}

