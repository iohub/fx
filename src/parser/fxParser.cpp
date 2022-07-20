
// Generated from fx.g4 by ANTLR 4.7.2


#include "fxListener.h"
#include "fxVisitor.h"

#include "fxParser.h"


using namespace antlrcpp;
using namespace antlr4;

fxParser::fxParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

fxParser::~fxParser() {
  delete _interpreter;
}

std::string fxParser::getGrammarFileName() const {
  return "fx.g4";
}

const std::vector<std::string>& fxParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& fxParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

fxParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* fxParser::CompilationUnitContext::EOF() {
  return getToken(fxParser::EOF, 0);
}

fxParser::TranslationUnitContext* fxParser::CompilationUnitContext::translationUnit() {
  return getRuleContext<fxParser::TranslationUnitContext>(0);
}


size_t fxParser::CompilationUnitContext::getRuleIndex() const {
  return fxParser::RuleCompilationUnit;
}

void fxParser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void fxParser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}


antlrcpp::Any fxParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

fxParser::CompilationUnitContext* fxParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, fxParser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == fxParser::T__0) {
      setState(44);
      translationUnit();
    }
    setState(47);
    match(fxParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TranslationUnitContext ------------------------------------------------------------------

fxParser::TranslationUnitContext::TranslationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<fxParser::ExternalDeclarationContext *> fxParser::TranslationUnitContext::externalDeclaration() {
  return getRuleContexts<fxParser::ExternalDeclarationContext>();
}

fxParser::ExternalDeclarationContext* fxParser::TranslationUnitContext::externalDeclaration(size_t i) {
  return getRuleContext<fxParser::ExternalDeclarationContext>(i);
}


size_t fxParser::TranslationUnitContext::getRuleIndex() const {
  return fxParser::RuleTranslationUnit;
}

void fxParser::TranslationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTranslationUnit(this);
}

void fxParser::TranslationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTranslationUnit(this);
}


antlrcpp::Any fxParser::TranslationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitTranslationUnit(this);
  else
    return visitor->visitChildren(this);
}

fxParser::TranslationUnitContext* fxParser::translationUnit() {
  TranslationUnitContext *_localctx = _tracker.createInstance<TranslationUnitContext>(_ctx, getState());
  enterRule(_localctx, 2, fxParser::RuleTranslationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(49);
      externalDeclaration();
      setState(52); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == fxParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternalDeclarationContext ------------------------------------------------------------------

fxParser::ExternalDeclarationContext::ExternalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

fxParser::FunctionDefinitionContext* fxParser::ExternalDeclarationContext::functionDefinition() {
  return getRuleContext<fxParser::FunctionDefinitionContext>(0);
}


size_t fxParser::ExternalDeclarationContext::getRuleIndex() const {
  return fxParser::RuleExternalDeclaration;
}

void fxParser::ExternalDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternalDeclaration(this);
}

void fxParser::ExternalDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternalDeclaration(this);
}


antlrcpp::Any fxParser::ExternalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitExternalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

fxParser::ExternalDeclarationContext* fxParser::externalDeclaration() {
  ExternalDeclarationContext *_localctx = _tracker.createInstance<ExternalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, fxParser::RuleExternalDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    functionDefinition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

fxParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* fxParser::FunctionDefinitionContext::Identifier() {
  return getToken(fxParser::Identifier, 0);
}

tree::TerminalNode* fxParser::FunctionDefinitionContext::LeftParen() {
  return getToken(fxParser::LeftParen, 0);
}

fxParser::ParameterListContext* fxParser::FunctionDefinitionContext::parameterList() {
  return getRuleContext<fxParser::ParameterListContext>(0);
}

tree::TerminalNode* fxParser::FunctionDefinitionContext::RightParen() {
  return getToken(fxParser::RightParen, 0);
}

fxParser::TypeSpecifierContext* fxParser::FunctionDefinitionContext::typeSpecifier() {
  return getRuleContext<fxParser::TypeSpecifierContext>(0);
}

fxParser::CompoundStatementContext* fxParser::FunctionDefinitionContext::compoundStatement() {
  return getRuleContext<fxParser::CompoundStatementContext>(0);
}


size_t fxParser::FunctionDefinitionContext::getRuleIndex() const {
  return fxParser::RuleFunctionDefinition;
}

void fxParser::FunctionDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefinition(this);
}

void fxParser::FunctionDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefinition(this);
}


antlrcpp::Any fxParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

