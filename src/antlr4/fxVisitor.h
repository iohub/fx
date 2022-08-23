
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

    virtual antlrcpp::Any visitStmt(fxParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitForStmt(fxParser::ForStmtContext *context) = 0;

    virtual antlrcpp::Any visitVarDecl(fxParser::VarDeclContext *context) = 0;

    virtual antlrcpp::Any visitAgnDecl(fxParser::AgnDeclContext *context) = 0;

    virtual antlrcpp::Any visitMatrixDecl(fxParser::MatrixDeclContext *context) = 0;

    virtual antlrcpp::Any visitMatrixAgnDecl(fxParser::MatrixAgnDeclContext *context) = 0;

    virtual antlrcpp::Any visitAgnStmt(fxParser::AgnStmtContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(fxParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(fxParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitInt(fxParser::IntContext *context) = 0;

    virtual antlrcpp::Any visitStr(fxParser::StrContext *context) = 0;

    virtual antlrcpp::Any visitBool(fxParser::BoolContext *context) = 0;

    virtual antlrcpp::Any visitVoid(fxParser::VoidContext *context) = 0;

    virtual antlrcpp::Any visitClassName(fxParser::ClassNameContext *context) = 0;

    virtual antlrcpp::Any visitAndExpr(fxParser::AndExprContext *context) = 0;

    virtual antlrcpp::Any visitIDExpr(fxParser::IDExprContext *context) = 0;

    virtual antlrcpp::Any visitConstExpr(fxParser::ConstExprContext *context) = 0;

    virtual antlrcpp::Any visitRelOpExpr(fxParser::RelOpExprContext *context) = 0;

    virtual antlrcpp::Any visitCallExpr(fxParser::CallExprContext *context) = 0;

    virtual antlrcpp::Any visitBinOpExpr(fxParser::BinOpExprContext *context) = 0;

    virtual antlrcpp::Any visitOrExpr(fxParser::OrExprContext *context) = 0;

    virtual antlrcpp::Any visitParamList(fxParser::ParamListContext *context) = 0;

    virtual antlrcpp::Any visitMatrixConst(fxParser::MatrixConstContext *context) = 0;

    virtual antlrcpp::Any visitMatrixLine(fxParser::MatrixLineContext *context) = 0;

    virtual antlrcpp::Any visitBoolean(fxParser::BooleanContext *context) = 0;

    virtual antlrcpp::Any visitConstBool(fxParser::ConstBoolContext *context) = 0;

    virtual antlrcpp::Any visitConstInt(fxParser::ConstIntContext *context) = 0;

    virtual antlrcpp::Any visitConstStr(fxParser::ConstStrContext *context) = 0;

    virtual antlrcpp::Any visitBinOp(fxParser::BinOpContext *context) = 0;

    virtual antlrcpp::Any visitRelOp(fxParser::RelOpContext *context) = 0;


};

