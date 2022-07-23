
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


//----------------- ProgramContext ------------------------------------------------------------------

fxParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<fxParser::TopDefContext *> fxParser::ProgramContext::topDef() {
  return getRuleContexts<fxParser::TopDefContext>();
}

fxParser::TopDefContext* fxParser::ProgramContext::topDef(size_t i) {
  return getRuleContext<fxParser::TopDefContext>(i);
}


size_t fxParser::ProgramContext::getRuleIndex() const {
  return fxParser::RuleProgram;
}

void fxParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void fxParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any fxParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

fxParser::ProgramContext* fxParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, fxParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(30);
      topDef();
      setState(33); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__2)
      | (1ULL << fxParser::T__15)
      | (1ULL << fxParser::T__16)
      | (1ULL << fxParser::T__17)
      | (1ULL << fxParser::T__18)
      | (1ULL << fxParser::ID))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TopDefContext ------------------------------------------------------------------

fxParser::TopDefContext::TopDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

fxParser::FuncDefContext* fxParser::TopDefContext::funcDef() {
  return getRuleContext<fxParser::FuncDefContext>(0);
}

fxParser::ClassDefContext* fxParser::TopDefContext::classDef() {
  return getRuleContext<fxParser::ClassDefContext>(0);
}


size_t fxParser::TopDefContext::getRuleIndex() const {
  return fxParser::RuleTopDef;
}

void fxParser::TopDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTopDef(this);
}

void fxParser::TopDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTopDef(this);
}


antlrcpp::Any fxParser::TopDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitTopDef(this);
  else
    return visitor->visitChildren(this);
}

fxParser::TopDefContext* fxParser::topDef() {
  TopDefContext *_localctx = _tracker.createInstance<TopDefContext>(_ctx, getState());
  enterRule(_localctx, 2, fxParser::RuleTopDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(37);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case fxParser::T__15:
      case fxParser::T__16:
      case fxParser::T__17:
      case fxParser::T__18:
      case fxParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(35);
        funcDef();
        break;
      }

      case fxParser::T__2: {
        enterOuterAlt(_localctx, 2);
        setState(36);
        classDef();
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

//----------------- FuncDefContext ------------------------------------------------------------------

fxParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

fxParser::Type_Context* fxParser::FuncDefContext::type_() {
  return getRuleContext<fxParser::Type_Context>(0);
}

tree::TerminalNode* fxParser::FuncDefContext::ID() {
  return getToken(fxParser::ID, 0);
}

fxParser::BlockContext* fxParser::FuncDefContext::block() {
  return getRuleContext<fxParser::BlockContext>(0);
}

fxParser::ArgContext* fxParser::FuncDefContext::arg() {
  return getRuleContext<fxParser::ArgContext>(0);
}


size_t fxParser::FuncDefContext::getRuleIndex() const {
  return fxParser::RuleFuncDef;
}

void fxParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void fxParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}


antlrcpp::Any fxParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

fxParser::FuncDefContext* fxParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 4, fxParser::RuleFuncDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(39);
    type_();
    setState(40);
    match(fxParser::ID);
    setState(41);
    match(fxParser::T__0);
    setState(43);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__15)
      | (1ULL << fxParser::T__16)
      | (1ULL << fxParser::T__17)
      | (1ULL << fxParser::T__18)
      | (1ULL << fxParser::ID))) != 0)) {
      setState(42);
      arg();
    }
    setState(45);
    match(fxParser::T__1);
    setState(46);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDefContext ------------------------------------------------------------------

fxParser::ClassDefContext::ClassDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> fxParser::ClassDefContext::ID() {
  return getTokens(fxParser::ID);
}

tree::TerminalNode* fxParser::ClassDefContext::ID(size_t i) {
  return getToken(fxParser::ID, i);
}

std::vector<fxParser::ClassItemContext *> fxParser::ClassDefContext::classItem() {
  return getRuleContexts<fxParser::ClassItemContext>();
}

fxParser::ClassItemContext* fxParser::ClassDefContext::classItem(size_t i) {
  return getRuleContext<fxParser::ClassItemContext>(i);
}


size_t fxParser::ClassDefContext::getRuleIndex() const {
  return fxParser::RuleClassDef;
}

void fxParser::ClassDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDef(this);
}

void fxParser::ClassDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDef(this);
}


antlrcpp::Any fxParser::ClassDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitClassDef(this);
  else
    return visitor->visitChildren(this);
}

fxParser::ClassDefContext* fxParser::classDef() {
  ClassDefContext *_localctx = _tracker.createInstance<ClassDefContext>(_ctx, getState());
  enterRule(_localctx, 6, fxParser::RuleClassDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(fxParser::T__2);
    setState(49);
    match(fxParser::ID);
    setState(52);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == fxParser::T__3) {
      setState(50);
      match(fxParser::T__3);
      setState(51);
      match(fxParser::ID);
    }
    setState(54);
    match(fxParser::T__4);
    setState(58);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__15)
      | (1ULL << fxParser::T__16)
      | (1ULL << fxParser::T__17)
      | (1ULL << fxParser::T__18)
      | (1ULL << fxParser::ID))) != 0)) {
      setState(55);
      classItem();
      setState(60);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(61);
    match(fxParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassItemContext ------------------------------------------------------------------

fxParser::ClassItemContext::ClassItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t fxParser::ClassItemContext::getRuleIndex() const {
  return fxParser::RuleClassItem;
}

void fxParser::ClassItemContext::copyFrom(ClassItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FieldDeclContext ------------------------------------------------------------------

fxParser::Type_Context* fxParser::FieldDeclContext::type_() {
  return getRuleContext<fxParser::Type_Context>(0);
}

tree::TerminalNode* fxParser::FieldDeclContext::ID() {
  return getToken(fxParser::ID, 0);
}

fxParser::FieldDeclContext::FieldDeclContext(ClassItemContext *ctx) { copyFrom(ctx); }

void fxParser::FieldDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFieldDecl(this);
}
void fxParser::FieldDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFieldDecl(this);
}

antlrcpp::Any fxParser::FieldDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitFieldDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MethodDefContext ------------------------------------------------------------------

fxParser::Type_Context* fxParser::MethodDefContext::type_() {
  return getRuleContext<fxParser::Type_Context>(0);
}

tree::TerminalNode* fxParser::MethodDefContext::ID() {
  return getToken(fxParser::ID, 0);
}

fxParser::BlockContext* fxParser::MethodDefContext::block() {
  return getRuleContext<fxParser::BlockContext>(0);
}

fxParser::ArgContext* fxParser::MethodDefContext::arg() {
  return getRuleContext<fxParser::ArgContext>(0);
}

fxParser::MethodDefContext::MethodDefContext(ClassItemContext *ctx) { copyFrom(ctx); }

void fxParser::MethodDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodDef(this);
}
void fxParser::MethodDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodDef(this);
}

