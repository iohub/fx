
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

  virtual void enterStmt(fxParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(fxParser::StmtContext * /*ctx*/) override { }

  virtual void enterForStmt(fxParser::ForStmtContext * /*ctx*/) override { }
  virtual void exitForStmt(fxParser::ForStmtContext * /*ctx*/) override { }

  virtual void enterVarDecl(fxParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(fxParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterAss(fxParser::AssContext * /*ctx*/) override { }
  virtual void exitAss(fxParser::AssContext * /*ctx*/) override { }

  virtual void enterReturnStmt(fxParser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(fxParser::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterIfStmt(fxParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(fxParser::IfStmtContext * /*ctx*/) override { }

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

  virtual void enterAndExpr(fxParser::AndExprContext * /*ctx*/) override { }
  virtual void exitAndExpr(fxParser::AndExprContext * /*ctx*/) override { }

  virtual void enterIDExpr(fxParser::IDExprContext * /*ctx*/) override { }
  virtual void exitIDExpr(fxParser::IDExprContext * /*ctx*/) override { }

  virtual void enterConstExpr(fxParser::ConstExprContext * /*ctx*/) override { }
  virtual void exitConstExpr(fxParser::ConstExprContext * /*ctx*/) override { }

  virtual void enterRelOpExpr(fxParser::RelOpExprContext * /*ctx*/) override { }
  virtual void exitRelOpExpr(fxParser::RelOpExprContext * /*ctx*/) override { }

  virtual void enterCallExpr(fxParser::CallExprContext * /*ctx*/) override { }
  virtual void exitCallExpr(fxParser::CallExprContext * /*ctx*/) override { }

  virtual void enterBinOpExpr(fxParser::BinOpExprContext * /*ctx*/) override { }
  virtual void exitBinOpExpr(fxParser::BinOpExprContext * /*ctx*/) override { }

  virtual void enterOrExpr(fxParser::OrExprContext * /*ctx*/) override { }
  virtual void exitOrExpr(fxParser::OrExprContext * /*ctx*/) override { }

  virtual void enterParamList(fxParser::ParamListContext * /*ctx*/) override { }
  virtual void exitParamList(fxParser::ParamListContext * /*ctx*/) override { }

  virtual void enterBoolean(fxParser::BooleanContext * /*ctx*/) override { }
  virtual void exitBoolean(fxParser::BooleanContext * /*ctx*/) override { }

  virtual void enterConstBool(fxParser::ConstBoolContext * /*ctx*/) override { }
  virtual void exitConstBool(fxParser::ConstBoolContext * /*ctx*/) override { }

  virtual void enterConstInt(fxParser::ConstIntContext * /*ctx*/) override { }
  virtual void exitConstInt(fxParser::ConstIntContext * /*ctx*/) override { }

  virtual void enterConstStr(fxParser::ConstStrContext * /*ctx*/) override { }
  virtual void exitConstStr(fxParser::ConstStrContext * /*ctx*/) override { }

  virtual void enterBinOp(fxParser::BinOpContext * /*ctx*/) override { }
  virtual void exitBinOp(fxParser::BinOpContext * /*ctx*/) override { }

  virtual void enterRelOp(fxParser::RelOpContext * /*ctx*/) override { }
  virtual void exitRelOp(fxParser::RelOpContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

