#ifndef FX_VISITOR_IMPL_
#define FX_VISITOR_IMPL_

#include "fxLexer.h"
#include "fxVisitor.h"
#include "ast.h"

using namespace fx;

class  AstVisitor : public fxVisitor {
public:
    AstVisitor() { ast = new Decls(Loc()); }

    virtual antlrcpp::Any visitProgram(fxParser::ProgramContext *ctx);
    virtual antlrcpp::Any visitFuncDef(fxParser::FuncDefContext *ctx);
    virtual antlrcpp::Any visitTopDef(fxParser::TopDefContext *ctx);
    virtual antlrcpp::Any visitClassDef(fxParser::ClassDefContext *ctx);
    virtual antlrcpp::Any visitFieldDecl(fxParser::FieldDeclContext *ctx);
    virtual antlrcpp::Any visitMethodDef(fxParser::MethodDefContext *ctx);
    virtual antlrcpp::Any visitArg(fxParser::ArgContext *ctx);
    virtual antlrcpp::Any visitVarDef(fxParser::VarDefContext *ctx);
    virtual antlrcpp::Any visitBlock(fxParser::BlockContext *ctx);
    virtual antlrcpp::Any visitAgnStmt(fxParser::AgnStmtContext *ctx);
    virtual antlrcpp::Any visitStmt(fxParser::StmtContext *ctx);
    virtual antlrcpp::Any visitInt(fxParser::IntContext *ctx);
    virtual antlrcpp::Any visitStr(fxParser::StrContext *ctx);
    virtual antlrcpp::Any visitBool(fxParser::BoolContext *ctx);
    virtual antlrcpp::Any visitVoid(fxParser::VoidContext *ctx);
    virtual antlrcpp::Any visitClassName(fxParser::ClassNameContext *ctx);
    virtual antlrcpp::Any visitRelOp(fxParser::RelOpContext *ctx);
    virtual antlrcpp::Any visitBinOp(fxParser::BinOpContext *ctx);
    virtual antlrcpp::Any visitAndExpr(fxParser::AndExprContext *ctx);
    virtual antlrcpp::Any visitIDExpr(fxParser::IDExprContext *ctx);
    virtual antlrcpp::Any visitConstExpr(fxParser::ConstExprContext *ctx);
    virtual antlrcpp::Any visitParamList(fxParser::ParamListContext *ctx);
    virtual antlrcpp::Any visitCallExpr(fxParser::CallExprContext *ctx);
    virtual antlrcpp::Any visitRelOpExpr(fxParser::RelOpExprContext *ctx);
    virtual antlrcpp::Any visitBinOpExpr(fxParser::BinOpExprContext *ctx);
    virtual antlrcpp::Any visitOrExpr(fxParser::OrExprContext *ctx);
    virtual antlrcpp::Any visitConstBool(fxParser::ConstBoolContext *ctx);
    virtual antlrcpp::Any visitConstInt(fxParser::ConstIntContext *ctx);
    virtual antlrcpp::Any visitConstStr(fxParser::ConstStrContext *ctx);
    virtual antlrcpp::Any visitBoolean(fxParser::BooleanContext *ctx);
    virtual antlrcpp::Any visitIfStmt(fxParser::IfStmtContext *ctx);
    virtual antlrcpp::Any visitReturnStmt(fxParser::ReturnStmtContext *ctx);
    virtual antlrcpp::Any visitForStmt(fxParser::ForStmtContext *ctx);
    virtual antlrcpp::Any visitVarDecl(fxParser::VarDeclContext *ctx);
    virtual antlrcpp::Any visitAgnDecl(fxParser::AgnDeclContext *context);
    virtual antlrcpp::Any visitMatrixDecl(fxParser::MatrixDeclContext *context);
    virtual antlrcpp::Any visitMatrixAgnDecl(fxParser::MatrixAgnDeclContext *context);
    virtual antlrcpp::Any visitMatrixConst(fxParser::MatrixConstContext *context);
    virtual antlrcpp::Any visitMatrixLine(fxParser::MatrixLineContext *context);
    virtual antlrcpp::Any visitTargetType(fxParser::TargetTypeContext *context);



public:
    Decls *ast;
    Loc loc(antlr4::ParserRuleContext *ctx);
};





#endif