antlrcpp::Any fxParser::MethodDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitMethodDef(this);
  else
    return visitor->visitChildren(this);
}
fxParser::ClassItemContext* fxParser::classItem() {
  ClassItemContext *_localctx = _tracker.createInstance<ClassItemContext>(_ctx, getState());
  enterRule(_localctx, 8, fxParser::RuleClassItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ClassItemContext *>(_tracker.createInstance<fxParser::FieldDeclContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(63);
      type_();
      setState(64);
      match(fxParser::ID);
      setState(65);
      match(fxParser::T__6);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ClassItemContext *>(_tracker.createInstance<fxParser::MethodDefContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(67);
      type_();
      setState(68);
      match(fxParser::ID);
      setState(69);
      match(fxParser::T__0);
      setState(71);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << fxParser::T__15)
        | (1ULL << fxParser::T__16)
        | (1ULL << fxParser::T__17)
        | (1ULL << fxParser::T__18)
        | (1ULL << fxParser::ID))) != 0)) {
        setState(70);
        arg();
      }
      setState(73);
      match(fxParser::T__1);
      setState(74);
      block();
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

//----------------- ArgContext ------------------------------------------------------------------

fxParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<fxParser::VarDefContext *> fxParser::ArgContext::varDef() {
  return getRuleContexts<fxParser::VarDefContext>();
}

fxParser::VarDefContext* fxParser::ArgContext::varDef(size_t i) {
  return getRuleContext<fxParser::VarDefContext>(i);
}


size_t fxParser::ArgContext::getRuleIndex() const {
  return fxParser::RuleArg;
}

void fxParser::ArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArg(this);
}

void fxParser::ArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArg(this);
}


antlrcpp::Any fxParser::ArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitArg(this);
  else
    return visitor->visitChildren(this);
}

fxParser::ArgContext* fxParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 10, fxParser::RuleArg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    varDef();
    setState(83);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == fxParser::T__7) {
      setState(79);
      match(fxParser::T__7);
      setState(80);
      varDef();
      setState(85);
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

//----------------- VarDefContext ------------------------------------------------------------------

fxParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

fxParser::Type_Context* fxParser::VarDefContext::type_() {
  return getRuleContext<fxParser::Type_Context>(0);
}

tree::TerminalNode* fxParser::VarDefContext::ID() {
  return getToken(fxParser::ID, 0);
}


size_t fxParser::VarDefContext::getRuleIndex() const {
  return fxParser::RuleVarDef;
}

void fxParser::VarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDef(this);
}

void fxParser::VarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDef(this);
}


antlrcpp::Any fxParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

fxParser::VarDefContext* fxParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 12, fxParser::RuleVarDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    type_();
    setState(87);
    match(fxParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

fxParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<fxParser::StmtContext *> fxParser::BlockContext::stmt() {
  return getRuleContexts<fxParser::StmtContext>();
}

fxParser::StmtContext* fxParser::BlockContext::stmt(size_t i) {
  return getRuleContext<fxParser::StmtContext>(i);
}


size_t fxParser::BlockContext::getRuleIndex() const {
  return fxParser::RuleBlock;
}

void fxParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void fxParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any fxParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

fxParser::BlockContext* fxParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 14, fxParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    match(fxParser::T__4);
    setState(93);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__0)
      | (1ULL << fxParser::T__4)
      | (1ULL << fxParser::T__6)
      | (1ULL << fxParser::T__11)
      | (1ULL << fxParser::T__12)
      | (1ULL << fxParser::T__14)
      | (1ULL << fxParser::T__15)
      | (1ULL << fxParser::T__16)
      | (1ULL << fxParser::T__17)
      | (1ULL << fxParser::T__18)
      | (1ULL << fxParser::T__20)
      | (1ULL << fxParser::T__21)
      | (1ULL << fxParser::T__24)
      | (1ULL << fxParser::T__25)
      | (1ULL << fxParser::T__26)
      | (1ULL << fxParser::T__27)
      | (1ULL << fxParser::INT)
      | (1ULL << fxParser::ID)
      | (1ULL << fxParser::STR))) != 0)) {
      setState(90);
      stmt();
      setState(95);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(96);
    match(fxParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

fxParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t fxParser::StmtContext::getRuleIndex() const {
  return fxParser::RuleStmt;
}

void fxParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AssContext ------------------------------------------------------------------

std::vector<fxParser::ExprContext *> fxParser::AssContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::AssContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::AssContext::AssContext(StmtContext *ctx) { copyFrom(ctx); }

void fxParser::AssContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAss(this);
}
void fxParser::AssContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAss(this);
}

