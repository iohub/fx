
// Generated from fx.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "fxParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by fxParser.
 */
class  fxVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by fxParser.
   */
    virtual antlrcpp::Any visitProgram(fxParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitTopDef(fxParser::TopDefContext *context) = 0;

    virtual antlrcpp::Any visitFuncDef(fxParser::FuncDefContext *context) = 0;

    virtual antlrcpp::Any visitClassDef(fxParser::ClassDefContext *context) = 0;

    virtual antlrcpp::Any visitFieldDecl(fxParser::FieldDeclContext *context) = 0;

    virtual antlrcpp::Any visitMethodDef(fxParser::MethodDefContext *context) = 0;

    virtual antlrcpp::Any visitArg(fxParser::ArgContext *context) = 0;

    virtual antlrcpp::Any visitVarDef(fxParser::VarDefContext *context) = 0;

    virtual antlrcpp::Any visitBlock(fxParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitEmpty(fxParser::EmptyContext *context) = 0;

    virtual antlrcpp::Any visitBlockStmt(fxParser::BlockStmtContext *context) = 0;

    virtual antlrcpp::Any visitDecl(fxParser::DeclContext *context) = 0;

    virtual antlrcpp::Any visitAss(fxParser::AssContext *context) = 0;

    virtual antlrcpp::Any visitIncr(fxParser::IncrContext *context) = 0;

    virtual antlrcpp::Any visitDecr(fxParser::DecrContext *context) = 0;

    virtual antlrcpp::Any visitRet(fxParser::RetContext *context) = 0;

    virtual antlrcpp::Any visitVRet(fxParser::VRetContext *context) = 0;

    virtual antlrcpp::Any visitCond(fxParser::CondContext *context) = 0;

    virtual antlrcpp::Any visitCondElse(fxParser::CondElseContext *context) = 0;

    virtual antlrcpp::Any visitWhile(fxParser::WhileContext *context) = 0;

    virtual antlrcpp::Any visitSExp(fxParser::SExpContext *context) = 0;

    virtual antlrcpp::Any visitInt(fxParser::IntContext *context) = 0;

    virtual antlrcpp::Any visitStr(fxParser::StrContext *context) = 0;

    virtual antlrcpp::Any visitBool(fxParser::BoolContext *context) = 0;

    virtual antlrcpp::Any visitVoid(fxParser::VoidContext *context) = 0;

    virtual antlrcpp::Any visitClassName(fxParser::ClassNameContext *context) = 0;

    virtual antlrcpp::Any visitItem(fxParser::ItemContext *context) = 0;

    virtual antlrcpp::Any visitEId(fxParser::EIdContext *context) = 0;

    virtual antlrcpp::Any visitEFunCall(fxParser::EFunCallContext *context) = 0;

    virtual antlrcpp::Any visitERelOp(fxParser::ERelOpContext *context) = 0;

    virtual antlrcpp::Any visitETrue(fxParser::ETrueContext *context) = 0;

    virtual antlrcpp::Any visitEOr(fxParser::EOrContext *context) = 0;

    virtual antlrcpp::Any visitEInt(fxParser::EIntContext *context) = 0;

    virtual antlrcpp::Any visitEMemberExpr(fxParser::EMemberExprContext *context) = 0;

    virtual antlrcpp::Any visitEUnOp(fxParser::EUnOpContext *context) = 0;

    virtual antlrcpp::Any visitEStr(fxParser::EStrContext *context) = 0;

    virtual antlrcpp::Any visitENewExpr(fxParser::ENewExprContext *context) = 0;

    virtual antlrcpp::Any visitEMulOp(fxParser::EMulOpContext *context) = 0;

    virtual antlrcpp::Any visitEAnd(fxParser::EAndContext *context) = 0;

    virtual antlrcpp::Any visitEClassCast(fxParser::EClassCastContext *context) = 0;

    virtual antlrcpp::Any visitEParen(fxParser::EParenContext *context) = 0;

    virtual antlrcpp::Any visitEFalse(fxParser::EFalseContext *context) = 0;

    virtual antlrcpp::Any visitEAddOp(fxParser::EAddOpContext *context) = 0;

    virtual antlrcpp::Any visitENull(fxParser::ENullContext *context) = 0;

    virtual antlrcpp::Any visitAddOp(fxParser::AddOpContext *context) = 0;

    virtual antlrcpp::Any visitMulOp(fxParser::MulOpContext *context) = 0;

    virtual antlrcpp::Any visitRelOp(fxParser::RelOpContext *context) = 0;


};