fxParser::FunctionDefinitionContext* fxParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 6, fxParser::RuleFunctionDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(fxParser::T__0);
    setState(57);
    match(fxParser::Identifier);
    setState(58);
    match(fxParser::LeftParen);
    setState(59);
    parameterList();
    setState(60);
    match(fxParser::RightParen);
    setState(61);
    typeSpecifier();
    setState(62);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifiersContext ------------------------------------------------------------------

fxParser::DeclarationSpecifiersContext::DeclarationSpecifiersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<fxParser::DeclarationSpecifierContext *> fxParser::DeclarationSpecifiersContext::declarationSpecifier() {
  return getRuleContexts<fxParser::DeclarationSpecifierContext>();
}

fxParser::DeclarationSpecifierContext* fxParser::DeclarationSpecifiersContext::declarationSpecifier(size_t i) {
  return getRuleContext<fxParser::DeclarationSpecifierContext>(i);
}


size_t fxParser::DeclarationSpecifiersContext::getRuleIndex() const {
  return fxParser::RuleDeclarationSpecifiers;
}

void fxParser::DeclarationSpecifiersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifiers(this);
}

void fxParser::DeclarationSpecifiersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifiers(this);
}


antlrcpp::Any fxParser::DeclarationSpecifiersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifiers(this);
  else
    return visitor->visitChildren(this);
}

fxParser::DeclarationSpecifiersContext* fxParser::declarationSpecifiers() {
  DeclarationSpecifiersContext *_localctx = _tracker.createInstance<DeclarationSpecifiersContext>(_ctx, getState());
  enterRule(_localctx, 8, fxParser::RuleDeclarationSpecifiers);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(64);
      declarationSpecifier();
      setState(67); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__1)
      | (1ULL << fxParser::Char)
      | (1ULL << fxParser::Float)
      | (1ULL << fxParser::Int)
      | (1ULL << fxParser::Void)
      | (1ULL << fxParser::Bool))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifierContext ------------------------------------------------------------------

fxParser::DeclarationSpecifierContext::DeclarationSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

fxParser::TypeSpecifierContext* fxParser::DeclarationSpecifierContext::typeSpecifier() {
  return getRuleContext<fxParser::TypeSpecifierContext>(0);
}


size_t fxParser::DeclarationSpecifierContext::getRuleIndex() const {
  return fxParser::RuleDeclarationSpecifier;
}

void fxParser::DeclarationSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifier(this);
}

void fxParser::DeclarationSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifier(this);
}


antlrcpp::Any fxParser::DeclarationSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifier(this);
  else
    return visitor->visitChildren(this);
}

fxParser::DeclarationSpecifierContext* fxParser::declarationSpecifier() {
  DeclarationSpecifierContext *_localctx = _tracker.createInstance<DeclarationSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 10, fxParser::RuleDeclarationSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    typeSpecifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

fxParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<fxParser::ParameterDeclarationContext *> fxParser::ParameterListContext::parameterDeclaration() {
  return getRuleContexts<fxParser::ParameterDeclarationContext>();
}

fxParser::ParameterDeclarationContext* fxParser::ParameterListContext::parameterDeclaration(size_t i) {
  return getRuleContext<fxParser::ParameterDeclarationContext>(i);
}

std::vector<tree::TerminalNode *> fxParser::ParameterListContext::Comma() {
  return getTokens(fxParser::Comma);
}

tree::TerminalNode* fxParser::ParameterListContext::Comma(size_t i) {
  return getToken(fxParser::Comma, i);
}


size_t fxParser::ParameterListContext::getRuleIndex() const {
  return fxParser::RuleParameterList;
}

void fxParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void fxParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}


antlrcpp::Any fxParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

fxParser::ParameterListContext* fxParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 12, fxParser::RuleParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    parameterDeclaration();
    setState(76);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == fxParser::Comma) {
      setState(72);
      match(fxParser::Comma);
      setState(73);
      parameterDeclaration();
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationContext ------------------------------------------------------------------

fxParser::ParameterDeclarationContext::ParameterDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

fxParser::DeclarationSpecifiersContext* fxParser::ParameterDeclarationContext::declarationSpecifiers() {
  return getRuleContext<fxParser::DeclarationSpecifiersContext>(0);
}

tree::TerminalNode* fxParser::ParameterDeclarationContext::Identifier() {
  return getToken(fxParser::Identifier, 0);
}


size_t fxParser::ParameterDeclarationContext::getRuleIndex() const {
  return fxParser::RuleParameterDeclaration;
}

void fxParser::ParameterDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterDeclaration(this);
}