antlrcpp::Any fxParser::AssContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitAss(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DecrContext ------------------------------------------------------------------

fxParser::ExprContext* fxParser::DecrContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

fxParser::DecrContext::DecrContext(StmtContext *ctx) { copyFrom(ctx); }

void fxParser::DecrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecr(this);
}
void fxParser::DecrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecr(this);
}

antlrcpp::Any fxParser::DecrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitDecr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RetContext ------------------------------------------------------------------

fxParser::ExprContext* fxParser::RetContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

fxParser::RetContext::RetContext(StmtContext *ctx) { copyFrom(ctx); }

void fxParser::RetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRet(this);
}
void fxParser::RetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRet(this);
}

antlrcpp::Any fxParser::RetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitRet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EmptyContext ------------------------------------------------------------------

fxParser::EmptyContext::EmptyContext(StmtContext *ctx) { copyFrom(ctx); }

void fxParser::EmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmpty(this);
}
void fxParser::EmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmpty(this);
}

antlrcpp::Any fxParser::EmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEmpty(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CondContext ------------------------------------------------------------------

fxParser::ExprContext* fxParser::CondContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

fxParser::StmtContext* fxParser::CondContext::stmt() {
  return getRuleContext<fxParser::StmtContext>(0);
}

fxParser::CondContext::CondContext(StmtContext *ctx) { copyFrom(ctx); }

void fxParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}
void fxParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}

antlrcpp::Any fxParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CondElseContext ------------------------------------------------------------------

fxParser::ExprContext* fxParser::CondElseContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

std::vector<fxParser::StmtContext *> fxParser::CondElseContext::stmt() {
  return getRuleContexts<fxParser::StmtContext>();
}

fxParser::StmtContext* fxParser::CondElseContext::stmt(size_t i) {
  return getRuleContext<fxParser::StmtContext>(i);
}

fxParser::CondElseContext::CondElseContext(StmtContext *ctx) { copyFrom(ctx); }

void fxParser::CondElseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondElse(this);
}
void fxParser::CondElseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondElse(this);
}

antlrcpp::Any fxParser::CondElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitCondElse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VRetContext ------------------------------------------------------------------

fxParser::VRetContext::VRetContext(StmtContext *ctx) { copyFrom(ctx); }

void fxParser::VRetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVRet(this);
}
void fxParser::VRetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVRet(this);
}

antlrcpp::Any fxParser::VRetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitVRet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IncrContext ------------------------------------------------------------------

fxParser::ExprContext* fxParser::IncrContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

fxParser::IncrContext::IncrContext(StmtContext *ctx) { copyFrom(ctx); }

void fxParser::IncrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIncr(this);
}
void fxParser::IncrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIncr(this);
}

antlrcpp::Any fxParser::IncrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitIncr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlockStmtContext ------------------------------------------------------------------

fxParser::BlockContext* fxParser::BlockStmtContext::block() {
  return getRuleContext<fxParser::BlockContext>(0);
}

fxParser::BlockStmtContext::BlockStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void fxParser::BlockStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStmt(this);
}
void fxParser::BlockStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStmt(this);
}

antlrcpp::Any fxParser::BlockStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitBlockStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclContext ------------------------------------------------------------------

fxParser::Type_Context* fxParser::DeclContext::type_() {
  return getRuleContext<fxParser::Type_Context>(0);
}

std::vector<fxParser::ItemContext *> fxParser::DeclContext::item() {
  return getRuleContexts<fxParser::ItemContext>();
}

fxParser::ItemContext* fxParser::DeclContext::item(size_t i) {
  return getRuleContext<fxParser::ItemContext>(i);
}

fxParser::DeclContext::DeclContext(StmtContext *ctx) { copyFrom(ctx); }

void fxParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}
void fxParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}

antlrcpp::Any fxParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileContext ------------------------------------------------------------------

fxParser::ExprContext* fxParser::WhileContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

fxParser::StmtContext* fxParser::WhileContext::stmt() {
  return getRuleContext<fxParser::StmtContext>(0);
}

fxParser::WhileContext::WhileContext(StmtContext *ctx) { copyFrom(ctx); }

void fxParser::WhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile(this);
}
void fxParser::WhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile(this);
}

antlrcpp::Any fxParser::WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SExpContext ------------------------------------------------------------------

fxParser::ExprContext* fxParser::SExpContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

fxParser::SExpContext::SExpContext(StmtContext *ctx) { copyFrom(ctx); }

void fxParser::SExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSExp(this);
}
void fxParser::SExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSExp(this);
}

antlrcpp::Any fxParser::SExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitSExp(this);
  else
    return visitor->visitChildren(this);
}
fxParser::StmtContext* fxParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 16, fxParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(153);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<fxParser::EmptyContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(98);
      match(fxParser::T__6);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<fxParser::BlockStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(99);
      block();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<fxParser::DeclContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(100);
      type_();
      setState(101);
      item();
      setState(106);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == fxParser::T__7) {
        setState(102);
        match(fxParser::T__7);
        setState(103);
        item();
        setState(108);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(109);
      match(fxParser::T__6);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<fxParser::AssContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(111);
      expr(0);
      setState(112);
      match(fxParser::T__8);
      setState(113);
      expr(0);
      setState(114);
      match(fxParser::T__6);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<fxParser::IncrContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(116);
      expr(0);
      setState(117);
      match(fxParser::T__9);
      setState(118);
      match(fxParser::T__6);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<fxParser::DecrContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(120);
      expr(0);
      setState(121);
      match(fxParser::T__10);
      setState(122);
      match(fxParser::T__6);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<fxParser::RetContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(124);
      match(fxParser::T__11);
      setState(125);
      expr(0);
      setState(126);
      match(fxParser::T__6);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<fxParser::VRetContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(128);
      match(fxParser::T__11);
      setState(129);
      match(fxParser::T__6);
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<fxParser::CondContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(130);
      match(fxParser::T__12);
      setState(131);
      match(fxParser::T__0);
      setState(132);
      expr(0);
      setState(133);
      match(fxParser::T__1);
      setState(134);
      stmt();
      break;
    }

    case 10: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<fxParser::CondElseContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(136);
      match(fxParser::T__12);
      setState(137);
      match(fxParser::T__0);
      setState(138);
      expr(0);
      setState(139);
      match(fxParser::T__1);
      setState(140);
      stmt();
      setState(141);
      match(fxParser::T__13);
      setState(142);
      stmt();
      break;
    }

    case 11: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<fxParser::WhileContext>(_localctx));
      enterOuterAlt(_localctx, 11);
      setState(144);
      match(fxParser::T__14);
      setState(145);
      match(fxParser::T__0);
      setState(146);
      expr(0);
      setState(147);
      match(fxParser::T__1);
      setState(148);
      stmt();
      break;
    }

    case 12: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<fxParser::SExpContext>(_localctx));
      enterOuterAlt(_localctx, 12);
      setState(150);
      expr(0);
      setState(151);
      match(fxParser::T__6);
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

