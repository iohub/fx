
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

  virtual void enterEmpty(fxParser::EmptyContext *ctx) = 0;
  virtual void exitEmpty(fxParser::EmptyContext *ctx) = 0;

  virtual void enterBlockStmt(fxParser::BlockStmtContext *ctx) = 0;
  virtual void exitBlockStmt(fxParser::BlockStmtContext *ctx) = 0;

  virtual void enterDecl(fxParser::DeclContext *ctx) = 0;
  virtual void exitDecl(fxParser::DeclContext *ctx) = 0;

  virtual void enterAss(fxParser::AssContext *ctx) = 0;
  virtual void exitAss(fxParser::AssContext *ctx) = 0;

  virtual void enterIncr(fxParser::IncrContext *ctx) = 0;
  virtual void exitIncr(fxParser::IncrContext *ctx) = 0;

  virtual void enterDecr(fxParser::DecrContext *ctx) = 0;
  virtual void exitDecr(fxParser::DecrContext *ctx) = 0;

  virtual void enterRet(fxParser::RetContext *ctx) = 0;
  virtual void exitRet(fxParser::RetContext *ctx) = 0;

  virtual void enterVRet(fxParser::VRetContext *ctx) = 0;
  virtual void exitVRet(fxParser::VRetContext *ctx) = 0;

  virtual void enterCond(fxParser::CondContext *ctx) = 0;
  virtual void exitCond(fxParser::CondContext *ctx) = 0;

  virtual void enterCondElse(fxParser::CondElseContext *ctx) = 0;
  virtual void exitCondElse(fxParser::CondElseContext *ctx) = 0;

  virtual void enterWhile(fxParser::WhileContext *ctx) = 0;
  virtual void exitWhile(fxParser::WhileContext *ctx) = 0;

  virtual void enterSExp(fxParser::SExpContext *ctx) = 0;
  virtual void exitSExp(fxParser::SExpContext *ctx) = 0;

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

  virtual void enterEId(fxParser::EIdContext *ctx) = 0;
  virtual void exitEId(fxParser::EIdContext *ctx) = 0;

  virtual void enterEFunCall(fxParser::EFunCallContext *ctx) = 0;
  virtual void exitEFunCall(fxParser::EFunCallContext *ctx) = 0;

  virtual void enterERelOp(fxParser::ERelOpContext *ctx) = 0;
  virtual void exitERelOp(fxParser::ERelOpContext *ctx) = 0;

  virtual void enterETrue(fxParser::ETrueContext *ctx) = 0;
  virtual void exitETrue(fxParser::ETrueContext *ctx) = 0;

  virtual void enterEOr(fxParser::EOrContext *ctx) = 0;
  virtual void exitEOr(fxParser::EOrContext *ctx) = 0;

  virtual void enterEInt(fxParser::EIntContext *ctx) = 0;
  virtual void exitEInt(fxParser::EIntContext *ctx) = 0;

  virtual void enterEMemberExpr(fxParser::EMemberExprContext *ctx) = 0;
  virtual void exitEMemberExpr(fxParser::EMemberExprContext *ctx) = 0;

  virtual void enterEUnOp(fxParser::EUnOpContext *ctx) = 0;
  virtual void exitEUnOp(fxParser::EUnOpContext *ctx) = 0;

  virtual void enterEStr(fxParser::EStrContext *ctx) = 0;
  virtual void exitEStr(fxParser::EStrContext *ctx) = 0;

  virtual void enterENewExpr(fxParser::ENewExprContext *ctx) = 0;
  virtual void exitENewExpr(fxParser::ENewExprContext *ctx) = 0;

  virtual void enterEMulOp(fxParser::EMulOpContext *ctx) = 0;
  virtual void exitEMulOp(fxParser::EMulOpContext *ctx) = 0;

  virtual void enterEAnd(fxParser::EAndContext *ctx) = 0;
  virtual void exitEAnd(fxParser::EAndContext *ctx) = 0;

  virtual void enterEClassCast(fxParser::EClassCastContext *ctx) = 0;
  virtual void exitEClassCast(fxParser::EClassCastContext *ctx) = 0;

  virtual void enterEParen(fxParser::EParenContext *ctx) = 0;
  virtual void exitEParen(fxParser::EParenContext *ctx) = 0;

  virtual void enterEFalse(fxParser::EFalseContext *ctx) = 0;
  virtual void exitEFalse(fxParser::EFalseContext *ctx) = 0;

  virtual void enterEAddOp(fxParser::EAddOpContext *ctx) = 0;
  virtual void exitEAddOp(fxParser::EAddOpContext *ctx) = 0;

  virtual void enterENull(fxParser::ENullContext *ctx) = 0;
  virtual void exitENull(fxParser::ENullContext *ctx) = 0;

  virtual void enterAddOp(fxParser::AddOpContext *ctx) = 0;
  virtual void exitAddOp(fxParser::AddOpContext *ctx) = 0;

  virtual void enterMulOp(fxParser::MulOpContext *ctx) = 0;
  virtual void exitMulOp(fxParser::MulOpContext *ctx) = 0;

  virtual void enterRelOp(fxParser::RelOpContext *ctx) = 0;
  virtual void exitRelOp(fxParser::RelOpContext *ctx) = 0;


};

