
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
    setState(49); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(48);
      topDef();
      setState(51); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__2)
      | (1ULL << fxParser::T__3)
      | (1ULL << fxParser::T__4)
      | (1ULL << fxParser::T__20)
      | (1ULL << fxParser::T__21)
      | (1ULL << fxParser::T__22)
      | (1ULL << fxParser::T__23)
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
    setState(55);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case fxParser::T__2:
      case fxParser::T__3:
      case fxParser::T__20:
      case fxParser::T__21:
      case fxParser::T__22:
      case fxParser::T__23:
      case fxParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(53);
        funcDef();
        break;
      }

      case fxParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(54);
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

fxParser::TargetTypeContext* fxParser::FuncDefContext::targetType() {
  return getRuleContext<fxParser::TargetTypeContext>(0);
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
    setState(58);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == fxParser::T__2

    || _la == fxParser::T__3) {
      setState(57);
      targetType();
    }
    setState(60);
    type_();
    setState(61);
    match(fxParser::ID);
    setState(62);
    match(fxParser::T__0);
    setState(64);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__20)
      | (1ULL << fxParser::T__21)
      | (1ULL << fxParser::T__22)
      | (1ULL << fxParser::T__23)
      | (1ULL << fxParser::ID))) != 0)) {
      setState(63);
      arg();
    }
    setState(66);
    match(fxParser::T__1);
    setState(67);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TargetTypeContext ------------------------------------------------------------------

fxParser::TargetTypeContext::TargetTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t fxParser::TargetTypeContext::getRuleIndex() const {
  return fxParser::RuleTargetType;
}

void fxParser::TargetTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTargetType(this);
}

void fxParser::TargetTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTargetType(this);
}


antlrcpp::Any fxParser::TargetTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitTargetType(this);
  else
    return visitor->visitChildren(this);
}

fxParser::TargetTypeContext* fxParser::targetType() {
  TargetTypeContext *_localctx = _tracker.createInstance<TargetTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, fxParser::RuleTargetType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    _la = _input->LA(1);
    if (!(_la == fxParser::T__2

    || _la == fxParser::T__3)) {
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
  enterRule(_localctx, 8, fxParser::RuleClassDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(fxParser::T__4);
    setState(72);
    match(fxParser::ID);
    setState(75);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == fxParser::T__5) {
      setState(73);
      match(fxParser::T__5);
      setState(74);
      match(fxParser::ID);
    }
    setState(77);
    match(fxParser::T__6);
    setState(81);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__20)
      | (1ULL << fxParser::T__21)
      | (1ULL << fxParser::T__22)
      | (1ULL << fxParser::T__23)
      | (1ULL << fxParser::ID))) != 0)) {
      setState(78);
      classItem();
      setState(83);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(84);
    match(fxParser::T__7);
   
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
  enterRule(_localctx, 10, fxParser::RuleClassItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ClassItemContext *>(_tracker.createInstance<fxParser::FieldDeclContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(86);
      type_();
      setState(87);
      match(fxParser::ID);
      setState(88);
      match(fxParser::T__8);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ClassItemContext *>(_tracker.createInstance<fxParser::MethodDefContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(90);
      type_();
      setState(91);
      match(fxParser::ID);
      setState(92);
      match(fxParser::T__0);
      setState(94);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << fxParser::T__20)
        | (1ULL << fxParser::T__21)
        | (1ULL << fxParser::T__22)
        | (1ULL << fxParser::T__23)
        | (1ULL << fxParser::ID))) != 0)) {
        setState(93);
        arg();
      }
      setState(96);
      match(fxParser::T__1);
      setState(97);
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
  enterRule(_localctx, 12, fxParser::RuleArg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    varDef();
    setState(106);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == fxParser::T__9) {
      setState(102);
      match(fxParser::T__9);
      setState(103);
      varDef();
      setState(108);
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
  enterRule(_localctx, 14, fxParser::RuleVarDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    type_();
    setState(110);
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
  enterRule(_localctx, 16, fxParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    match(fxParser::T__6);
    setState(116);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__8)
      | (1ULL << fxParser::T__10)
      | (1ULL << fxParser::T__12)
      | (1ULL << fxParser::T__17)
      | (1ULL << fxParser::T__18)
      | (1ULL << fxParser::T__20)
      | (1ULL << fxParser::T__21)
      | (1ULL << fxParser::T__22)
      | (1ULL << fxParser::T__23)
      | (1ULL << fxParser::T__26)
      | (1ULL << fxParser::T__27)
      | (1ULL << fxParser::INT)
      | (1ULL << fxParser::ID)
      | (1ULL << fxParser::STR))) != 0)) {
      setState(113);
      stmt();
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(119);
    match(fxParser::T__7);
   
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

fxParser::VarAssignDefContext* fxParser::StmtContext::varAssignDef() {
  return getRuleContext<fxParser::VarAssignDefContext>(0);
}

fxParser::AssignStmtContext* fxParser::StmtContext::assignStmt() {
  return getRuleContext<fxParser::AssignStmtContext>(0);
}

fxParser::ReturnStmtContext* fxParser::StmtContext::returnStmt() {
  return getRuleContext<fxParser::ReturnStmtContext>(0);
}

fxParser::IfStmtContext* fxParser::StmtContext::ifStmt() {
  return getRuleContext<fxParser::IfStmtContext>(0);
}

fxParser::ForStmtContext* fxParser::StmtContext::forStmt() {
  return getRuleContext<fxParser::ForStmtContext>(0);
}

fxParser::ExprContext* fxParser::StmtContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}