//----------------- Type_Context ------------------------------------------------------------------

fxParser::Type_Context::Type_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t fxParser::Type_Context::getRuleIndex() const {
  return fxParser::RuleType_;
}

void fxParser::Type_Context::copyFrom(Type_Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StrContext ------------------------------------------------------------------

fxParser::StrContext::StrContext(Type_Context *ctx) { copyFrom(ctx); }

void fxParser::StrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStr(this);
}
void fxParser::StrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStr(this);
}

antlrcpp::Any fxParser::StrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitStr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolContext ------------------------------------------------------------------

fxParser::BoolContext::BoolContext(Type_Context *ctx) { copyFrom(ctx); }

void fxParser::BoolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBool(this);
}
void fxParser::BoolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBool(this);
}

antlrcpp::Any fxParser::BoolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitBool(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassNameContext ------------------------------------------------------------------

tree::TerminalNode* fxParser::ClassNameContext::ID() {
  return getToken(fxParser::ID, 0);
}

fxParser::ClassNameContext::ClassNameContext(Type_Context *ctx) { copyFrom(ctx); }

void fxParser::ClassNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassName(this);
}
void fxParser::ClassNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassName(this);
}

antlrcpp::Any fxParser::ClassNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitClassName(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VoidContext ------------------------------------------------------------------

fxParser::VoidContext::VoidContext(Type_Context *ctx) { copyFrom(ctx); }

void fxParser::VoidContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVoid(this);
}
void fxParser::VoidContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVoid(this);
}

antlrcpp::Any fxParser::VoidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitVoid(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

fxParser::IntContext::IntContext(Type_Context *ctx) { copyFrom(ctx); }

void fxParser::IntContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt(this);
}
void fxParser::IntContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt(this);
}

antlrcpp::Any fxParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
}
fxParser::Type_Context* fxParser::type_() {
  Type_Context *_localctx = _tracker.createInstance<Type_Context>(_ctx, getState());
  enterRule(_localctx, 18, fxParser::RuleType_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(160);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case fxParser::T__15: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::IntContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(155);
        match(fxParser::T__15);
        break;
      }

      case fxParser::T__16: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::StrContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(156);
        match(fxParser::T__16);
        break;
      }

      case fxParser::T__17: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::BoolContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(157);
        match(fxParser::T__17);
        break;
      }

      case fxParser::T__18: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::VoidContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(158);
        match(fxParser::T__18);
        break;
      }

      case fxParser::ID: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::ClassNameContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(159);
        match(fxParser::ID);
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

//----------------- ItemContext ------------------------------------------------------------------

fxParser::ItemContext::ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* fxParser::ItemContext::ID() {
  return getToken(fxParser::ID, 0);
}

fxParser::ExprContext* fxParser::ItemContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}


size_t fxParser::ItemContext::getRuleIndex() const {
  return fxParser::RuleItem;
}

void fxParser::ItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterItem(this);
}

void fxParser::ItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitItem(this);
}


antlrcpp::Any fxParser::ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitItem(this);
  else
    return visitor->visitChildren(this);
}

fxParser::ItemContext* fxParser::item() {
  ItemContext *_localctx = _tracker.createInstance<ItemContext>(_ctx, getState());
  enterRule(_localctx, 20, fxParser::RuleItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(166);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(162);
      match(fxParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(163);
      match(fxParser::ID);
      setState(164);
      match(fxParser::T__8);
      setState(165);
      expr(0);
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

//----------------- ExprContext ------------------------------------------------------------------

fxParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t fxParser::ExprContext::getRuleIndex() const {
  return fxParser::RuleExpr;
}

void fxParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- EIdContext ------------------------------------------------------------------

tree::TerminalNode* fxParser::EIdContext::ID() {
  return getToken(fxParser::ID, 0);
}

fxParser::EIdContext::EIdContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::EIdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEId(this);
}
void fxParser::EIdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEId(this);
}

antlrcpp::Any fxParser::EIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EFunCallContext ------------------------------------------------------------------

std::vector<fxParser::ExprContext *> fxParser::EFunCallContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::EFunCallContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::EFunCallContext::EFunCallContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::EFunCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEFunCall(this);
}
void fxParser::EFunCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEFunCall(this);
}

antlrcpp::Any fxParser::EFunCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEFunCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ERelOpContext ------------------------------------------------------------------

std::vector<fxParser::ExprContext *> fxParser::ERelOpContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::ERelOpContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::RelOpContext* fxParser::ERelOpContext::relOp() {
  return getRuleContext<fxParser::RelOpContext>(0);
}

fxParser::ERelOpContext::ERelOpContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::ERelOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterERelOp(this);
}
void fxParser::ERelOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitERelOp(this);
}

