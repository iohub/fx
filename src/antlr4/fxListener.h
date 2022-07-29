
// Generated from fx.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "fxParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by fxParser.
 */
class  fxListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(fxParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(fxParser::ProgramContext *ctx) = 0;

  virtual void enterTopDef(fxParser::TopDefContext *ctx) = 0;
  virtual void exitTopDef(fxParser::TopDefContext *ctx) = 0;

  virtual void enterFuncDef(fxParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(fxParser::FuncDefContext *ctx) = 0;

  virtual void enterClassDef(fxParser::ClassDefContext *ctx) = 0;
  virtual void exitClassDef(fxParser::ClassDefContext *ctx) = 0;

  virtual void enterFieldDecl(fxParser::FieldDeclContext *ctx) = 0;
  virtual void exitFieldDecl(fxParser::FieldDeclContext *ctx) = 0;

  virtual void enterMethodDef(fxParser::MethodDefContext *ctx) = 0;
  virtual void exitMethodDef(fxParser::MethodDefContext *ctx) = 0;

  virtual void enterArg(fxParser::ArgContext *ctx) = 0;
  virtual void exitArg(fxParser::ArgContext *ctx) = 0;

  virtual void enterVarDef(fxParser::VarDefContext *ctx) = 0;
  virtual void exitVarDef(fxParser::VarDefContext *ctx) = 0;

  virtual void enterBlock(fxParser::BlockContext *ctx) = 0;
  virtual void exitBlock(fxParser::BlockContext *ctx) = 0;

  virtual void enterStmt(fxParser::StmtContext *ctx) = 0;
  virtual void exitStmt(fxParser::StmtContext *ctx) = 0;

  virtual void enterDecl(fxParser::DeclContext *ctx) = 0;
  virtual void exitDecl(fxParser::DeclContext *ctx) = 0;

  virtual void enterAss(fxParser::AssContext *ctx) = 0;
  virtual void exitAss(fxParser::AssContext *ctx) = 0;

  virtual void enterReturnStmt(fxParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(fxParser::ReturnStmtContext *ctx) = 0;

  virtual void enterIfStmt(fxParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(fxParser::IfStmtContext *ctx) = 0;

  virtual void enterInt(fxParser::IntContext *ctx) = 0;
  virtual void exitInt(fxParser::IntContext *ctx) = 0;

  virtual void enterStr(fxParser::StrContext *ctx) = 0;
  virtual void exitStr(fxParser::StrContext *ctx) = 0;

  virtual void enterBool(fxParser::BoolContext *ctx) = 0;
  virtual void exitBool(fxParser::BoolContext *ctx) = 0;

  virtual void enterVoid(fxParser::VoidContext *ctx) = 0;
  virtual void exitVoid(fxParser::VoidContext *ctx) = 0;

  virtual void enterClassName(fxParser::ClassNameContext *ctx) = 0;
  virtual void exitClassName(fxParser::ClassNameContext *ctx) = 0;

  virtual void enterItem(fxParser::ItemContext *ctx) = 0;
  virtual void exitItem(fxParser::ItemContext *ctx) = 0;

  virtual void enterAndExpr(fxParser::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(fxParser::AndExprContext *ctx) = 0;

  virtual void enterIDExpr(fxParser::IDExprContext *ctx) = 0;
  virtual void exitIDExpr(fxParser::IDExprContext *ctx) = 0;

  virtual void enterConstExpr(fxParser::ConstExprContext *ctx) = 0;
  virtual void exitConstExpr(fxParser::ConstExprContext *ctx) = 0;

  virtual void enterRelOpExpr(fxParser::RelOpExprContext *ctx) = 0;
  virtual void exitRelOpExpr(fxParser::RelOpExprContext *ctx) = 0;

  virtual void enterCallExpr(fxParser::CallExprContext *ctx) = 0;
  virtual void exitCallExpr(fxParser::CallExprContext *ctx) = 0;

  virtual void enterBinOpExpr(fxParser::BinOpExprContext *ctx) = 0;
  virtual void exitBinOpExpr(fxParser::BinOpExprContext *ctx) = 0;

  virtual void enterOrExpr(fxParser::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(fxParser::OrExprContext *ctx) = 0;

  virtual void enterParamList(fxParser::ParamListContext *ctx) = 0;
  virtual void exitParamList(fxParser::ParamListContext *ctx) = 0;

  virtual void enterBoolean(fxParser::BooleanContext *ctx) = 0;
  virtual void exitBoolean(fxParser::BooleanContext *ctx) = 0;

  virtual void enterConstBool(fxParser::ConstBoolContext *ctx) = 0;
  virtual void exitConstBool(fxParser::ConstBoolContext *ctx) = 0;

  virtual void enterConstInt(fxParser::ConstIntContext *ctx) = 0;
  virtual void exitConstInt(fxParser::ConstIntContext *ctx) = 0;

  virtual void enterConstStr(fxParser::ConstStrContext *ctx) = 0;
  virtual void exitConstStr(fxParser::ConstStrContext *ctx) = 0;

  virtual void enterBinOp(fxParser::BinOpContext *ctx) = 0;
  virtual void exitBinOp(fxParser::BinOpContext *ctx) = 0;

  virtual void enterRelOp(fxParser::RelOpContext *ctx) = 0;
  virtual void exitRelOp(fxParser::RelOpContext *ctx) = 0;


};

