
// Generated from fx.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "fxParser.h"
#include <fmt/core.h>



/**
 * This class defines an abstract visitor for a parse tree
 * produced by fxParser.
 */
class  fxVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by fxParser.
   */
    virtual antlrcpp::Any visitCompilationUnit(fxParser::CompilationUnitContext *context) {
        return visitTranslationUnit(context->translationUnit());
    };

    virtual antlrcpp::Any visitTranslationUnit(fxParser::TranslationUnitContext *context) {
        for (auto &e : context->externalDeclaration()) {
            visitExternalDeclaration(e);
        }
        return 0;
    };

    virtual antlrcpp::Any visitExternalDeclaration(fxParser::ExternalDeclarationContext *context) {
        return visitFunctionDefinition(context->functionDefinition());
    };

    virtual antlrcpp::Any visitFunctionDefinition(fxParser::FunctionDefinitionContext *context) {
        std::string ident = context->Identifier()->toString();
        fmt::print("def {} {}\n", ident, context->toString()); return 0;
    };

    virtual antlrcpp::Any visitDeclarationSpecifiers(fxParser::DeclarationSpecifiersContext *context) {
        fmt::print("{}\n", context->toString()); return 0;
    };

    virtual antlrcpp::Any visitDeclarationSpecifier(fxParser::DeclarationSpecifierContext *context) {
        fmt::print("{}\n", context->toString()); return 0;
    };

    virtual antlrcpp::Any visitParameterList(fxParser::ParameterListContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitParameterDeclaration(fxParser::ParameterDeclarationContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitIdentifierList(fxParser::IdentifierListContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitAssignmentOperator(fxParser::AssignmentOperatorContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitTypeSpecifier(fxParser::TypeSpecifierContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitCompoundStatement(fxParser::CompoundStatementContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitStatement(fxParser::StatementContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitIf_statement(fxParser::If_statementContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitElse_clause(fxParser::Else_clauseContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitCond_expression(fxParser::Cond_expressionContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitBinary_expression(fxParser::Binary_expressionContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitBinary_compare(fxParser::Binary_compareContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitReturn_statement(fxParser::Return_statementContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitExpression(fxParser::ExpressionContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitStatements(fxParser::StatementsContext *context) { fmt::print("{}\n", context->toString()); return 0; };

    virtual antlrcpp::Any visitAssignment_expression(fxParser::Assignment_expressionContext *context) { fmt::print("{}\n", context->toString()); return 0; };


};


