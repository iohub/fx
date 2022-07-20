
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

  virtual void enterCompilationUnit(fxParser::CompilationUnitContext * /*ctx*/) override { }
  virtual void exitCompilationUnit(fxParser::CompilationUnitContext * /*ctx*/) override { }

  virtual void enterTranslationUnit(fxParser::TranslationUnitContext * /*ctx*/) override { }
  virtual void exitTranslationUnit(fxParser::TranslationUnitContext * /*ctx*/) override { }

  virtual void enterExternalDeclaration(fxParser::ExternalDeclarationContext * /*ctx*/) override { }
  virtual void exitExternalDeclaration(fxParser::ExternalDeclarationContext * /*ctx*/) override { }

  virtual void enterFunctionDefinition(fxParser::FunctionDefinitionContext * /*ctx*/) override { }
  virtual void exitFunctionDefinition(fxParser::FunctionDefinitionContext * /*ctx*/) override { }

  virtual void enterDeclarationSpecifiers(fxParser::DeclarationSpecifiersContext * /*ctx*/) override { }
  virtual void exitDeclarationSpecifiers(fxParser::DeclarationSpecifiersContext * /*ctx*/) override { }

  virtual void enterDeclarationSpecifier(fxParser::DeclarationSpecifierContext * /*ctx*/) override { }
  virtual void exitDeclarationSpecifier(fxParser::DeclarationSpecifierContext * /*ctx*/) override { }

  virtual void enterParameterList(fxParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(fxParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameterDeclaration(fxParser::ParameterDeclarationContext * /*ctx*/) override { }
  virtual void exitParameterDeclaration(fxParser::ParameterDeclarationContext * /*ctx*/) override { }

  virtual void enterIdentifierList(fxParser::IdentifierListContext * /*ctx*/) override { }
  virtual void exitIdentifierList(fxParser::IdentifierListContext * /*ctx*/) override { }

  virtual void enterAssignmentOperator(fxParser::AssignmentOperatorContext * /*ctx*/) override { }
  virtual void exitAssignmentOperator(fxParser::AssignmentOperatorContext * /*ctx*/) override { }

  virtual void enterTypeSpecifier(fxParser::TypeSpecifierContext * /*ctx*/) override { }
  virtual void exitTypeSpecifier(fxParser::TypeSpecifierContext * /*ctx*/) override { }

  virtual void enterCompoundStatement(fxParser::CompoundStatementContext * /*ctx*/) override { }
  virtual void exitCompoundStatement(fxParser::CompoundStatementContext * /*ctx*/) override { }

  virtual void enterStatement(fxParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(fxParser::StatementContext * /*ctx*/) override { }

  virtual void enterIf_statement(fxParser::If_statementContext * /*ctx*/) override { }
  virtual void exitIf_statement(fxParser::If_statementContext * /*ctx*/) override { }

  virtual void enterElse_clause(fxParser::Else_clauseContext * /*ctx*/) override { }
  virtual void exitElse_clause(fxParser::Else_clauseContext * /*ctx*/) override { }

  virtual void enterCond_expression(fxParser::Cond_expressionContext * /*ctx*/) override { }
  virtual void exitCond_expression(fxParser::Cond_expressionContext * /*ctx*/) override { }

  virtual void enterBinary_expression(fxParser::Binary_expressionContext * /*ctx*/) override { }
  virtual void exitBinary_expression(fxParser::Binary_expressionContext * /*ctx*/) override { }

  virtual void enterBinary_compare(fxParser::Binary_compareContext * /*ctx*/) override { }
  virtual void exitBinary_compare(fxParser::Binary_compareContext * /*ctx*/) override { }

  virtual void enterReturn_statement(fxParser::Return_statementContext * /*ctx*/) override { }
  virtual void exitReturn_statement(fxParser::Return_statementContext * /*ctx*/) override { }

  virtual void enterExpression(fxParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(fxParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterStatements(fxParser::StatementsContext * /*ctx*/) override { }
  virtual void exitStatements(fxParser::StatementsContext * /*ctx*/) override { }

  virtual void enterAssignment_expression(fxParser::Assignment_expressionContext * /*ctx*/) override { }
  virtual void exitAssignment_expression(fxParser::Assignment_expressionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

