
// Generated from fx.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "fxListener.h"


/**
 * This class provides an empty implementation of fxListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  fxBaseListener : public fxListener {
public:

  virtual void enterProgram(fxParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(fxParser::ProgramContext * /*ctx*/) override { }

  virtual void enterTopDef(fxParser::TopDefContext * /*ctx*/) override { }
  virtual void exitTopDef(fxParser::TopDefContext * /*ctx*/) override { }

  virtual void enterFuncDef(fxParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(fxParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterClassDef(fxParser::ClassDefContext * /*ctx*/) override { }
  virtual void exitClassDef(fxParser::ClassDefContext * /*ctx*/) override { }

  virtual void enterFieldDecl(fxParser::FieldDeclContext * /*ctx*/) override { }
  virtual void exitFieldDecl(fxParser::FieldDeclContext * /*ctx*/) override { }

  virtual void enterMethodDef(fxParser::MethodDefContext * /*ctx*/) override { }
  virtual void exitMethodDef(fxParser::MethodDefContext * /*ctx*/) override { }

  virtual void enterArg(fxParser::ArgContext * /*ctx*/) override { }
  virtual void exitArg(fxParser::ArgContext * /*ctx*/) override { }

  virtual void enterVarDef(fxParser::VarDefContext * /*ctx*/) override { }
  virtual void exitVarDef(fxParser::VarDefContext * /*ctx*/) override { }

  virtual void enterBlock(fxParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(fxParser::BlockContext * /*ctx*/) override { }

  virtual void enterEmpty(fxParser::EmptyContext * /*ctx*/) override { }
  virtual void exitEmpty(fxParser::EmptyContext * /*ctx*/) override { }

  virtual void enterBlockStmt(fxParser::BlockStmtContext * /*ctx*/) override { }
  virtual void exitBlockStmt(fxParser::BlockStmtContext * /*ctx*/) override { }

  virtual void enterDecl(fxParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(fxParser::DeclContext * /*ctx*/) override { }

  virtual void enterAss(fxParser::AssContext * /*ctx*/) override { }
  virtual void exitAss(fxParser::AssContext * /*ctx*/) override { }

  virtual void enterIncr(fxParser::IncrContext * /*ctx*/) override { }
  virtual void exitIncr(fxParser::IncrContext * /*ctx*/) override { }

  virtual void enterDecr(fxParser::DecrContext * /*ctx*/) override { }
  virtual void exitDecr(fxParser::DecrContext * /*ctx*/) override { }

  virtual void enterRet(fxParser::RetContext * /*ctx*/) override { }
  virtual void exitRet(fxParser::RetContext * /*ctx*/) override { }

  virtual void enterVRet(fxParser::VRetContext * /*ctx*/) override { }
  virtual void exitVRet(fxParser::VRetContext * /*ctx*/) override { }

  virtual void enterCond(fxParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(fxParser::CondContext * /*ctx*/) override { }

  virtual void enterCondElse(fxParser::CondElseContext * /*ctx*/) override { }
  virtual void exitCondElse(fxParser::CondElseContext * /*ctx*/) override { }

  virtual void enterWhile(fxParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(fxParser::WhileContext * /*ctx*/) override { }

  virtual void enterSExp(fxParser::SExpContext * /*ctx*/) override { }
  virtual void exitSExp(fxParser::SExpContext * /*ctx*/) override { }

  virtual void enterInt(fxParser::IntContext * /*ctx*/) override { }
  virtual void exitInt(fxParser::IntContext * /*ctx*/) override { }

  virtual void enterStr(fxParser::StrContext * /*ctx*/) override { }
  virtual void exitStr(fxParser::StrContext * /*ctx*/) override { }

  virtual void enterBool(fxParser::BoolContext * /*ctx*/) override { }
  virtual void exitBool(fxParser::BoolContext * /*ctx*/) override { }

  virtual void enterVoid(fxParser::VoidContext * /*ctx*/) override { }
  virtual void exitVoid(fxParser::VoidContext * /*ctx*/) override { }

  virtual void enterClassName(fxParser::ClassNameContext * /*ctx*/) override { }
  virtual void exitClassName(fxParser::ClassNameContext * /*ctx*/) override { }

  virtual void enterItem(fxParser::ItemContext * /*ctx*/) override { }
  virtual void exitItem(fxParser::ItemContext * /*ctx*/) override { }

  virtual void enterEId(fxParser::EIdContext * /*ctx*/) override { }
  virtual void exitEId(fxParser::EIdContext * /*ctx*/) override { }

  virtual void enterEFunCall(fxParser::EFunCallContext * /*ctx*/) override { }
  virtual void exitEFunCall(fxParser::EFunCallContext * /*ctx*/) override { }

  virtual void enterERelOp(fxParser::ERelOpContext * /*ctx*/) override { }
  virtual void exitERelOp(fxParser::ERelOpContext * /*ctx*/) override { }

  virtual void enterETrue(fxParser::ETrueContext * /*ctx*/) override { }
  virtual void exitETrue(fxParser::ETrueContext * /*ctx*/) override { }

  virtual void enterEOr(fxParser::EOrContext * /*ctx*/) override { }
  virtual void exitEOr(fxParser::EOrContext * /*ctx*/) override { }

  virtual void enterEInt(fxParser::EIntContext * /*ctx*/) override { }
  virtual void exitEInt(fxParser::EIntContext * /*ctx*/) override { }

  virtual void enterEMemberExpr(fxParser::EMemberExprContext * /*ctx*/) override { }
  virtual void exitEMemberExpr(fxParser::EMemberExprContext * /*ctx*/) override { }

  virtual void enterEUnOp(fxParser::EUnOpContext * /*ctx*/) override { }
  virtual void exitEUnOp(fxParser::EUnOpContext * /*ctx*/) override { }

  virtual void enterEStr(fxParser::EStrContext * /*ctx*/) override { }
  virtual void exitEStr(fxParser::EStrContext * /*ctx*/) override { }

  virtual void enterENewExpr(fxParser::ENewExprContext * /*ctx*/) override { }
  virtual void exitENewExpr(fxParser::ENewExprContext * /*ctx*/) override { }

  virtual void enterEMulOp(fxParser::EMulOpContext * /*ctx*/) override { }
  virtual void exitEMulOp(fxParser::EMulOpContext * /*ctx*/) override { }

  virtual void enterEAnd(fxParser::EAndContext * /*ctx*/) override { }
  virtual void exitEAnd(fxParser::EAndContext * /*ctx*/) override { }

  virtual void enterEClassCast(fxParser::EClassCastContext * /*ctx*/) override { }
  virtual void exitEClassCast(fxParser::EClassCastContext * /*ctx*/) override { }

  virtual void enterEParen(fxParser::EParenContext * /*ctx*/) override { }
  virtual void exitEParen(fxParser::EParenContext * /*ctx*/) override { }

  virtual void enterEFalse(fxParser::EFalseContext * /*ctx*/) override { }
  virtual void exitEFalse(fxParser::EFalseContext * /*ctx*/) override { }

  virtual void enterEAddOp(fxParser::EAddOpContext * /*ctx*/) override { }
  virtual void exitEAddOp(fxParser::EAddOpContext * /*ctx*/) override { }

  virtual void enterENull(fxParser::ENullContext * /*ctx*/) override { }
  virtual void exitENull(fxParser::ENullContext * /*ctx*/) override { }

  virtual void enterAddOp(fxParser::AddOpContext * /*ctx*/) override { }
  virtual void exitAddOp(fxParser::AddOpContext * /*ctx*/) override { }

  virtual void enterMulOp(fxParser::MulOpContext * /*ctx*/) override { }
  virtual void exitMulOp(fxParser::MulOpContext * /*ctx*/) override { }

  virtual void enterRelOp(fxParser::RelOpContext * /*ctx*/) override { }
  virtual void exitRelOp(fxParser::RelOpContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