size_t fxParser::StmtContext::getRuleIndex() const {
  return fxParser::RuleStmt;
}

void fxParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void fxParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


antlrcpp::Any fxParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

fxParser::StmtContext* fxParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 18, fxParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(130);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(121);
      match(fxParser::T__8);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(122);
      varAssignDef();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(123);
      assignStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(124);
      returnStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(125);
      ifStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(126);
      forStmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(127);
      expr(0);
      setState(128);
      match(fxParser::T__8);
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

//----------------- ForStmtContext ------------------------------------------------------------------

fxParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<fxParser::ExprContext *> fxParser::ForStmtContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::ForStmtContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::BlockContext* fxParser::ForStmtContext::block() {
  return getRuleContext<fxParser::BlockContext>(0);
}


size_t fxParser::ForStmtContext::getRuleIndex() const {
  return fxParser::RuleForStmt;
}

void fxParser::ForStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStmt(this);
}

void fxParser::ForStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStmt(this);
}


antlrcpp::Any fxParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}

fxParser::ForStmtContext* fxParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 20, fxParser::RuleForStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    match(fxParser::T__10);
    setState(133);
    match(fxParser::T__0);
    setState(135);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__26)
      | (1ULL << fxParser::T__27)
      | (1ULL << fxParser::INT)
      | (1ULL << fxParser::ID)
      | (1ULL << fxParser::STR))) != 0)) {
      setState(134);
      expr(0);
    }
    setState(137);
    match(fxParser::T__8);
    setState(138);
    expr(0);
    setState(139);
    match(fxParser::T__8);
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__26)
      | (1ULL << fxParser::T__27)
      | (1ULL << fxParser::INT)
      | (1ULL << fxParser::ID)
      | (1ULL << fxParser::STR))) != 0)) {
      setState(140);
      expr(0);
    }
    setState(143);
    match(fxParser::T__1);
    setState(144);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarAssignDefContext ------------------------------------------------------------------

fxParser::VarAssignDefContext::VarAssignDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t fxParser::VarAssignDefContext::getRuleIndex() const {
  return fxParser::RuleVarAssignDef;
}

void fxParser::VarAssignDefContext::copyFrom(VarAssignDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MatrixAgnDeclContext ------------------------------------------------------------------

tree::TerminalNode* fxParser::MatrixAgnDeclContext::ID() {
  return getToken(fxParser::ID, 0);
}

fxParser::MatrixConstContext* fxParser::MatrixAgnDeclContext::matrixConst() {
  return getRuleContext<fxParser::MatrixConstContext>(0);
}

fxParser::MatrixAgnDeclContext::MatrixAgnDeclContext(VarAssignDefContext *ctx) { copyFrom(ctx); }

void fxParser::MatrixAgnDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatrixAgnDecl(this);
}
void fxParser::MatrixAgnDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatrixAgnDecl(this);
}

antlrcpp::Any fxParser::MatrixAgnDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitMatrixAgnDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AgnDeclContext ------------------------------------------------------------------

fxParser::Type_Context* fxParser::AgnDeclContext::type_() {
  return getRuleContext<fxParser::Type_Context>(0);
}

tree::TerminalNode* fxParser::AgnDeclContext::ID() {
  return getToken(fxParser::ID, 0);
}

fxParser::ExprContext* fxParser::AgnDeclContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

fxParser::AgnDeclContext::AgnDeclContext(VarAssignDefContext *ctx) { copyFrom(ctx); }

void fxParser::AgnDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAgnDecl(this);
}
void fxParser::AgnDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAgnDecl(this);
}

antlrcpp::Any fxParser::AgnDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitAgnDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarDeclContext ------------------------------------------------------------------

fxParser::Type_Context* fxParser::VarDeclContext::type_() {
  return getRuleContext<fxParser::Type_Context>(0);
}

tree::TerminalNode* fxParser::VarDeclContext::ID() {
  return getToken(fxParser::ID, 0);
}

fxParser::VarDeclContext::VarDeclContext(VarAssignDefContext *ctx) { copyFrom(ctx); }

void fxParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}
void fxParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}

antlrcpp::Any fxParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatrixDeclContext ------------------------------------------------------------------

tree::TerminalNode* fxParser::MatrixDeclContext::ID() {
  return getToken(fxParser::ID, 0);
}

fxParser::Type_Context* fxParser::MatrixDeclContext::type_() {
  return getRuleContext<fxParser::Type_Context>(0);
}

std::vector<tree::TerminalNode *> fxParser::MatrixDeclContext::INT() {
  return getTokens(fxParser::INT);
}

tree::TerminalNode* fxParser::MatrixDeclContext::INT(size_t i) {
  return getToken(fxParser::INT, i);
}

fxParser::MatrixDeclContext::MatrixDeclContext(VarAssignDefContext *ctx) { copyFrom(ctx); }

void fxParser::MatrixDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatrixDecl(this);
}
void fxParser::MatrixDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatrixDecl(this);
}