antlrcpp::Any fxParser::ERelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitERelOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ETrueContext ------------------------------------------------------------------

fxParser::ETrueContext::ETrueContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::ETrueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterETrue(this);
}
void fxParser::ETrueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitETrue(this);
}

antlrcpp::Any fxParser::ETrueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitETrue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EOrContext ------------------------------------------------------------------

std::vector<fxParser::ExprContext *> fxParser::EOrContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::EOrContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::EOrContext::EOrContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::EOrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEOr(this);
}
void fxParser::EOrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEOr(this);
}

antlrcpp::Any fxParser::EOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EIntContext ------------------------------------------------------------------

tree::TerminalNode* fxParser::EIntContext::INT() {
  return getToken(fxParser::INT, 0);
}

fxParser::EIntContext::EIntContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::EIntContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEInt(this);
}
void fxParser::EIntContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEInt(this);
}

antlrcpp::Any fxParser::EIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EMemberExprContext ------------------------------------------------------------------

fxParser::ExprContext* fxParser::EMemberExprContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

tree::TerminalNode* fxParser::EMemberExprContext::ID() {
  return getToken(fxParser::ID, 0);
}

fxParser::EMemberExprContext::EMemberExprContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::EMemberExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEMemberExpr(this);
}
void fxParser::EMemberExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEMemberExpr(this);
}

antlrcpp::Any fxParser::EMemberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEMemberExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EUnOpContext ------------------------------------------------------------------

fxParser::ExprContext* fxParser::EUnOpContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

fxParser::EUnOpContext::EUnOpContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::EUnOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEUnOp(this);
}
void fxParser::EUnOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEUnOp(this);
}

antlrcpp::Any fxParser::EUnOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEUnOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EStrContext ------------------------------------------------------------------

tree::TerminalNode* fxParser::EStrContext::STR() {
  return getToken(fxParser::STR, 0);
}

fxParser::EStrContext::EStrContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::EStrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEStr(this);
}
void fxParser::EStrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEStr(this);
}

antlrcpp::Any fxParser::EStrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEStr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ENewExprContext ------------------------------------------------------------------

fxParser::Type_Context* fxParser::ENewExprContext::type_() {
  return getRuleContext<fxParser::Type_Context>(0);
}

fxParser::ENewExprContext::ENewExprContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::ENewExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterENewExpr(this);
}
void fxParser::ENewExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitENewExpr(this);
}

antlrcpp::Any fxParser::ENewExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitENewExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EMulOpContext ------------------------------------------------------------------

std::vector<fxParser::ExprContext *> fxParser::EMulOpContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::EMulOpContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::MulOpContext* fxParser::EMulOpContext::mulOp() {
  return getRuleContext<fxParser::MulOpContext>(0);
}

fxParser::EMulOpContext::EMulOpContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::EMulOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEMulOp(this);
}
void fxParser::EMulOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEMulOp(this);
}

antlrcpp::Any fxParser::EMulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEMulOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EAndContext ------------------------------------------------------------------

std::vector<fxParser::ExprContext *> fxParser::EAndContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::EAndContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::EAndContext::EAndContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::EAndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEAnd(this);
}
void fxParser::EAndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEAnd(this);
}

antlrcpp::Any fxParser::EAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EClassCastContext ------------------------------------------------------------------

fxParser::Type_Context* fxParser::EClassCastContext::type_() {
  return getRuleContext<fxParser::Type_Context>(0);
}

fxParser::ExprContext* fxParser::EClassCastContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

fxParser::EClassCastContext::EClassCastContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::EClassCastContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEClassCast(this);
}
void fxParser::EClassCastContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEClassCast(this);
}

antlrcpp::Any fxParser::EClassCastContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEClassCast(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EParenContext ------------------------------------------------------------------

fxParser::ExprContext* fxParser::EParenContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

fxParser::EParenContext::EParenContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::EParenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEParen(this);
}
void fxParser::EParenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEParen(this);
}

antlrcpp::Any fxParser::EParenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEParen(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EFalseContext ------------------------------------------------------------------

fxParser::EFalseContext::EFalseContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::EFalseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEFalse(this);
}
void fxParser::EFalseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEFalse(this);
}

antlrcpp::Any fxParser::EFalseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEFalse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EAddOpContext ------------------------------------------------------------------

std::vector<fxParser::ExprContext *> fxParser::EAddOpContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::EAddOpContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::AddOpContext* fxParser::EAddOpContext::addOp() {
  return getRuleContext<fxParser::AddOpContext>(0);
}

fxParser::EAddOpContext::EAddOpContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::EAddOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEAddOp(this);
}
void fxParser::EAddOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEAddOp(this);
}

antlrcpp::Any fxParser::EAddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitEAddOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ENullContext ------------------------------------------------------------------

fxParser::ENullContext::ENullContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::ENullContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterENull(this);
}
void fxParser::ENullContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitENull(this);
}

antlrcpp::Any fxParser::ENullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitENull(this);
  else
    return visitor->visitChildren(this);
}

fxParser::ExprContext* fxParser::expr() {
   return expr(0);
}

