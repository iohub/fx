
// Generated from fx.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "fxParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by fxParser.
 */
class  fxListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompilationUnit(fxParser::CompilationUnitContext *ctx) = 0;
  virtual void exitCompilationUnit(fxParser::CompilationUnitContext *ctx) = 0;

  virtual void enterTranslationUnit(fxParser::TranslationUnitContext *ctx) = 0;
  virtual void exitTranslationUnit(fxParser::TranslationUnitContext *ctx) = 0;

  virtual void enterExternalDeclaration(fxParser::ExternalDeclarationContext *ctx) = 0;
  virtual void exitExternalDeclaration(fxParser::ExternalDeclarationContext *ctx) = 0;

  virtual void enterFunctionDefinition(fxParser::FunctionDefinitionContext *ctx) = 0;
  virtual void exitFunctionDefinition(fxParser::FunctionDefinitionContext *ctx) = 0;

  virtual void enterDeclarationSpecifiers(fxParser::DeclarationSpecifiersContext *ctx) = 0;
  virtual void exitDeclarationSpecifiers(fxParser::DeclarationSpecifiersContext *ctx) = 0;

  virtual void enterDeclarationSpecifier(fxParser::DeclarationSpecifierContext *ctx) = 0;
  virtual void exitDeclarationSpecifier(fxParser::DeclarationSpecifierContext *ctx) = 0;

  virtual void enterParameterList(fxParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(fxParser::ParameterListContext *ctx) = 0;

  virtual void enterParameterDeclaration(fxParser::ParameterDeclarationContext *ctx) = 0;
  virtual void exitParameterDeclaration(fxParser::ParameterDeclarationContext *ctx) = 0;

  virtual void enterIdentifierList(fxParser::IdentifierListContext *ctx) = 0;
  virtual void exitIdentifierList(fxParser::IdentifierListContext *ctx) = 0;

  virtual void enterAssignmentOperator(fxParser::AssignmentOperatorContext *ctx) = 0;
  virtual void exitAssignmentOperator(fxParser::AssignmentOperatorContext *ctx) = 0;

  virtual void enterTypeSpecifier(fxParser::TypeSpecifierContext *ctx) = 0;
  virtual void exitTypeSpecifier(fxParser::TypeSpecifierContext *ctx) = 0;

  virtual void enterCompoundStatement(fxParser::CompoundStatementContext *ctx) = 0;
  virtual void exitCompoundStatement(fxParser::CompoundStatementContext *ctx) = 0;

  virtual void enterStatement(fxParser::StatementContext *ctx) = 0;
  virtual void exitStatement(fxParser::StatementContext *ctx) = 0;

  virtual void enterIf_statement(fxParser::If_statementContext *ctx) = 0;
  virtual void exitIf_statement(fxParser::If_statementContext *ctx) = 0;

  virtual void enterElse_clause(fxParser::Else_clauseContext *ctx) = 0;
  virtual void exitElse_clause(fxParser::Else_clauseContext *ctx) = 0;

  virtual void enterCond_expression(fxParser::Cond_expressionContext *ctx) = 0;
  virtual void exitCond_expression(fxParser::Cond_expressionContext *ctx) = 0;

  virtual void enterBinary_expression(fxParser::Binary_expressionContext *ctx) = 0;
  virtual void exitBinary_expression(fxParser::Binary_expressionContext *ctx) = 0;

  virtual void enterBinary_compare(fxParser::Binary_compareContext *ctx) = 0;
  virtual void exitBinary_compare(fxParser::Binary_compareContext *ctx) = 0;

  virtual void enterReturn_statement(fxParser::Return_statementContext *ctx) = 0;
  virtual void exitReturn_statement(fxParser::Return_statementContext *ctx) = 0;

  virtual void enterExpression(fxParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(fxParser::ExpressionContext *ctx) = 0;

  virtual void enterStatements(fxParser::StatementsContext *ctx) = 0;
  virtual void exitStatements(fxParser::StatementsContext *ctx) = 0;

  virtual void enterAssignment_expression(fxParser::Assignment_expressionContext *ctx) = 0;
  virtual void exitAssignment_expression(fxParser::Assignment_expressionContext *ctx) = 0;


};