antlrcpp::Any fxParser::MatrixDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitMatrixDecl(this);
  else
    return visitor->visitChildren(this);
}
fxParser::VarAssignDefContext* fxParser::varAssignDef() {
  VarAssignDefContext *_localctx = _tracker.createInstance<VarAssignDefContext>(_ctx, getState());
  enterRule(_localctx, 22, fxParser::RuleVarAssignDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(176);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarAssignDefContext *>(_tracker.createInstance<fxParser::VarDeclContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(146);
      type_();
      setState(147);
      match(fxParser::ID);
      setState(148);
      match(fxParser::T__8);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarAssignDefContext *>(_tracker.createInstance<fxParser::AgnDeclContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(150);
      type_();
      setState(151);
      match(fxParser::ID);
      setState(152);
      match(fxParser::T__11);
      setState(153);
      expr(0);
      setState(154);
      match(fxParser::T__8);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<VarAssignDefContext *>(_tracker.createInstance<fxParser::MatrixDeclContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(156);
      match(fxParser::T__12);
      setState(157);
      match(fxParser::ID);
      setState(158);
      match(fxParser::T__13);
      setState(159);
      type_();
      setState(160);
      match(fxParser::T__14);
      setState(161);
      match(fxParser::T__0);
      setState(162);
      match(fxParser::INT);
      setState(163);
      match(fxParser::T__9);
      setState(164);
      match(fxParser::INT);
      setState(165);
      match(fxParser::T__1);
      setState(166);
      match(fxParser::T__8);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<VarAssignDefContext *>(_tracker.createInstance<fxParser::MatrixAgnDeclContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(168);
      match(fxParser::T__12);
      setState(169);
      match(fxParser::ID);
      setState(170);
      match(fxParser::T__11);
      setState(171);
      match(fxParser::T__15);
      setState(172);
      matrixConst();
      setState(173);
      match(fxParser::T__16);
      setState(174);
      match(fxParser::T__8);
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

//----------------- AssignStmtContext ------------------------------------------------------------------

fxParser::AssignStmtContext::AssignStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t fxParser::AssignStmtContext::getRuleIndex() const {
  return fxParser::RuleAssignStmt;
}

void fxParser::AssignStmtContext::copyFrom(AssignStmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AgnStmtContext ------------------------------------------------------------------

std::vector<fxParser::ExprContext *> fxParser::AgnStmtContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::AgnStmtContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::AgnStmtContext::AgnStmtContext(AssignStmtContext *ctx) { copyFrom(ctx); }

void fxParser::AgnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAgnStmt(this);
}
void fxParser::AgnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAgnStmt(this);
}

antlrcpp::Any fxParser::AgnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitAgnStmt(this);
  else
    return visitor->visitChildren(this);
}
fxParser::AssignStmtContext* fxParser::assignStmt() {
  AssignStmtContext *_localctx = _tracker.createInstance<AssignStmtContext>(_ctx, getState());
  enterRule(_localctx, 24, fxParser::RuleAssignStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<AssignStmtContext *>(_tracker.createInstance<fxParser::AgnStmtContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(178);
    expr(0);
    setState(179);
    match(fxParser::T__11);
    setState(180);
    expr(0);
    setState(181);
    match(fxParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

fxParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

fxParser::ExprContext* fxParser::ReturnStmtContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}


size_t fxParser::ReturnStmtContext::getRuleIndex() const {
  return fxParser::RuleReturnStmt;
}

void fxParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}

void fxParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}


antlrcpp::Any fxParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

fxParser::ReturnStmtContext* fxParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 26, fxParser::RuleReturnStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(183);
      match(fxParser::T__17);
      setState(184);
      expr(0);
      setState(185);
      match(fxParser::T__8);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(187);
      match(fxParser::T__17);
      setState(188);
      match(fxParser::T__8);
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

//----------------- IfStmtContext ------------------------------------------------------------------

fxParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

fxParser::ExprContext* fxParser::IfStmtContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

std::vector<fxParser::BlockContext *> fxParser::IfStmtContext::block() {
  return getRuleContexts<fxParser::BlockContext>();
}

fxParser::BlockContext* fxParser::IfStmtContext::block(size_t i) {
  return getRuleContext<fxParser::BlockContext>(i);
}


size_t fxParser::IfStmtContext::getRuleIndex() const {
  return fxParser::RuleIfStmt;
}

void fxParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void fxParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}


antlrcpp::Any fxParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

fxParser::IfStmtContext* fxParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 28, fxParser::RuleIfStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(205);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(191);
      match(fxParser::T__18);
      setState(192);
      match(fxParser::T__0);
      setState(193);
      expr(0);
      setState(194);
      match(fxParser::T__1);
      setState(195);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(197);
      match(fxParser::T__18);
      setState(198);
      match(fxParser::T__0);
      setState(199);
      expr(0);
      setState(200);
      match(fxParser::T__1);
      setState(201);
      block();
      setState(202);
      match(fxParser::T__19);
      setState(203);
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
  enterRule(_localctx, 30, fxParser::RuleType_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(212);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case fxParser::T__20: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::IntContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(207);
        match(fxParser::T__20);
        break;
      }

      case fxParser::T__21: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::StrContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(208);
        match(fxParser::T__21);
        break;
      }

      case fxParser::T__22: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::BoolContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(209);
        match(fxParser::T__22);
        break;
      }

      case fxParser::T__23: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::VoidContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(210);
        match(fxParser::T__23);
        break;
      }

      case fxParser::ID: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::ClassNameContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(211);
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

//----------------- AndExprContext ------------------------------------------------------------------

std::vector<fxParser::ExprContext *> fxParser::AndExprContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::AndExprContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::AndExprContext::AndExprContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::AndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpr(this);
}
void fxParser::AndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpr(this);
}