fxParser::ExprContext* fxParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  fxParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  fxParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, fxParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(188);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<EUnOpContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(169);
      _la = _input->LA(1);
      if (!(_la == fxParser::T__20

      || _la == fxParser::T__21)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(170);
      expr(15);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ENewExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(171);
      match(fxParser::T__24);
      setState(172);
      type_();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<EIdContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(173);
      match(fxParser::ID);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<EIntContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(174);
      match(fxParser::INT);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ETrueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(175);
      match(fxParser::T__25);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<EFalseContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(176);
      match(fxParser::T__26);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<EStrContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(177);
      match(fxParser::STR);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ENullContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(178);
      match(fxParser::T__27);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<EParenContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(179);
      match(fxParser::T__0);
      setState(180);
      expr(0);
      setState(181);
      match(fxParser::T__1);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<EClassCastContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(183);
      match(fxParser::T__0);
      setState(184);
      type_();
      setState(185);
      match(fxParser::T__1);
      setState(186);
      expr(1);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(226);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(224);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<EMulOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(190);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(191);
          mulOp();
          setState(192);
          expr(15);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<EAddOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(194);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(195);
          addOp();
          setState(196);
          expr(14);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ERelOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(198);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(199);
          relOp();
          setState(200);
          expr(13);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EAndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(202);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(203);
          match(fxParser::T__22);
          setState(204);
          expr(11);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<EOrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(205);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(206);
          match(fxParser::T__23);
          setState(207);
          expr(10);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<EFunCallContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(208);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(209);
          match(fxParser::T__0);
          setState(218);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << fxParser::T__0)
            | (1ULL << fxParser::T__20)
            | (1ULL << fxParser::T__21)
            | (1ULL << fxParser::T__24)
            | (1ULL << fxParser::T__25)
            | (1ULL << fxParser::T__26)
            | (1ULL << fxParser::T__27)
            | (1ULL << fxParser::INT)
            | (1ULL << fxParser::ID)
            | (1ULL << fxParser::STR))) != 0)) {
            setState(210);
            expr(0);
            setState(215);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == fxParser::T__7) {
              setState(211);
              match(fxParser::T__7);
              setState(212);
              expr(0);
              setState(217);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(220);
          match(fxParser::T__1);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<EMemberExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(221);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(222);
          match(fxParser::T__19);
          setState(223);
          match(fxParser::ID);
          break;
        }

        } 
      }
      setState(228);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AddOpContext ------------------------------------------------------------------

fxParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t fxParser::AddOpContext::getRuleIndex() const {
  return fxParser::RuleAddOp;
}

void fxParser::AddOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddOp(this);
}

void fxParser::AddOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddOp(this);
}


antlrcpp::Any fxParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

fxParser::AddOpContext* fxParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 24, fxParser::RuleAddOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    _la = _input->LA(1);
    if (!(_la == fxParser::T__20

    || _la == fxParser::T__28)) {
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

//----------------- MulOpContext ------------------------------------------------------------------

fxParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t fxParser::MulOpContext::getRuleIndex() const {
  return fxParser::RuleMulOp;
}

void fxParser::MulOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulOp(this);
}

void fxParser::MulOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulOp(this);
}


antlrcpp::Any fxParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}

fxParser::MulOpContext* fxParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 26, fxParser::RuleMulOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(231);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__29)
      | (1ULL << fxParser::T__30)
      | (1ULL << fxParser::T__31))) != 0))) {
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

//----------------- RelOpContext ------------------------------------------------------------------

fxParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t fxParser::RelOpContext::getRuleIndex() const {
  return fxParser::RuleRelOp;
}

void fxParser::RelOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelOp(this);
}

void fxParser::RelOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelOp(this);
}


antlrcpp::Any fxParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

fxParser::RelOpContext* fxParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 28, fxParser::RuleRelOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__32)
      | (1ULL << fxParser::T__33)
      | (1ULL << fxParser::T__34)
      | (1ULL << fxParser::T__35)
      | (1ULL << fxParser::T__36)
      | (1ULL << fxParser::T__37))) != 0))) {
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

bool fxParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool fxParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 14);
    case 1: return precpred(_ctx, 13);
    case 2: return precpred(_ctx, 12);
    case 3: return precpred(_ctx, 11);
    case 4: return precpred(_ctx, 10);
    case 5: return precpred(_ctx, 17);
    case 6: return precpred(_ctx, 16);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> fxParser::_decisionToDFA;
atn::PredictionContextCache fxParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN fxParser::_atn;
std::vector<uint16_t> fxParser::_serializedATN;

std::vector<std::string> fxParser::_ruleNames = {
  "program", "topDef", "funcDef", "classDef", "classItem", "arg", "varDef", 
  "block", "stmt", "type_", "item", "expr", "addOp", "mulOp", "relOp"
};

std::vector<std::string> fxParser::_literalNames = {
  "", "'('", "')'", "'class'", "'extends'", "'{'", "'}'", "';'", "','", 
  "'='", "'++'", "'--'", "'return'", "'if'", "'else'", "'while'", "'int'", 
  "'str'", "'bool'", "'void'", "'.'", "'-'", "'!'", "'&&'", "'||'", "'new'", 
  "'true'", "'false'", "'null'", "'+'", "'*'", "'/'", "'%'", "'<'", "'<='", 
  "'>'", "'>='", "'=='", "'!='"
};