void fxParser::ParameterDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterDeclaration(this);
}


antlrcpp::Any fxParser::ParameterDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitParameterDeclaration(this);
  else
    return visitor->visitChildren(this);
}

fxParser::ParameterDeclarationContext* fxParser::parameterDeclaration() {
  ParameterDeclarationContext *_localctx = _tracker.createInstance<ParameterDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 14, fxParser::RuleParameterDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    declarationSpecifiers();
    setState(80);
    match(fxParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

fxParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> fxParser::IdentifierListContext::Identifier() {
  return getTokens(fxParser::Identifier);
}

tree::TerminalNode* fxParser::IdentifierListContext::Identifier(size_t i) {
  return getToken(fxParser::Identifier, i);
}

std::vector<tree::TerminalNode *> fxParser::IdentifierListContext::Comma() {
  return getTokens(fxParser::Comma);
}

tree::TerminalNode* fxParser::IdentifierListContext::Comma(size_t i) {
  return getToken(fxParser::Comma, i);
}


size_t fxParser::IdentifierListContext::getRuleIndex() const {
  return fxParser::RuleIdentifierList;
}

void fxParser::IdentifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierList(this);
}

void fxParser::IdentifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierList(this);
}


antlrcpp::Any fxParser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

fxParser::IdentifierListContext* fxParser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 16, fxParser::RuleIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(fxParser::Identifier);
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == fxParser::Comma) {
      setState(83);
      match(fxParser::Comma);
      setState(84);
      match(fxParser::Identifier);
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

fxParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* fxParser::AssignmentOperatorContext::Assign() {
  return getToken(fxParser::Assign, 0);
}

tree::TerminalNode* fxParser::AssignmentOperatorContext::StarAssign() {
  return getToken(fxParser::StarAssign, 0);
}

tree::TerminalNode* fxParser::AssignmentOperatorContext::DivAssign() {
  return getToken(fxParser::DivAssign, 0);
}

tree::TerminalNode* fxParser::AssignmentOperatorContext::ModAssign() {
  return getToken(fxParser::ModAssign, 0);
}

tree::TerminalNode* fxParser::AssignmentOperatorContext::PlusAssign() {
  return getToken(fxParser::PlusAssign, 0);
}

tree::TerminalNode* fxParser::AssignmentOperatorContext::MinusAssign() {
  return getToken(fxParser::MinusAssign, 0);
}

tree::TerminalNode* fxParser::AssignmentOperatorContext::LeftShiftAssign() {
  return getToken(fxParser::LeftShiftAssign, 0);
}

tree::TerminalNode* fxParser::AssignmentOperatorContext::RightShiftAssign() {
  return getToken(fxParser::RightShiftAssign, 0);
}

tree::TerminalNode* fxParser::AssignmentOperatorContext::AndAssign() {
  return getToken(fxParser::AndAssign, 0);
}

tree::TerminalNode* fxParser::AssignmentOperatorContext::XorAssign() {
  return getToken(fxParser::XorAssign, 0);
}

tree::TerminalNode* fxParser::AssignmentOperatorContext::OrAssign() {
  return getToken(fxParser::OrAssign, 0);
}


size_t fxParser::AssignmentOperatorContext::getRuleIndex() const {
  return fxParser::RuleAssignmentOperator;
}

void fxParser::AssignmentOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void fxParser::AssignmentOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}


antlrcpp::Any fxParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

fxParser::AssignmentOperatorContext* fxParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 18, fxParser::RuleAssignmentOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::Assign)
      | (1ULL << fxParser::StarAssign)
      | (1ULL << fxParser::DivAssign)
      | (1ULL << fxParser::ModAssign)
      | (1ULL << fxParser::PlusAssign)
      | (1ULL << fxParser::MinusAssign)
      | (1ULL << fxParser::LeftShiftAssign)
      | (1ULL << fxParser::RightShiftAssign)
      | (1ULL << fxParser::AndAssign)
      | (1ULL << fxParser::XorAssign)
      | (1ULL << fxParser::OrAssign))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecifierContext ------------------------------------------------------------------

fxParser::TypeSpecifierContext::TypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* fxParser::TypeSpecifierContext::Void() {
  return getToken(fxParser::Void, 0);
}

tree::TerminalNode* fxParser::TypeSpecifierContext::Char() {
  return getToken(fxParser::Char, 0);
}

tree::TerminalNode* fxParser::TypeSpecifierContext::Int() {
  return getToken(fxParser::Int, 0);
}