antlrcpp::Any fxParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IDExprContext ------------------------------------------------------------------

tree::TerminalNode* fxParser::IDExprContext::ID() {
  return getToken(fxParser::ID, 0);
}

fxParser::IDExprContext::IDExprContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::IDExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIDExpr(this);
}
void fxParser::IDExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIDExpr(this);
}

antlrcpp::Any fxParser::IDExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitIDExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstExprContext ------------------------------------------------------------------

fxParser::ConstantContext* fxParser::ConstExprContext::constant() {
  return getRuleContext<fxParser::ConstantContext>(0);
}

fxParser::ConstExprContext::ConstExprContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::ConstExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExpr(this);
}
void fxParser::ConstExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExpr(this);
}

antlrcpp::Any fxParser::ConstExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitConstExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelOpExprContext ------------------------------------------------------------------

std::vector<fxParser::ExprContext *> fxParser::RelOpExprContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::RelOpExprContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::RelOpContext* fxParser::RelOpExprContext::relOp() {
  return getRuleContext<fxParser::RelOpContext>(0);
}

fxParser::RelOpExprContext::RelOpExprContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::RelOpExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelOpExpr(this);
}
void fxParser::RelOpExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelOpExpr(this);
}

antlrcpp::Any fxParser::RelOpExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitRelOpExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallExprContext ------------------------------------------------------------------

tree::TerminalNode* fxParser::CallExprContext::ID() {
  return getToken(fxParser::ID, 0);
}

fxParser::ParamListContext* fxParser::CallExprContext::paramList() {
  return getRuleContext<fxParser::ParamListContext>(0);
}

fxParser::CallExprContext::CallExprContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::CallExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallExpr(this);
}
void fxParser::CallExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallExpr(this);
}

antlrcpp::Any fxParser::CallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinOpExprContext ------------------------------------------------------------------

std::vector<fxParser::ExprContext *> fxParser::BinOpExprContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::BinOpExprContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::BinOpContext* fxParser::BinOpExprContext::binOp() {
  return getRuleContext<fxParser::BinOpContext>(0);
}

fxParser::BinOpExprContext::BinOpExprContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::BinOpExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinOpExpr(this);
}
void fxParser::BinOpExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinOpExpr(this);
}

antlrcpp::Any fxParser::BinOpExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitBinOpExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

std::vector<fxParser::ExprContext *> fxParser::OrExprContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::OrExprContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::OrExprContext::OrExprContext(ExprContext *ctx) { copyFrom(ctx); }

void fxParser::OrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpr(this);
}
void fxParser::OrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpr(this);
}

antlrcpp::Any fxParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
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
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, fxParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(223);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(215);
      match(fxParser::ID);
      setState(216);
      match(fxParser::T__0);
      setState(218);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << fxParser::T__26)
        | (1ULL << fxParser::T__27)
        | (1ULL << fxParser::INT)
        | (1ULL << fxParser::ID)
        | (1ULL << fxParser::STR))) != 0)) {
        setState(217);
        paramList();
      }
      setState(220);
      match(fxParser::T__1);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<IDExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(221);
      match(fxParser::ID);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ConstExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(222);
      constant();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(241);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(239);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinOpExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(225);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(226);
          binOp();
          setState(227);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<RelOpExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(229);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(230);
          relOp();
          setState(231);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(233);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(234);
          match(fxParser::T__24);
          setState(235);
          expr(5);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(236);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(237);
          match(fxParser::T__25);
          setState(238);
          expr(4);
          break;
        }

        } 
      }
      setState(243);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

fxParser::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<fxParser::ExprContext *> fxParser::ParamListContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::ParamListContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}


size_t fxParser::ParamListContext::getRuleIndex() const {
  return fxParser::RuleParamList;
}

void fxParser::ParamListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamList(this);
}

void fxParser::ParamListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamList(this);
}


antlrcpp::Any fxParser::ParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitParamList(this);
  else
    return visitor->visitChildren(this);
}

fxParser::ParamListContext* fxParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 34, fxParser::RuleParamList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    expr(0);
    setState(249);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == fxParser::T__9) {
      setState(245);
      match(fxParser::T__9);
      setState(246);
      expr(0);
      setState(251);
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

//----------------- MatrixConstContext ------------------------------------------------------------------

fxParser::MatrixConstContext::MatrixConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<fxParser::MatrixLineContext *> fxParser::MatrixConstContext::matrixLine() {
  return getRuleContexts<fxParser::MatrixLineContext>();
}

fxParser::MatrixLineContext* fxParser::MatrixConstContext::matrixLine(size_t i) {
  return getRuleContext<fxParser::MatrixLineContext>(i);
}


size_t fxParser::MatrixConstContext::getRuleIndex() const {
  return fxParser::RuleMatrixConst;
}

void fxParser::MatrixConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatrixConst(this);
}

void fxParser::MatrixConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatrixConst(this);
}


