
// Generated from fx.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "fxVisitor.h"


/**
 * This class provides an empty implementation of fxVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  fxBaseVisitor : public fxVisitor {
public:

  virtual antlrcpp::Any visitProgram(fxParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTopDef(fxParser::TopDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncDef(fxParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassDef(fxParser::ClassDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFieldDecl(fxParser::FieldDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodDef(fxParser::MethodDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArg(fxParser::ArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDef(fxParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(fxParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(fxParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl(fxParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAss(fxParser::AssContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStmt(fxParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStmt(fxParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt(fxParser::IntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStr(fxParser::StrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBool(fxParser::BoolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVoid(fxParser::VoidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassName(fxParser::ClassNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitItem(fxParser::ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAndExpr(fxParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIDExpr(fxParser::IDExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstExpr(fxParser::ConstExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelOpExpr(fxParser::RelOpExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallExpr(fxParser::CallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinOpExpr(fxParser::BinOpExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrExpr(fxParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParamList(fxParser::ParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean(fxParser::BooleanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstBool(fxParser::ConstBoolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstInt(fxParser::ConstIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstStr(fxParser::ConstStrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinOp(fxParser::BinOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelOp(fxParser::RelOpContext *ctx) override {
    return visitChildren(ctx);
  }


};

