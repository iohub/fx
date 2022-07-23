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

extern FILE *yyin;
extern AstNode* Program;
Logging::Level Logging::level;


void compile(const std::string &fname) {
    FILE *fobj = fopen(fname.c_str(), "r");
    if (!fobj) {
        throw new ParseException(_f("open {} err", fname));
    }
    yyin = fobj;
    do { yyparse(); } while (!feof(yyin));
    if (!Program) {
        throw new ParseException(_f("parse {} err", fname));
    }
    AstNodePtr wrap(Program);
    TypeChecker checker;

    TypeCheckResult result = checker.check(wrap);
    json jsonExp = Program->tojson();
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

class  AstVisitor : public fxVisitor {
public:
    AstVisitor() : ast(Loc()) {}

    virtual antlrcpp::Any visitProgram(fxParser::ProgramContext *ctx) {
        for (auto *child : ctx->children) {
            AstNode* n = visit(child);
            if (n) ast.append(n);
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
        return (AstNode*) fn;
    }

    virtual antlrcpp::Any visitTopDef(fxParser::TopDefContext *ctx) {
        for (auto *child : ctx->children) {
            AstNode* n = visit(child);
            if (n) ast.append(n);
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

    virtual antlrcpp::Any visitBlock(fxParser::BlockContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEmpty(fxParser::EmptyContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitBlockStmt(fxParser::BlockStmtContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitDecl(fxParser::DeclContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitAss(fxParser::AssContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitIncr(fxParser::IncrContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitDecr(fxParser::DecrContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitRet(fxParser::RetContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitVRet(fxParser::VRetContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitCond(fxParser::CondContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitCondElse(fxParser::CondElseContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitWhile(fxParser::WhileContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitSExp(fxParser::SExpContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitInt(fxParser::IntContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitStr(fxParser::StrContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitBool(fxParser::BoolContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitVoid(fxParser::VoidContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitClassName(fxParser::ClassNameContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitItem(fxParser::ItemContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEId(fxParser::EIdContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEFunCall(fxParser::EFunCallContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitERelOp(fxParser::ERelOpContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitETrue(fxParser::ETrueContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEOr(fxParser::EOrContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEInt(fxParser::EIntContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEMemberExpr(fxParser::EMemberExprContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEUnOp(fxParser::EUnOpContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEStr(fxParser::EStrContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitENewExpr(fxParser::ENewExprContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEMulOp(fxParser::EMulOpContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEAnd(fxParser::EAndContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEClassCast(fxParser::EClassCastContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEParen(fxParser::EParenContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEFalse(fxParser::EFalseContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitEAddOp(fxParser::EAddOpContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitENull(fxParser::ENullContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitAddOp(fxParser::AddOpContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitMulOp(fxParser::MulOpContext *ctx) { return nullptr; }

    virtual antlrcpp::Any visitRelOp(fxParser::RelOpContext *ctx) { return nullptr; }

public:
    Decls ast;
};

int parse(const std::string &fname){
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

    fmt::print("{}\n{}\n", top->toStringTree(), visitor.ast.dump());

    return 0;
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