antlrcpp::Any fxParser::MatrixConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitMatrixConst(this);
  else
    return visitor->visitChildren(this);
}

fxParser::MatrixConstContext* fxParser::matrixConst() {
  MatrixConstContext *_localctx = _tracker.createInstance<MatrixConstContext>(_ctx, getState());
  enterRule(_localctx, 36, fxParser::RuleMatrixConst);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    matrixLine();
    setState(257);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == fxParser::T__8) {
      setState(253);
      match(fxParser::T__8);
      setState(254);
      matrixLine();
      setState(259);
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

//----------------- MatrixLineContext ------------------------------------------------------------------

fxParser::MatrixLineContext::MatrixLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> fxParser::MatrixLineContext::INT() {
  return getTokens(fxParser::INT);
}

tree::TerminalNode* fxParser::MatrixLineContext::INT(size_t i) {
  return getToken(fxParser::INT, i);
}


size_t fxParser::MatrixLineContext::getRuleIndex() const {
  return fxParser::RuleMatrixLine;
}

void fxParser::MatrixLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatrixLine(this);
}

void fxParser::MatrixLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatrixLine(this);
}


antlrcpp::Any fxParser::MatrixLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitMatrixLine(this);
  else
    return visitor->visitChildren(this);
}

fxParser::MatrixLineContext* fxParser::matrixLine() {
  MatrixLineContext *_localctx = _tracker.createInstance<MatrixLineContext>(_ctx, getState());
  enterRule(_localctx, 38, fxParser::RuleMatrixLine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    match(fxParser::INT);
    setState(265);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == fxParser::T__9) {
      setState(261);
      match(fxParser::T__9);
      setState(262);
      match(fxParser::INT);
      setState(267);
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

//----------------- BooleanContext ------------------------------------------------------------------

fxParser::BooleanContext::BooleanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t fxParser::BooleanContext::getRuleIndex() const {
  return fxParser::RuleBoolean;
}

void fxParser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}

void fxParser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}


antlrcpp::Any fxParser::BooleanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitBoolean(this);
  else
    return visitor->visitChildren(this);
}

fxParser::BooleanContext* fxParser::boolean() {
  BooleanContext *_localctx = _tracker.createInstance<BooleanContext>(_ctx, getState());
  enterRule(_localctx, 40, fxParser::RuleBoolean);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    _la = _input->LA(1);
    if (!(_la == fxParser::T__26

    || _la == fxParser::T__27)) {
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

//----------------- ConstantContext ------------------------------------------------------------------

fxParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t fxParser::ConstantContext::getRuleIndex() const {
  return fxParser::RuleConstant;
}

void fxParser::ConstantContext::copyFrom(ConstantContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ConstBoolContext ------------------------------------------------------------------

fxParser::BooleanContext* fxParser::ConstBoolContext::boolean() {
  return getRuleContext<fxParser::BooleanContext>(0);
}

fxParser::ConstBoolContext::ConstBoolContext(ConstantContext *ctx) { copyFrom(ctx); }

void fxParser::ConstBoolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstBool(this);
}
void fxParser::ConstBoolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstBool(this);
}

antlrcpp::Any fxParser::ConstBoolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitConstBool(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstStrContext ------------------------------------------------------------------

tree::TerminalNode* fxParser::ConstStrContext::STR() {
  return getToken(fxParser::STR, 0);
}

fxParser::ConstStrContext::ConstStrContext(ConstantContext *ctx) { copyFrom(ctx); }

void fxParser::ConstStrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstStr(this);
}
void fxParser::ConstStrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstStr(this);
}

antlrcpp::Any fxParser::ConstStrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitConstStr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstIntContext ------------------------------------------------------------------

tree::TerminalNode* fxParser::ConstIntContext::INT() {
  return getToken(fxParser::INT, 0);
}

fxParser::ConstIntContext::ConstIntContext(ConstantContext *ctx) { copyFrom(ctx); }

void fxParser::ConstIntContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstInt(this);
}
void fxParser::ConstIntContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstInt(this);
}

antlrcpp::Any fxParser::ConstIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitConstInt(this);
  else
    return visitor->visitChildren(this);
}
fxParser::ConstantContext* fxParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 42, fxParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(273);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case fxParser::T__26:
      case fxParser::T__27: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<fxParser::ConstBoolContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(270);
        boolean();
        break;
      }

      case fxParser::INT: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<fxParser::ConstIntContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(271);
        match(fxParser::INT);
        break;
      }

      case fxParser::STR: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<fxParser::ConstStrContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(272);
        match(fxParser::STR);
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

//----------------- BinOpContext ------------------------------------------------------------------

fxParser::BinOpContext::BinOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t fxParser::BinOpContext::getRuleIndex() const {
  return fxParser::RuleBinOp;
}

void fxParser::BinOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinOp(this);
}

void fxParser::BinOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<fxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinOp(this);
}


antlrcpp::Any fxParser::BinOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<fxVisitor*>(visitor))
    return parserVisitor->visitBinOp(this);
  else
    return visitor->visitChildren(this);
}