tree::TerminalNode* fxParser::TypeSpecifierContext::Float() {
  return getToken(fxParser::Float, 0);
}

tree::TerminalNode* fxParser::TypeSpecifierContext::Bool() {
  return getToken(fxParser::Bool, 0);
}


size_t fxParser::TypeSpecifierContext::getRuleIndex() const {
  return fxParser::RuleTypeSpecifier;
}

void fxParser::TypeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSpecifier(this);
}

void fxParser::TypeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSpecifier(this);
}


antlrcpp::Any fxParser::TypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

fxParser::TypeSpecifierContext* fxParser::typeSpecifier() {
  TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 20, fxParser::RuleTypeSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__1)
      | (1ULL << fxParser::Char)
      | (1ULL << fxParser::Float)
      | (1ULL << fxParser::Int)
      | (1ULL << fxParser::Void)
      | (1ULL << fxParser::Bool))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

fxParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* fxParser::CompoundStatementContext::LeftBrace() {
  return getToken(fxParser::LeftBrace, 0);
}

tree::TerminalNode* fxParser::CompoundStatementContext::RightBrace() {
  return getToken(fxParser::RightBrace, 0);
}

fxParser::StatementsContext* fxParser::CompoundStatementContext::statements() {
  return getRuleContext<fxParser::StatementsContext>(0);
}


size_t fxParser::CompoundStatementContext::getRuleIndex() const {
  return fxParser::RuleCompoundStatement;
}

void fxParser::CompoundStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompoundStatement(this);
}

void fxParser::CompoundStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompoundStatement(this);
}


antlrcpp::Any fxParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

fxParser::CompoundStatementContext* fxParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, fxParser::RuleCompoundStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(fxParser::LeftBrace);
    setState(96);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 14) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 14)) & ((1ULL << (fxParser::If - 14))
      | (1ULL << (fxParser::Return - 14))
      | (1ULL << (fxParser::Identifier - 14)))) != 0)) {
      setState(95);
      statements();
    }
    setState(98);
    match(fxParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

fxParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

fxParser::If_statementContext* fxParser::StatementContext::if_statement() {
  return getRuleContext<fxParser::If_statementContext>(0);
}

fxParser::Assignment_expressionContext* fxParser::StatementContext::assignment_expression() {
  return getRuleContext<fxParser::Assignment_expressionContext>(0);
}

fxParser::Return_statementContext* fxParser::StatementContext::return_statement() {
  return getRuleContext<fxParser::Return_statementContext>(0);
}


size_t fxParser::StatementContext::getRuleIndex() const {
  return fxParser::RuleStatement;
}

void fxParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void fxParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any fxParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

fxParser::StatementContext* fxParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 24, fxParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(103);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case fxParser::If: {
        enterOuterAlt(_localctx, 1);
        setState(100);
        if_statement();
        break;
      }

      case fxParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(101);
        assignment_expression();
        break;
      }

      case fxParser::Return: {
        enterOuterAlt(_localctx, 3);
        setState(102);
        return_statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statementContext ------------------------------------------------------------------

fxParser::If_statementContext::If_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* fxParser::If_statementContext::If() {
  return getToken(fxParser::If, 0);
}

tree::TerminalNode* fxParser::If_statementContext::LeftParen() {
  return getToken(fxParser::LeftParen, 0);
}

fxParser::Cond_expressionContext* fxParser::If_statementContext::cond_expression() {
  return getRuleContext<fxParser::Cond_expressionContext>(0);
}

tree::TerminalNode* fxParser::If_statementContext::RightParen() {
  return getToken(fxParser::RightParen, 0);
}

fxParser::CompoundStatementContext* fxParser::If_statementContext::compoundStatement() {
  return getRuleContext<fxParser::CompoundStatementContext>(0);
}

fxParser::Else_clauseContext* fxParser::If_statementContext::else_clause() {
  return getRuleContext<fxParser::Else_clauseContext>(0);
}


size_t fxParser::If_statementContext::getRuleIndex() const {
  return fxParser::RuleIf_statement;
}

void fxParser::If_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_statement(this);
}

void fxParser::If_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_statement(this);
}


antlrcpp::Any fxParser::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}

