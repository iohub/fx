
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

  virtual antlrcpp::Any visitEmpty(fxParser::EmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockStmt(fxParser::BlockStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl(fxParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAss(fxParser::AssContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIncr(fxParser::IncrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecr(fxParser::DecrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRet(fxParser::RetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVRet(fxParser::VRetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond(fxParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondElse(fxParser::CondElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile(fxParser::WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSExp(fxParser::SExpContext *ctx) override {
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

  virtual antlrcpp::Any visitEId(fxParser::EIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEFunCall(fxParser::EFunCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitERelOp(fxParser::ERelOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitETrue(fxParser::ETrueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEOr(fxParser::EOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEInt(fxParser::EIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEMemberExpr(fxParser::EMemberExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEUnOp(fxParser::EUnOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEStr(fxParser::EStrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitENewExpr(fxParser::ENewExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEMulOp(fxParser::EMulOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEAnd(fxParser::EAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEClassCast(fxParser::EClassCastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEParen(fxParser::EParenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEFalse(fxParser::EFalseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEAddOp(fxParser::EAddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitENull(fxParser::ENullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddOp(fxParser::AddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulOp(fxParser::MulOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelOp(fxParser::RelOpContext *ctx) override {
    return visitChildren(ctx);
  }


};