fxParser::BinOpContext* fxParser::binOp() {
  BinOpContext *_localctx = _tracker.createInstance<BinOpContext>(_ctx, getState());
  enterRule(_localctx, 44, fxParser::RuleBinOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__28)
      | (1ULL << fxParser::T__29)
      | (1ULL << fxParser::T__30)
      | (1ULL << fxParser::T__31)
      | (1ULL << fxParser::T__32))) != 0))) {
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
  enterRule(_localctx, 46, fxParser::RuleRelOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__13)
      | (1ULL << fxParser::T__14)
      | (1ULL << fxParser::T__33)
      | (1ULL << fxParser::T__34)
      | (1ULL << fxParser::T__35)
      | (1ULL << fxParser::T__36))) != 0))) {
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
    case 16: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool fxParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);

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
  "program", "topDef", "funcDef", "targetType", "classDef", "classItem", 
  "arg", "varDef", "block", "stmt", "forStmt", "varAssignDef", "assignStmt", 
  "returnStmt", "ifStmt", "type_", "expr", "paramList", "matrixConst", "matrixLine", 
  "boolean", "constant", "binOp", "relOp"
};

std::vector<std::string> fxParser::_literalNames = {
  "", "'('", "')'", "'@kernel'", "'@host'", "'class'", "'extends'", "'{'", 
  "'}'", "';'", "','", "'for'", "'='", "'matrix'", "'<'", "'>'", "'['", 
  "']'", "'return'", "'if'", "'else'", "'int'", "'str'", "'bool'", "'void'", 
  "'&&'", "'||'", "'true'", "'false'", "'+'", "'-'", "'*'", "'/'", "'%'", 
  "'<='", "'>='", "'=='", "'!='"
};