fxParser::If_statementContext* fxParser::if_statement() {
  If_statementContext *_localctx = _tracker.createInstance<If_statementContext>(_ctx, getState());
  enterRule(_localctx, 26, fxParser::RuleIf_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(fxParser::If);
    setState(106);
    match(fxParser::LeftParen);
    setState(107);
    cond_expression();
    setState(108);
    match(fxParser::RightParen);
    setState(109);
    compoundStatement();
    setState(111);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == fxParser::Else) {
      setState(110);
      else_clause();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_clauseContext ------------------------------------------------------------------

fxParser::Else_clauseContext::Else_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* fxParser::Else_clauseContext::Else() {
  return getToken(fxParser::Else, 0);
}

fxParser::CompoundStatementContext* fxParser::Else_clauseContext::compoundStatement() {
  return getRuleContext<fxParser::CompoundStatementContext>(0);
}

fxParser::If_statementContext* fxParser::Else_clauseContext::if_statement() {
  return getRuleContext<fxParser::If_statementContext>(0);
}


size_t fxParser::Else_clauseContext::getRuleIndex() const {
  return fxParser::RuleElse_clause;
}

void fxParser::Else_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElse_clause(this);
}

void fxParser::Else_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElse_clause(this);
}


antlrcpp::Any fxParser::Else_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitElse_clause(this);
  else
    return visitor->visitChildren(this);
}

fxParser::Else_clauseContext* fxParser::else_clause() {
  Else_clauseContext *_localctx = _tracker.createInstance<Else_clauseContext>(_ctx, getState());
  enterRule(_localctx, 28, fxParser::RuleElse_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(117);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(113);
      match(fxParser::Else);
      setState(114);
      compoundStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(115);
      match(fxParser::Else);
      setState(116);
      if_statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cond_expressionContext ------------------------------------------------------------------

fxParser::Cond_expressionContext::Cond_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

fxParser::Binary_expressionContext* fxParser::Cond_expressionContext::binary_expression() {
  return getRuleContext<fxParser::Binary_expressionContext>(0);
}


size_t fxParser::Cond_expressionContext::getRuleIndex() const {
  return fxParser::RuleCond_expression;
}

void fxParser::Cond_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond_expression(this);
}

void fxParser::Cond_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond_expression(this);
}


antlrcpp::Any fxParser::Cond_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitCond_expression(this);
  else
    return visitor->visitChildren(this);
}

fxParser::Cond_expressionContext* fxParser::cond_expression() {
  Cond_expressionContext *_localctx = _tracker.createInstance<Cond_expressionContext>(_ctx, getState());
  enterRule(_localctx, 30, fxParser::RuleCond_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    binary_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binary_expressionContext ------------------------------------------------------------------

fxParser::Binary_expressionContext::Binary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<fxParser::ExpressionContext *> fxParser::Binary_expressionContext::expression() {
  return getRuleContexts<fxParser::ExpressionContext>();
}

fxParser::ExpressionContext* fxParser::Binary_expressionContext::expression(size_t i) {
  return getRuleContext<fxParser::ExpressionContext>(i);
}

fxParser::Binary_compareContext* fxParser::Binary_expressionContext::binary_compare() {
  return getRuleContext<fxParser::Binary_compareContext>(0);
}


size_t fxParser::Binary_expressionContext::getRuleIndex() const {
  return fxParser::RuleBinary_expression;
}

void fxParser::Binary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary_expression(this);
}

void fxParser::Binary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary_expression(this);
}


antlrcpp::Any fxParser::Binary_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitBinary_expression(this);
  else
    return visitor->visitChildren(this);
}

fxParser::Binary_expressionContext* fxParser::binary_expression() {
  Binary_expressionContext *_localctx = _tracker.createInstance<Binary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, fxParser::RuleBinary_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    expression();
    setState(122);
    binary_compare();
    setState(123);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binary_compareContext ------------------------------------------------------------------

fxParser::Binary_compareContext::Binary_compareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* fxParser::Binary_compareContext::Equal() {
  return getToken(fxParser::Equal, 0);
}

tree::TerminalNode* fxParser::Binary_compareContext::NotEqual() {
  return getToken(fxParser::NotEqual, 0);
}

tree::TerminalNode* fxParser::Binary_compareContext::Greater() {
  return getToken(fxParser::Greater, 0);
}

tree::TerminalNode* fxParser::Binary_compareContext::GreaterEqual() {
  return getToken(fxParser::GreaterEqual, 0);
}

tree::TerminalNode* fxParser::Binary_compareContext::Less() {
  return getToken(fxParser::Less, 0);
}

tree::TerminalNode* fxParser::Binary_compareContext::LessEqual() {
  return getToken(fxParser::LessEqual, 0);
}


size_t fxParser::Binary_compareContext::getRuleIndex() const {
  return fxParser::RuleBinary_compare;
}

void fxParser::Binary_compareContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary_compare(this);
}

