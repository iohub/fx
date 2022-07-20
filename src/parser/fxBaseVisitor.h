
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

  virtual antlrcpp::Any visitCompilationUnit(fxParser::CompilationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTranslationUnit(fxParser::TranslationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExternalDeclaration(fxParser::ExternalDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDefinition(fxParser::FunctionDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationSpecifiers(fxParser::DeclarationSpecifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationSpecifier(fxParser::DeclarationSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterList(fxParser::ParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterDeclaration(fxParser::ParameterDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierList(fxParser::IdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentOperator(fxParser::AssignmentOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeSpecifier(fxParser::TypeSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompoundStatement(fxParser::CompoundStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(fxParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_statement(fxParser::If_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElse_clause(fxParser::Else_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond_expression(fxParser::Cond_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinary_expression(fxParser::Binary_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinary_compare(fxParser::Binary_compareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturn_statement(fxParser::Return_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(fxParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatements(fxParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment_expression(fxParser::Assignment_expressionContext *ctx) override {
    return visitChildren(ctx);
  }


};