std::vector<std::string> fxParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "COMMENT", "MULTICOMMENT", "INT", "ID", "WS", "STR"
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
    0x3, 0x2d, 0x11a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x3, 0x2, 0x6, 0x2, 0x34, 0xa, 0x2, 0xd, 
    0x2, 0xe, 0x2, 0x35, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x3a, 0xa, 0x3, 0x3, 
    0x4, 0x5, 0x4, 0x3d, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0x43, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x4e, 0xa, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x52, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x55, 
    0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x61, 0xa, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x66, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x7, 0x8, 0x6b, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x6e, 0xb, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x75, 0xa, 
    0xa, 0xc, 0xa, 0xe, 0xa, 0x78, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x5, 0xb, 0x85, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 
    0xc, 0x8a, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0x90, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0xb3, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 
    0xc0, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xd0, 0xa, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xd7, 0xa, 0x11, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xdd, 0xa, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xe2, 0xa, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 
    0x12, 0xf2, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xf5, 0xb, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xfa, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 
    0xfd, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x102, 
    0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x105, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x7, 0x15, 0x10a, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x10d, 
    0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 
    0x17, 0x114, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x2, 0x3, 0x22, 0x1a, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
    0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x2, 0x6, 0x3, 0x2, 0x5, 0x6, 0x3, 0x2, 
    0x1d, 0x1e, 0x3, 0x2, 0x1f, 0x23, 0x4, 0x2, 0x10, 0x11, 0x24, 0x27, 
    0x2, 0x128, 0x2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x4, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x8, 0x47, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0xc, 0x65, 0x3, 0x2, 0x2, 0x2, 0xe, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x12, 0x72, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x84, 0x3, 0x2, 0x2, 0x2, 0x16, 0x86, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xb2, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xb4, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xcf, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xd6, 0x3, 0x2, 0x2, 0x2, 0x22, 0xe1, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xf6, 0x3, 0x2, 0x2, 0x2, 0x26, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x28, 0x106, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x113, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x115, 0x3, 0x2, 0x2, 0x2, 0x30, 0x117, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x34, 0x5, 0x4, 0x3, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x3, 0x3, 0x2, 0x2, 0x2, 0x37, 
    0x3a, 0x5, 0x6, 0x4, 0x2, 0x38, 0x3a, 0x5, 0xa, 0x6, 0x2, 0x39, 0x37, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x3b, 0x3d, 0x5, 0x8, 0x5, 0x2, 0x3c, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x3f, 0x5, 0x20, 0x11, 0x2, 0x3f, 0x40, 0x7, 0x2b, 0x2, 0x2, 
    0x40, 0x42, 0x7, 0x3, 0x2, 0x2, 0x41, 0x43, 0x5, 0xe, 0x8, 0x2, 0x42, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x4, 0x2, 0x2, 0x45, 0x46, 0x5, 
    0x12, 0xa, 0x2, 0x46, 0x7, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x9, 0x2, 
    0x2, 0x2, 0x48, 0x9, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x7, 0x2, 
    0x2, 0x4a, 0x4d, 0x7, 0x2b, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x8, 0x2, 0x2, 
    0x4c, 0x4e, 0x7, 0x2b, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4d, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x53, 
    0x7, 0x9, 0x2, 0x2, 0x50, 0x52, 0x5, 0xc, 0x7, 0x2, 0x51, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x55, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 0xa, 0x2, 0x2, 
    0x57, 0xb, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x5, 0x20, 0x11, 0x2, 0x59, 
    0x5a, 0x7, 0x2b, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0xb, 0x2, 0x2, 0x5b, 0x66, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0x20, 0x11, 0x2, 0x5d, 0x5e, 0x7, 
    0x2b, 0x2, 0x2, 0x5e, 0x60, 0x7, 0x3, 0x2, 0x2, 0x5f, 0x61, 0x5, 0xe, 
    0x8, 0x2, 0x60, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0x4, 0x2, 0x2, 
    0x63, 0x64, 0x5, 0x12, 0xa, 0x2, 0x64, 0x66, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0x65, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x66, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x6c, 0x5, 0x10, 0x9, 0x2, 0x68, 0x69, 0x7, 
    0xc, 0x2, 0x2, 0x69, 0x6b, 0x5, 0x10, 0x9, 0x2, 0x6a, 0x68, 0x3, 0x2, 
    0x2, 0x2, 0x6b, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x5, 0x20, 0x11, 0x2, 0x70, 
    0x71, 0x7, 0x2b, 0x2, 0x2, 0x71, 0x11, 0x3, 0x2, 0x2, 0x2, 0x72, 0x76, 
    0x7, 0x9, 0x2, 0x2, 0x73, 0x75, 0x5, 0x14, 0xb, 0x2, 0x74, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x75, 0x78, 0x3, 0x2, 0x2, 0x2, 0x76, 0x74, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x7, 0xa, 0x2, 0x2, 
    0x7a, 0x13, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x85, 0x7, 0xb, 0x2, 0x2, 0x7c, 
    0x85, 0x5, 0x18, 0xd, 0x2, 0x7d, 0x85, 0x5, 0x1a, 0xe, 0x2, 0x7e, 0x85, 
    0x5, 0x1c, 0xf, 0x2, 0x7f, 0x85, 0x5, 0x1e, 0x10, 0x2, 0x80, 0x85, 0x5, 
    0x16, 0xc, 0x2, 0x81, 0x82, 0x5, 0x22, 0x12, 0x2, 0x82, 0x83, 0x7, 0xb, 
    0x2, 0x2, 0x83, 0x85, 0x3, 0x2, 0x2, 0x2, 0x84, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x84, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x84, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x84, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x80, 0x3, 0x2, 0x2, 0x2, 0x84, 0x81, 0x3, 0x2, 0x2, 0x2, 0x85, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x7, 0xd, 0x2, 0x2, 0x87, 0x89, 0x7, 
    0x3, 0x2, 0x2, 0x88, 0x8a, 0x5, 0x22, 0x12, 0x2, 0x89, 0x88, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 0x2, 
    0x2, 0x8b, 0x8c, 0x7, 0xb, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x22, 0x12, 0x2, 
    0x8d, 0x8f, 0x7, 0xb, 0x2, 0x2, 0x8e, 0x90, 0x5, 0x22, 0x12, 0x2, 0x8f, 
    0x8e, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 
    0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x7, 0x4, 0x2, 0x2, 0x92, 0x93, 0x5, 
    0x12, 0xa, 0x2, 0x93, 0x17, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x5, 0x20, 
    0x11, 0x2, 0x95, 0x96, 0x7, 0x2b, 0x2, 0x2, 0x96, 0x97, 0x7, 0xb, 0x2, 
    0x2, 0x97, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x5, 0x20, 0x11, 0x2, 
    0x99, 0x9a, 0x7, 0x2b, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0xe, 0x2, 0x2, 0x9b, 
    0x9c, 0x5, 0x22, 0x12, 0x2, 0x9c, 0x9d, 0x7, 0xb, 0x2, 0x2, 0x9d, 0xb3, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0xf, 0x2, 0x2, 0x9f, 0xa0, 0x7, 
    0x2b, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x10, 0x2, 0x2, 0xa1, 0xa2, 0x5, 0x20, 
    0x11, 0x2, 0xa2, 0xa3, 0x7, 0x11, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x3, 0x2, 
    0x2, 0xa4, 0xa5, 0x7, 0x2a, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0xc, 0x2, 0x2, 
    0xa6, 0xa7, 0x7, 0x2a, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x4, 0x2, 0x2, 0xa8, 
    0xa9, 0x7, 0xb, 0x2, 0x2, 0xa9, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 
    0x7, 0xf, 0x2, 0x2, 0xab, 0xac, 0x7, 0x2b, 0x2, 0x2, 0xac, 0xad, 0x7, 
    0xe, 0x2, 0x2, 0xad, 0xae, 0x7, 0x12, 0x2, 0x2, 0xae, 0xaf, 0x5, 0x26, 
    0x14, 0x2, 0xaf, 0xb0, 0x7, 0x13, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0xb, 0x2, 
    0x2, 0xb1, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x94, 0x3, 0x2, 0x2, 0x2, 
    0xb2, 0x98, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xb2, 
    0xaa, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x19, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 
    0x5, 0x22, 0x12, 0x2, 0xb5, 0xb6, 0x7, 0xe, 0x2, 0x2, 0xb6, 0xb7, 0x5, 
    0x22, 0x12, 0x2, 0xb7, 0xb8, 0x7, 0xb, 0x2, 0x2, 0xb8, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0xb9, 0xba, 0x7, 0x14, 0x2, 0x2, 0xba, 0xbb, 0x5, 0x22, 0x12, 
    0x2, 0xbb, 0xbc, 0x7, 0xb, 0x2, 0x2, 0xbc, 0xc0, 0x3, 0x2, 0x2, 0x2, 
    0xbd, 0xbe, 0x7, 0x14, 0x2, 0x2, 0xbe, 0xc0, 0x7, 0xb, 0x2, 0x2, 0xbf, 
    0xb9, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x15, 0x2, 0x2, 0xc2, 0xc3, 0x7, 
    0x3, 0x2, 0x2, 0xc3, 0xc4, 0x5, 0x22, 0x12, 0x2, 0xc4, 0xc5, 0x7, 0x4, 
    0x2, 0x2, 0xc5, 0xc6, 0x5, 0x12, 0xa, 0x2, 0xc6, 0xd0, 0x3, 0x2, 0x2, 
    0x2, 0xc7, 0xc8, 0x7, 0x15, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x3, 0x2, 0x2, 
    0xc9, 0xca, 0x5, 0x22, 0x12, 0x2, 0xca, 0xcb, 0x7, 0x4, 0x2, 0x2, 0xcb, 
    0xcc, 0x5, 0x12, 0xa, 0x2, 0xcc, 0xcd, 0x7, 0x16, 0x2, 0x2, 0xcd, 0xce, 
    0x5, 0x12, 0xa, 0x2, 0xce, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc1, 0x3, 
    0x2, 0x2, 0x2, 0xcf, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xd0, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0xd1, 0xd7, 0x7, 0x17, 0x2, 0x2, 0xd2, 0xd7, 0x7, 0x18, 0x2, 
    0x2, 0xd3, 0xd7, 0x7, 0x19, 0x2, 0x2, 0xd4, 0xd7, 0x7, 0x1a, 0x2, 0x2, 
    0xd5, 0xd7, 0x7, 0x2b, 0x2, 0x2, 0xd6, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd6, 
    0xd2, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xd6, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0xd8, 0xd9, 0x8, 0x12, 0x1, 0x2, 0xd9, 0xda, 0x7, 0x2b, 
    0x2, 0x2, 0xda, 0xdc, 0x7, 0x3, 0x2, 0x2, 0xdb, 0xdd, 0x5, 0x24, 0x13, 
    0x2, 0xdc, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0xe2, 0x7, 0x4, 0x2, 0x2, 0xdf, 
    0xe2, 0x7, 0x2b, 0x2, 0x2, 0xe0, 0xe2, 0x5, 0x2c, 0x17, 0x2, 0xe1, 0xd8, 
    0x3, 0x2, 0x2, 0x2, 0xe1, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0xc, 0x9, 
    0x2, 0x2, 0xe4, 0xe5, 0x5, 0x2e, 0x18, 0x2, 0xe5, 0xe6, 0x5, 0x22, 0x12, 
    0xa, 0xe6, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0xc, 0x8, 0x2, 0x2, 
    0xe8, 0xe9, 0x5, 0x30, 0x19, 0x2, 0xe9, 0xea, 0x5, 0x22, 0x12, 0x9, 
    0xea, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0xc, 0x7, 0x2, 0x2, 0xec, 
    0xed, 0x7, 0x1b, 0x2, 0x2, 0xed, 0xf2, 0x5, 0x22, 0x12, 0x7, 0xee, 0xef, 
    0xc, 0x6, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x1c, 0x2, 0x2, 0xf0, 0xf2, 0x5, 
    0x22, 0x12, 0x6, 0xf1, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe7, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xee, 0x3, 0x2, 0x2, 
    0x2, 0xf2, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 0x3, 0x2, 0x2, 0x2, 
    0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0x23, 0x3, 0x2, 0x2, 0x2, 0xf5, 
    0xf3, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xfb, 0x5, 0x22, 0x12, 0x2, 0xf7, 0xf8, 
    0x7, 0xc, 0x2, 0x2, 0xf8, 0xfa, 0x5, 0x22, 0x12, 0x2, 0xf9, 0xf7, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 
    0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x103, 0x5, 0x28, 0x15, 0x2, 
    0xff, 0x100, 0x7, 0xb, 0x2, 0x2, 0x100, 0x102, 0x5, 0x28, 0x15, 0x2, 
    0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x102, 0x105, 0x3, 0x2, 0x2, 0x2, 0x103, 
    0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 0x2, 0x104, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0x105, 0x103, 0x3, 0x2, 0x2, 0x2, 0x106, 0x10b, 
    0x7, 0x2a, 0x2, 0x2, 0x107, 0x108, 0x7, 0xc, 0x2, 0x2, 0x108, 0x10a, 
    0x7, 0x2a, 0x2, 0x2, 0x109, 0x107, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10d, 
    0x3, 0x2, 0x2, 0x2, 0x10b, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 
    0x3, 0x2, 0x2, 0x2, 0x10c, 0x29, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10b, 0x3, 
    0x2, 0x2, 0x2, 0x10e, 0x10f, 0x9, 0x3, 0x2, 0x2, 0x10f, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x110, 0x114, 0x5, 0x2a, 0x16, 0x2, 0x111, 0x114, 0x7, 0x2a, 
    0x2, 0x2, 0x112, 0x114, 0x7, 0x2d, 0x2, 0x2, 0x113, 0x110, 0x3, 0x2, 
    0x2, 0x2, 0x113, 0x111, 0x3, 0x2, 0x2, 0x2, 0x113, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x114, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x9, 0x4, 0x2, 
    0x2, 0x116, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x9, 0x5, 0x2, 0x2, 
    0x118, 0x31, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x35, 0x39, 0x3c, 0x42, 0x4d, 
    0x53, 0x60, 0x65, 0x6c, 0x76, 0x84, 0x89, 0x8f, 0xb2, 0xbf, 0xcf, 0xd6, 
    0xdc, 0xe1, 0xf1, 0xf3, 0xfb, 0x103, 0x10b, 0x113, 
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
