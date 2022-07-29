#include "fxParserImpl.h"
#include "astnode.h"
#include "antlr4-runtime.h"
#include "fxLexer.h"
#include "fxParser.h"

using namespace fx;

antlrcpp::Any AstVisitor::visitProgram(fxParser::ProgramContext *ctx) {
    for (auto *child : ctx->children) {
        AstNode* n = visit(child);
        if (n) ast->append(n);
    }
    return (AstNode*)&ast;
}

antlrcpp::Any AstVisitor::visitFuncDef(fxParser::FuncDefContext *ctx) {
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

antlrcpp::Any AstVisitor::visitTopDef(fxParser::TopDefContext *ctx) {
    for (auto *child : ctx->children) {
        AstNode* n = visit(child);
        if (n) ast->append(n);
    }
    return (AstNode*) nullptr;
}

antlrcpp::Any AstVisitor::visitClassDef(fxParser::ClassDefContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitFieldDecl(fxParser::FieldDeclContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitMethodDef(fxParser::MethodDefContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitArg(fxParser::ArgContext *ctx) {
    Args *args = new Args();
    for (auto *child : ctx->children) {
        if (child->getText() != ",") {
            AstNode *n = visit(child);
            args->push_back(AstNodePtr(n));
        }
    }
    return args;
}

antlrcpp::Any AstVisitor::visitVarDef(fxParser::VarDefContext *ctx) {
    std::string tyname = ctx->type_()->getText();
    std::string ident = ctx->ID()->toString();
    Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    VarDecl *n = new VarDecl(loc, ident, tyname);
    return (AstNode *)n;
}

antlrcpp::Any AstVisitor::visitBlock(fxParser::BlockContext *ctx) {
    Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    Stmts *retval = new Stmts();
    for (auto *e : ctx->stmt()) {
        AstNode *ev = visit(e);
        if (ev) retval->push_back(AstNodePtr(ev));
    }
    return retval;
}

antlrcpp::Any AstVisitor::visitDecl(fxParser::DeclContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitAss(fxParser::AssContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitStmt(fxParser::StmtContext *ctx) {
    Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    for (auto *e : ctx->children) {
        AstNode *ev = visit(e);
        if (ev != nullptr) return ev;
    }
    return (AstNode*) nullptr;
}

antlrcpp::Any AstVisitor::visitInt(fxParser::IntContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitStr(fxParser::StrContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitBool(fxParser::BoolContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitVoid(fxParser::VoidContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitClassName(fxParser::ClassNameContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitItem(fxParser::ItemContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitRelOp(fxParser::RelOpContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitBinOp(fxParser::BinOpContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitAndExpr(fxParser::AndExprContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitIDExpr(fxParser::IDExprContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitConstExpr(fxParser::ConstExprContext *ctx) {
    return visit(ctx->constant());
}

antlrcpp::Any AstVisitor::visitParamList(fxParser::ParamListContext *ctx) {
    Args *args = new Args();
    for (auto *e: ctx->expr()) visit(e);
    return args;
}

antlrcpp::Any AstVisitor::visitCallExpr(fxParser::CallExprContext *ctx) {
    Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    Call *caller = new Call(loc);
    caller->name_ = ctx->ID()->getText();
    caller->args_ = visit(ctx->paramList());
    return (AstNode*) caller;
}

antlrcpp::Any AstVisitor::visitRelOpExpr(fxParser::RelOpExprContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitBinOpExpr(fxParser::BinOpExprContext *ctx) {
    Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    AstNode* lhs = visit(ctx->expr().at(0));
    AstNode* rhs = visit(ctx->expr().at(1));
    BinaryExpr *binExpr = new BinaryExpr(loc, Kind::BinaryOperator,
            TypeID::Nil, ctx->binOp()->getText(), lhs, rhs);
    return (AstNode *)binExpr;
}

antlrcpp::Any AstVisitor::visitOrExpr(fxParser::OrExprContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitConstant(fxParser::ConstantContext *ctx) {
    for (auto *e : ctx->children) {
        AstNode *ev = visit(e);
        if (ev) return ev;
    }
    return (AstNode*) nullptr;
}

antlrcpp::Any AstVisitor::visitConstBool(fxParser::ConstBoolContext *ctx) {
    Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    return (AstNode*) new Val(loc, Kind::Constant, TypeID::Bool, ctx->getText());
}

antlrcpp::Any AstVisitor::visitConstInt(fxParser::ConstIntContext *ctx) {
    Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    return (AstNode*) new Val(loc, Kind::Constant, TypeID::Int, ctx->getText());
}

antlrcpp::Any AstVisitor::visitConstStr(fxParser::ConstStrContext *ctx) {
    Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    return (AstNode*) new Val(loc, Kind::Constant, TypeID::Str, ctx->getText());
}

antlrcpp::Any AstVisitor::visitBoolean(fxParser::BooleanContext *ctx) { return nullptr; }

antlrcpp::Any AstVisitor::visitIfStmt(fxParser::IfStmtContext *ctx) {
    Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    Stmts *then = nullptr, *_else = nullptr;
    if (!ctx->block().empty()) then = visit(ctx->block().at(0));
    if (ctx->block().size() > 1) _else = visit(ctx->block().at(1));
    IfStmt *retval = new IfStmt(loc, nullptr, then, _else);
    return (AstNode*) retval;
}

antlrcpp::Any AstVisitor::visitReturnStmt(fxParser::ReturnStmtContext *ctx) {
    Loc loc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    if (ctx->expr()->isEmpty()) {
        return (AstNode *) new ReturnStmt(loc);
    }
    AstNode * val = visit(ctx->expr());
    ReturnStmt *retval = new ReturnStmt(loc, val->Type());
    retval->stmt = AstNodePtr(val);
    return (AstNode*) retval;
}