std::vector<std::string> fxParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "COMMENT", "MULTICOMMENT", "INT", "ID", "WS", "STR"
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
    0x3, 0x2e, 0xee, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x3, 0x2, 0x6, 0x2, 0x22, 0xa, 
    0x2, 0xd, 0x2, 0xe, 0x2, 0x23, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x28, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x2e, 0xa, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x37, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x3b, 0xa, 0x5, 
    0xc, 0x5, 0xe, 0x5, 0x3e, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x4a, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x4f, 0xa, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x54, 0xa, 0x7, 0xc, 0x7, 
    0xe, 0x7, 0x57, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x7, 0x9, 0x5e, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x61, 0xb, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x7, 0xa, 0x6b, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x6e, 0xb, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0x9c, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xa3, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0xa9, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xbf, 0xa, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x7, 0xd, 0xd8, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xdb, 0xb, 0xd, 0x5, 
    0xd, 0xdd, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
    0xe3, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xe6, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x2, 0x3, 0x18, 
    0x11, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x2, 0x6, 0x3, 0x2, 0x17, 0x18, 0x4, 0x2, 0x17, 0x17, 
    0x1f, 0x1f, 0x3, 0x2, 0x20, 0x22, 0x3, 0x2, 0x23, 0x28, 0x2, 0x10a, 
    0x2, 0x21, 0x3, 0x2, 0x2, 0x2, 0x4, 0x27, 0x3, 0x2, 0x2, 0x2, 0x6, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x32, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4e, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x50, 0x3, 0x2, 0x2, 0x2, 0xe, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0x16, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x18, 0xbe, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xe9, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x20, 0x22, 0x5, 0x4, 
    0x3, 0x2, 0x21, 0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0x3, 0x3, 0x2, 0x2, 0x2, 0x25, 0x28, 0x5, 0x6, 0x4, 0x2, 0x26, 
    0x28, 0x5, 0x8, 0x5, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 0x26, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x5, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x5, 
    0x14, 0xb, 0x2, 0x2a, 0x2b, 0x7, 0x2c, 0x2, 0x2, 0x2b, 0x2d, 0x7, 0x3, 
    0x2, 0x2, 0x2c, 0x2e, 0x5, 0xc, 0x7, 0x2, 0x2d, 0x2c, 0x3, 0x2, 0x2, 
    0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x2f, 0x30, 0x7, 0x4, 0x2, 0x2, 0x30, 0x31, 0x5, 0x10, 0x9, 0x2, 0x31, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x7, 0x5, 0x2, 0x2, 0x33, 0x36, 
    0x7, 0x2c, 0x2, 0x2, 0x34, 0x35, 0x7, 0x6, 0x2, 0x2, 0x35, 0x37, 0x7, 
    0x2c, 0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3c, 0x7, 0x7, 0x2, 
    0x2, 0x39, 0x3b, 0x5, 0xa, 0x6, 0x2, 0x3a, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x3b, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 
    0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x8, 0x2, 0x2, 0x40, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x41, 0x42, 0x5, 0x14, 0xb, 0x2, 0x42, 0x43, 0x7, 0x2c, 
    0x2, 0x2, 0x43, 0x44, 0x7, 0x9, 0x2, 0x2, 0x44, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x45, 0x46, 0x5, 0x14, 0xb, 0x2, 0x46, 0x47, 0x7, 0x2c, 0x2, 0x2, 
    0x47, 0x49, 0x7, 0x3, 0x2, 0x2, 0x48, 0x4a, 0x5, 0xc, 0x7, 0x2, 0x49, 
    0x48, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 
    0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x4, 0x2, 0x2, 0x4c, 0x4d, 0x5, 
    0x10, 0x9, 0x2, 0x4d, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x45, 0x3, 0x2, 0x2, 0x2, 0x4f, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x55, 0x5, 0xe, 0x8, 0x2, 0x51, 0x52, 0x7, 0xa, 0x2, 0x2, 
    0x52, 0x54, 0x5, 0xe, 0x8, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 0x54, 
    0x57, 0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 
    0x3, 0x2, 0x2, 0x2, 0x56, 0xd, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x59, 0x5, 0x14, 0xb, 0x2, 0x59, 0x5a, 0x7, 0x2c, 
    0x2, 0x2, 0x5a, 0xf, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5f, 0x7, 0x7, 0x2, 
    0x2, 0x5c, 0x5e, 0x5, 0x12, 0xa, 0x2, 0x5d, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x61, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 
    0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x62, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 
    0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0x8, 0x2, 0x2, 0x63, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x9c, 0x7, 0x9, 0x2, 0x2, 0x65, 0x9c, 0x5, 0x10, 
    0x9, 0x2, 0x66, 0x67, 0x5, 0x14, 0xb, 0x2, 0x67, 0x6c, 0x5, 0x16, 0xc, 
    0x2, 0x68, 0x69, 0x7, 0xa, 0x2, 0x2, 0x69, 0x6b, 0x5, 0x16, 0xc, 0x2, 
    0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 
    0x9, 0x2, 0x2, 0x70, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x5, 0x18, 
    0xd, 0x2, 0x72, 0x73, 0x7, 0xb, 0x2, 0x2, 0x73, 0x74, 0x5, 0x18, 0xd, 
    0x2, 0x74, 0x75, 0x7, 0x9, 0x2, 0x2, 0x75, 0x9c, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0x77, 0x5, 0x18, 0xd, 0x2, 0x77, 0x78, 0x7, 0xc, 0x2, 0x2, 0x78, 
    0x79, 0x7, 0x9, 0x2, 0x2, 0x79, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 
    0x5, 0x18, 0xd, 0x2, 0x7b, 0x7c, 0x7, 0xd, 0x2, 0x2, 0x7c, 0x7d, 0x7, 
    0x9, 0x2, 0x2, 0x7d, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0xe, 
    0x2, 0x2, 0x7f, 0x80, 0x5, 0x18, 0xd, 0x2, 0x80, 0x81, 0x7, 0x9, 0x2, 
    0x2, 0x81, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x7, 0xe, 0x2, 0x2, 
    0x83, 0x9c, 0x7, 0x9, 0x2, 0x2, 0x84, 0x85, 0x7, 0xf, 0x2, 0x2, 0x85, 
    0x86, 0x7, 0x3, 0x2, 0x2, 0x86, 0x87, 0x5, 0x18, 0xd, 0x2, 0x87, 0x88, 
    0x7, 0x4, 0x2, 0x2, 0x88, 0x89, 0x5, 0x12, 0xa, 0x2, 0x89, 0x9c, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0xf, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x3, 
    0x2, 0x2, 0x8c, 0x8d, 0x5, 0x18, 0xd, 0x2, 0x8d, 0x8e, 0x7, 0x4, 0x2, 
    0x2, 0x8e, 0x8f, 0x5, 0x12, 0xa, 0x2, 0x8f, 0x90, 0x7, 0x10, 0x2, 0x2, 
    0x90, 0x91, 0x5, 0x12, 0xa, 0x2, 0x91, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x93, 0x7, 0x11, 0x2, 0x2, 0x93, 0x94, 0x7, 0x3, 0x2, 0x2, 0x94, 0x95, 
    0x5, 0x18, 0xd, 0x2, 0x95, 0x96, 0x7, 0x4, 0x2, 0x2, 0x96, 0x97, 0x5, 
    0x12, 0xa, 0x2, 0x97, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x5, 0x18, 
    0xd, 0x2, 0x99, 0x9a, 0x7, 0x9, 0x2, 0x2, 0x9a, 0x9c, 0x3, 0x2, 0x2, 
    0x2, 0x9b, 0x64, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x9b, 0x66, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x71, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x76, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x7e, 
    0x3, 0x2, 0x2, 0x2, 0x9b, 0x82, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x9b, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x92, 0x3, 0x2, 
    0x2, 0x2, 0x9b, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x9d, 0xa3, 0x7, 0x12, 0x2, 0x2, 0x9e, 0xa3, 0x7, 0x13, 0x2, 0x2, 
    0x9f, 0xa3, 0x7, 0x14, 0x2, 0x2, 0xa0, 0xa3, 0x7, 0x15, 0x2, 0x2, 0xa1, 
    0xa3, 0x7, 0x2c, 0x2, 0x2, 0xa2, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x9e, 
    0x3, 0x2, 0x2, 0x2, 0xa2, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 0x3, 
    0x2, 0x2, 0x2, 0xa2, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa3, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xa9, 0x7, 0x2c, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x2c, 0x2, 
    0x2, 0xa6, 0xa7, 0x7, 0xb, 0x2, 0x2, 0xa7, 0xa9, 0x5, 0x18, 0xd, 0x2, 
    0xa8, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa9, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x8, 0xd, 0x1, 0x2, 0xab, 0xac, 
    0x9, 0x2, 0x2, 0x2, 0xac, 0xbf, 0x5, 0x18, 0xd, 0x11, 0xad, 0xae, 0x7, 
    0x1b, 0x2, 0x2, 0xae, 0xbf, 0x5, 0x14, 0xb, 0x2, 0xaf, 0xbf, 0x7, 0x2c, 
    0x2, 0x2, 0xb0, 0xbf, 0x7, 0x2b, 0x2, 0x2, 0xb1, 0xbf, 0x7, 0x1c, 0x2, 
    0x2, 0xb2, 0xbf, 0x7, 0x1d, 0x2, 0x2, 0xb3, 0xbf, 0x7, 0x2e, 0x2, 0x2, 
    0xb4, 0xbf, 0x7, 0x1e, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x3, 0x2, 0x2, 0xb6, 
    0xb7, 0x5, 0x18, 0xd, 0x2, 0xb7, 0xb8, 0x7, 0x4, 0x2, 0x2, 0xb8, 0xbf, 
    0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x3, 0x2, 0x2, 0xba, 0xbb, 0x5, 
    0x14, 0xb, 0x2, 0xbb, 0xbc, 0x7, 0x4, 0x2, 0x2, 0xbc, 0xbd, 0x5, 0x18, 
    0xd, 0x3, 0xbd, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xaa, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0xad, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xbe, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xbe, 
    0xb2, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xb4, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xb9, 0x3, 
    0x2, 0x2, 0x2, 0xbf, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0xc, 0x10, 
    0x2, 0x2, 0xc1, 0xc2, 0x5, 0x1c, 0xf, 0x2, 0xc2, 0xc3, 0x5, 0x18, 0xd, 
    0x11, 0xc3, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0xc, 0xf, 0x2, 0x2, 
    0xc5, 0xc6, 0x5, 0x1a, 0xe, 0x2, 0xc6, 0xc7, 0x5, 0x18, 0xd, 0x10, 0xc7, 
    0xe3, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0xc, 0xe, 0x2, 0x2, 0xc9, 0xca, 
    0x5, 0x1e, 0x10, 0x2, 0xca, 0xcb, 0x5, 0x18, 0xd, 0xf, 0xcb, 0xe3, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0xcd, 0xc, 0xd, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x19, 
    0x2, 0x2, 0xce, 0xe3, 0x5, 0x18, 0xd, 0xd, 0xcf, 0xd0, 0xc, 0xc, 0x2, 
    0x2, 0xd0, 0xd1, 0x7, 0x1a, 0x2, 0x2, 0xd1, 0xe3, 0x5, 0x18, 0xd, 0xc, 
    0xd2, 0xd3, 0xc, 0x13, 0x2, 0x2, 0xd3, 0xdc, 0x7, 0x3, 0x2, 0x2, 0xd4, 
    0xd9, 0x5, 0x18, 0xd, 0x2, 0xd5, 0xd6, 0x7, 0xa, 0x2, 0x2, 0xd6, 0xd8, 
    0x5, 0x18, 0xd, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xdb, 0x3, 
    0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xda, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 
    0x2, 0xdc, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0xe3, 0x7, 0x4, 0x2, 0x2, 0xdf, 
    0xe0, 0xc, 0x12, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x16, 0x2, 0x2, 0xe1, 0xe3, 
    0x7, 0x2c, 0x2, 0x2, 0xe2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xc4, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xcc, 0x3, 0x2, 
    0x2, 0x2, 0xe2, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xe2, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe6, 0x3, 0x2, 0x2, 0x2, 
    0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe5, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 
    0x9, 0x3, 0x2, 0x2, 0xe8, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x9, 
    0x4, 0x2, 0x2, 0xea, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x9, 0x5, 
    0x2, 0x2, 0xec, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x14, 0x23, 0x27, 0x2d, 0x36, 
    0x3c, 0x49, 0x4e, 0x55, 0x5f, 0x6c, 0x9b, 0xa2, 0xa8, 0xbe, 0xd9, 0xdc, 
    0xe2, 0xe4, 
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