void fxParser::Binary_compareContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary_compare(this);
}


antlrcpp::Any fxParser::Binary_compareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitBinary_compare(this);
  else
    return visitor->visitChildren(this);
}

fxParser::Binary_compareContext* fxParser::binary_compare() {
  Binary_compareContext *_localctx = _tracker.createInstance<Binary_compareContext>(_ctx, getState());
  enterRule(_localctx, 34, fxParser::RuleBinary_compare);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    _la = _input->LA(1);
    if (!(((((_la - 29) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 29)) & ((1ULL << (fxParser::Less - 29))
      | (1ULL << (fxParser::LessEqual - 29))
      | (1ULL << (fxParser::Greater - 29))
      | (1ULL << (fxParser::GreaterEqual - 29))
      | (1ULL << (fxParser::Equal - 29))
      | (1ULL << (fxParser::NotEqual - 29)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statementContext ------------------------------------------------------------------

fxParser::Return_statementContext::Return_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* fxParser::Return_statementContext::Return() {
  return getToken(fxParser::Return, 0);
}

fxParser::ExpressionContext* fxParser::Return_statementContext::expression() {
  return getRuleContext<fxParser::ExpressionContext>(0);
}


size_t fxParser::Return_statementContext::getRuleIndex() const {
  return fxParser::RuleReturn_statement;
}

void fxParser::Return_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_statement(this);
}

void fxParser::Return_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_statement(this);
}


antlrcpp::Any fxParser::Return_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitReturn_statement(this);
  else
    return visitor->visitChildren(this);
}

fxParser::Return_statementContext* fxParser::return_statement() {
  Return_statementContext *_localctx = _tracker.createInstance<Return_statementContext>(_ctx, getState());
  enterRule(_localctx, 36, fxParser::RuleReturn_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(fxParser::Return);
    setState(128);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

fxParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* fxParser::ExpressionContext::Identifier() {
  return getToken(fxParser::Identifier, 0);
}

tree::TerminalNode* fxParser::ExpressionContext::Constant() {
  return getToken(fxParser::Constant, 0);
}


size_t fxParser::ExpressionContext::getRuleIndex() const {
  return fxParser::RuleExpression;
}

void fxParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void fxParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any fxParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

fxParser::ExpressionContext* fxParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 38, fxParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    _la = _input->LA(1);
    if (!(_la == fxParser::Identifier

    || _la == fxParser::Constant)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

fxParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<fxParser::StatementContext *> fxParser::StatementsContext::statement() {
  return getRuleContexts<fxParser::StatementContext>();
}

fxParser::StatementContext* fxParser::StatementsContext::statement(size_t i) {
  return getRuleContext<fxParser::StatementContext>(i);
}


size_t fxParser::StatementsContext::getRuleIndex() const {
  return fxParser::RuleStatements;
}

void fxParser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void fxParser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


antlrcpp::Any fxParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

fxParser::StatementsContext* fxParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 40, fxParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(132);
      statement();
      setState(135); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 14) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 14)) & ((1ULL << (fxParser::If - 14))
      | (1ULL << (fxParser::Return - 14))
      | (1ULL << (fxParser::Identifier - 14)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignment_expressionContext ------------------------------------------------------------------

fxParser::Assignment_expressionContext::Assignment_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> fxParser::Assignment_expressionContext::Identifier() {
  return getTokens(fxParser::Identifier);
}

tree::TerminalNode* fxParser::Assignment_expressionContext::Identifier(size_t i) {
  return getToken(fxParser::Identifier, i);
}

fxParser::AssignmentOperatorContext* fxParser::Assignment_expressionContext::assignmentOperator() {
  return getRuleContext<fxParser::AssignmentOperatorContext>(0);
}


size_t fxParser::Assignment_expressionContext::getRuleIndex() const {
  return fxParser::RuleAssignment_expression;
}

void fxParser::Assignment_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_expression(this);
}

void fxParser::Assignment_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_expression(this);
}


antlrcpp::Any fxParser::Assignment_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitAssignment_expression(this);
  else
    return visitor->visitChildren(this);
}

fxParser::Assignment_expressionContext* fxParser::assignment_expression() {
  Assignment_expressionContext *_localctx = _tracker.createInstance<Assignment_expressionContext>(_ctx, getState());
  enterRule(_localctx, 42, fxParser::RuleAssignment_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(fxParser::Identifier);
    setState(138);
    assignmentOperator();
    setState(139);
    match(fxParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> fxParser::_decisionToDFA;
atn::PredictionContextCache fxParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN fxParser::_atn;
std::vector<uint16_t> fxParser::_serializedATN;

std::vector<std::string> fxParser::_ruleNames = {
  "compilationUnit", "translationUnit", "externalDeclaration", "functionDefinition", 
  "declarationSpecifiers", "declarationSpecifier", "parameterList", "parameterDeclaration", 
  "identifierList", "assignmentOperator", "typeSpecifier", "compoundStatement", 
  "statement", "if_statement", "else_clause", "cond_expression", "binary_expression", 
  "binary_compare", "return_statement", "expression", "statements", "assignment_expression"
};

std::vector<std::string> fxParser::_literalNames = {
  "", "'def'", "'str'", "'break'", "'case'", "'char'", "'const'", "'continue'", 
  "'default'", "'do'", "'else'", "'enum'", "'float'", "'for'", "'if'", "'inline'", 
  "'int'", "'return'", "'struct'", "'switch'", "'void'", "'while'", "'bool'", 
  "'('", "')'", "'['", "']'", "'{'", "'}'", "'<'", "'<='", "'>'", "'>='", 
  "'<<'", "'>>'", "'+'", "'++'", "'-'", "'--'", "'*'", "'/'", "'%'", "'&'", 
  "'|'", "'&&'", "'||'", "'^'", "'!'", "'~'", "'?'", "':'", "';'", "','", 
  "'='", "'*='", "'/='", "'%='", "'+='", "'-='", "'<<='", "'>>='", "'&='", 
  "'^='", "'|='", "'=='", "'!='", "'->'", "'.'"
};

std::vector<std::string> fxParser::_symbolicNames = {
  "", "", "", "Break", "Case", "Char", "Const", "Continue", "Default", "Do", 
  "Else", "Enum", "Float", "For", "If", "Inline", "Int", "Return", "Struct", 
  "Switch", "Void", "While", "Bool", "LeftParen", "RightParen", "LeftBracket", 
  "RightBracket", "LeftBrace", "RightBrace", "Less", "LessEqual", "Greater", 
  "GreaterEqual", "LeftShift", "RightShift", "Plus", "PlusPlus", "Minus", 
  "MinusMinus", "Star", "Div", "Mod", "And", "Or", "AndAnd", "OrOr", "Caret", 
  "Not", "Tilde", "Question", "Colon", "Semi", "Comma", "Assign", "StarAssign", 
  "DivAssign", "ModAssign", "PlusAssign", "MinusAssign", "LeftShiftAssign", 
  "RightShiftAssign", "AndAssign", "XorAssign", "OrAssign", "Equal", "NotEqual", 
  "Arrow", "Dot", "Identifier", "Constant", "DigitSequence", "Whitespace", 
  "Newline", "BlockComment", "LineComment"
};

dfa::Vocabulary fxParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> fxParser::_tokenNames;

fxParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x4c, 0x90, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x3, 0x2, 0x5, 0x2, 
    0x30, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x6, 0x3, 0x35, 0xa, 0x3, 
    0xd, 0x3, 0xe, 0x3, 0x36, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x6, 
    0x6, 0x44, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x45, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x4d, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 
    0x50, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x7, 0xa, 0x58, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x5b, 0xb, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x63, 
    0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 
    0x6a, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x5, 0xf, 0x72, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x5, 0x10, 0x78, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x6, 0x16, 0x88, 0xa, 0x16, 
    0xd, 0x16, 0xe, 0x16, 0x89, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x2, 0x2, 0x18, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2c, 0x2, 0x6, 0x3, 0x2, 0x37, 0x41, 0x8, 0x2, 0x4, 0x4, 0x7, 
    0x7, 0xe, 0xe, 0x12, 0x12, 0x16, 0x16, 0x18, 0x18, 0x4, 0x2, 0x1f, 0x22, 
    0x42, 0x43, 0x3, 0x2, 0x46, 0x47, 0x2, 0x84, 0x2, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x34, 0x3, 0x2, 0x2, 0x2, 0x6, 0x38, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x3a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x43, 0x3, 0x2, 0x2, 0x2, 0xc, 0x47, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x49, 0x3, 0x2, 0x2, 0x2, 0x10, 0x51, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x54, 0x3, 0x2, 0x2, 0x2, 0x14, 0x5c, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x18, 0x60, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x77, 0x3, 0x2, 0x2, 0x2, 0x20, 0x79, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x7b, 0x3, 0x2, 0x2, 0x2, 0x24, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x26, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x84, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x4, 
    0x3, 0x2, 0x2f, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 
    0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0x2, 0x2, 0x3, 
    0x32, 0x3, 0x3, 0x2, 0x2, 0x2, 0x33, 0x35, 0x5, 0x6, 0x4, 0x2, 0x34, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x34, 
    0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x39, 0x5, 0x8, 0x5, 0x2, 0x39, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x3b, 0x7, 0x3, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x46, 0x2, 
    0x2, 0x3c, 0x3d, 0x7, 0x19, 0x2, 0x2, 0x3d, 0x3e, 0x5, 0xe, 0x8, 0x2, 
    0x3e, 0x3f, 0x7, 0x1a, 0x2, 0x2, 0x3f, 0x40, 0x5, 0x16, 0xc, 0x2, 0x40, 
    0x41, 0x5, 0x18, 0xd, 0x2, 0x41, 0x9, 0x3, 0x2, 0x2, 0x2, 0x42, 0x44, 
    0x5, 0xc, 0x7, 0x2, 0x43, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 
    0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0xb, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x5, 0x16, 0xc, 
    0x2, 0x48, 0xd, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4e, 0x5, 0x10, 0x9, 0x2, 
    0x4a, 0x4b, 0x7, 0x36, 0x2, 0x2, 0x4b, 0x4d, 0x5, 0x10, 0x9, 0x2, 0x4c, 
    0x4a, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x5, 0xa, 
    0x6, 0x2, 0x52, 0x53, 0x7, 0x46, 0x2, 0x2, 0x53, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x59, 0x7, 0x46, 0x2, 0x2, 0x55, 0x56, 0x7, 0x36, 0x2, 0x2, 
    0x56, 0x58, 0x7, 0x46, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 
    0x3, 0x2, 0x2, 0x2, 0x5a, 0x13, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x5d, 0x9, 0x2, 0x2, 0x2, 0x5d, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x5f, 0x9, 0x3, 0x2, 0x2, 0x5f, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x62, 0x7, 0x1d, 0x2, 0x2, 0x61, 0x63, 0x5, 0x2a, 0x16, 0x2, 
    0x62, 0x61, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x7, 0x1e, 0x2, 0x2, 0x65, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x66, 0x6a, 0x5, 0x1c, 0xf, 0x2, 0x67, 0x6a, 0x5, 
    0x2c, 0x17, 0x2, 0x68, 0x6a, 0x5, 0x26, 0x14, 0x2, 0x69, 0x66, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x68, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x10, 0x2, 
    0x2, 0x6c, 0x6d, 0x7, 0x19, 0x2, 0x2, 0x6d, 0x6e, 0x5, 0x20, 0x11, 0x2, 
    0x6e, 0x6f, 0x7, 0x1a, 0x2, 0x2, 0x6f, 0x71, 0x5, 0x18, 0xd, 0x2, 0x70, 
    0x72, 0x5, 0x1e, 0x10, 0x2, 0x71, 0x70, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 
    0xc, 0x2, 0x2, 0x74, 0x78, 0x5, 0x18, 0xd, 0x2, 0x75, 0x76, 0x7, 0xc, 
    0x2, 0x2, 0x76, 0x78, 0x5, 0x1c, 0xf, 0x2, 0x77, 0x73, 0x3, 0x2, 0x2, 
    0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x78, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0x79, 0x7a, 0x5, 0x22, 0x12, 0x2, 0x7a, 0x21, 0x3, 0x2, 0x2, 0x2, 0x7b, 
    0x7c, 0x5, 0x28, 0x15, 0x2, 0x7c, 0x7d, 0x5, 0x24, 0x13, 0x2, 0x7d, 
    0x7e, 0x5, 0x28, 0x15, 0x2, 0x7e, 0x23, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 
    0x9, 0x4, 0x2, 0x2, 0x80, 0x25, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x7, 
    0x13, 0x2, 0x2, 0x82, 0x83, 0x5, 0x28, 0x15, 0x2, 0x83, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x84, 0x85, 0x9, 0x5, 0x2, 0x2, 0x85, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0x86, 0x88, 0x5, 0x1a, 0xe, 0x2, 0x87, 0x86, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 
    0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 
    0x7, 0x46, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x14, 0xb, 0x2, 0x8d, 0x8e, 0x7, 
    0x46, 0x2, 0x2, 0x8e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x2f, 0x36, 0x45, 
    0x4e, 0x59, 0x62, 0x69, 0x71, 0x77, 0x89, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

fxParser::Initializer fxParser::_init;
