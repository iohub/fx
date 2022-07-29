
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
    setState(43); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(42);
      topDef();
      setState(45); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__2)
      | (1ULL << fxParser::T__13)
      | (1ULL << fxParser::T__14)
      | (1ULL << fxParser::T__15)
      | (1ULL << fxParser::T__16)
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
    setState(49);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case fxParser::T__13:
      case fxParser::T__14:
      case fxParser::T__15:
      case fxParser::T__16:
      case fxParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(47);
        funcDef();
        break;
      }

      case fxParser::T__2: {
        enterOuterAlt(_localctx, 2);
        setState(48);
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
    setState(51);
    type_();
    setState(52);
    match(fxParser::ID);
    setState(53);
    match(fxParser::T__0);
    setState(55);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__13)
      | (1ULL << fxParser::T__14)
      | (1ULL << fxParser::T__15)
      | (1ULL << fxParser::T__16)
      | (1ULL << fxParser::ID))) != 0)) {
      setState(54);
      arg();
    }
    setState(57);
    match(fxParser::T__1);
    setState(58);
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
    setState(60);
    match(fxParser::T__2);
    setState(61);
    match(fxParser::ID);
    setState(64);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == fxParser::T__3) {
      setState(62);
      match(fxParser::T__3);
      setState(63);
      match(fxParser::ID);
    }
    setState(66);
    match(fxParser::T__4);
    setState(70);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__13)
      | (1ULL << fxParser::T__14)
      | (1ULL << fxParser::T__15)
      | (1ULL << fxParser::T__16)
      | (1ULL << fxParser::ID))) != 0)) {
      setState(67);
      classItem();
      setState(72);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(73);
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
    setState(88);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ClassItemContext *>(_tracker.createInstance<fxParser::FieldDeclContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(75);
      type_();
      setState(76);
      match(fxParser::ID);
      setState(77);
      match(fxParser::T__6);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ClassItemContext *>(_tracker.createInstance<fxParser::MethodDefContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(79);
      type_();
      setState(80);
      match(fxParser::ID);
      setState(81);
      match(fxParser::T__0);
      setState(83);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << fxParser::T__13)
        | (1ULL << fxParser::T__14)
        | (1ULL << fxParser::T__15)
        | (1ULL << fxParser::T__16)
        | (1ULL << fxParser::ID))) != 0)) {
        setState(82);
        arg();
      }
      setState(85);
      match(fxParser::T__1);
      setState(86);
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
    setState(90);
    varDef();
    setState(95);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == fxParser::T__7) {
      setState(91);
      match(fxParser::T__7);
      setState(92);
      varDef();
      setState(97);
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
    setState(98);
    type_();
    setState(99);
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
    setState(101);
    match(fxParser::T__4);
    setState(105);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__6)
      | (1ULL << fxParser::T__8)
      | (1ULL << fxParser::T__10)
      | (1ULL << fxParser::T__11)
      | (1ULL << fxParser::T__13)
      | (1ULL << fxParser::T__14)
      | (1ULL << fxParser::T__15)
      | (1ULL << fxParser::T__16)
      | (1ULL << fxParser::T__19)
      | (1ULL << fxParser::T__20)
      | (1ULL << fxParser::INT)
      | (1ULL << fxParser::ID)
      | (1ULL << fxParser::STR))) != 0)) {
      setState(102);
      stmt();
      setState(107);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(108);
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

fxParser::ExprContext* fxParser::StmtContext::expr() {
  return getRuleContext<fxParser::ExprContext>(0);
}

fxParser::StmtContext* fxParser::StmtContext::stmt() {
  return getRuleContext<fxParser::StmtContext>(0);
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
  enterRule(_localctx, 16, fxParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(124);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(110);
      match(fxParser::T__6);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(111);
      varAssignDef();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(112);
      assignStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(113);
      returnStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(114);
      ifStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(115);
      match(fxParser::T__8);
      setState(116);
      match(fxParser::T__0);
      setState(117);
      expr(0);
      setState(118);
      match(fxParser::T__1);
      setState(119);
      stmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(121);
      expr(0);
      setState(122);
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

fxParser::DeclContext::DeclContext(VarAssignDefContext *ctx) { copyFrom(ctx); }

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
fxParser::VarAssignDefContext* fxParser::varAssignDef() {
  VarAssignDefContext *_localctx = _tracker.createInstance<VarAssignDefContext>(_ctx, getState());
  enterRule(_localctx, 18, fxParser::RuleVarAssignDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<VarAssignDefContext *>(_tracker.createInstance<fxParser::DeclContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(126);
    type_();
    setState(127);
    item();
    setState(132);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == fxParser::T__7) {
      setState(128);
      match(fxParser::T__7);
      setState(129);
      item();
      setState(134);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(135);
    match(fxParser::T__6);
   
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

//----------------- AssContext ------------------------------------------------------------------

std::vector<fxParser::ExprContext *> fxParser::AssContext::expr() {
  return getRuleContexts<fxParser::ExprContext>();
}

fxParser::ExprContext* fxParser::AssContext::expr(size_t i) {
  return getRuleContext<fxParser::ExprContext>(i);
}

fxParser::AssContext::AssContext(AssignStmtContext *ctx) { copyFrom(ctx); }

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
fxParser::AssignStmtContext* fxParser::assignStmt() {
  AssignStmtContext *_localctx = _tracker.createInstance<AssignStmtContext>(_ctx, getState());
  enterRule(_localctx, 20, fxParser::RuleAssignStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<AssignStmtContext *>(_tracker.createInstance<fxParser::AssContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(137);
    expr(0);
    setState(138);
    match(fxParser::T__9);
    setState(139);
    expr(0);
    setState(140);
    match(fxParser::T__6);
   
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
  enterRule(_localctx, 22, fxParser::RuleReturnStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(148);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(142);
      match(fxParser::T__10);
      setState(143);
      expr(0);
      setState(144);
      match(fxParser::T__6);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(146);
      match(fxParser::T__10);
      setState(147);
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
  enterRule(_localctx, 24, fxParser::RuleIfStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(164);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(150);
      match(fxParser::T__11);
      setState(151);
      match(fxParser::T__0);
      setState(152);
      expr(0);
      setState(153);
      match(fxParser::T__1);
      setState(154);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(156);
      match(fxParser::T__11);
      setState(157);
      match(fxParser::T__0);
      setState(158);
      expr(0);
      setState(159);
      match(fxParser::T__1);
      setState(160);
      block();
      setState(161);
      match(fxParser::T__12);
      setState(162);
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
  enterRule(_localctx, 26, fxParser::RuleType_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(171);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case fxParser::T__13: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::IntContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(166);
        match(fxParser::T__13);
        break;
      }

      case fxParser::T__14: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::StrContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(167);
        match(fxParser::T__14);
        break;
      }

      case fxParser::T__15: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::BoolContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(168);
        match(fxParser::T__15);
        break;
      }

      case fxParser::T__16: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::VoidContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(169);
        match(fxParser::T__16);
        break;
      }

      case fxParser::ID: {
        _localctx = dynamic_cast<Type_Context *>(_tracker.createInstance<fxParser::ClassNameContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(170);
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
  enterRule(_localctx, 28, fxParser::RuleItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(173);
      match(fxParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(174);
      match(fxParser::ID);
      setState(175);
      match(fxParser::T__9);
      setState(176);
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
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, fxParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(188);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(180);
      match(fxParser::ID);
      setState(181);
      match(fxParser::T__0);
      setState(183);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << fxParser::T__19)
        | (1ULL << fxParser::T__20)
        | (1ULL << fxParser::INT)
        | (1ULL << fxParser::ID)
        | (1ULL << fxParser::STR))) != 0)) {
        setState(182);
        paramList();
      }
      setState(185);
      match(fxParser::T__1);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<IDExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(186);
      match(fxParser::ID);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ConstExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(187);
      constant();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(206);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(204);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinOpExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(190);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(191);
          binOp();
          setState(192);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<RelOpExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(194);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(195);
          relOp();
          setState(196);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(198);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(199);
          match(fxParser::T__17);
          setState(200);
          expr(5);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(201);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(202);
          match(fxParser::T__18);
          setState(203);
          expr(4);
          break;
        }

        } 
      }
      setState(208);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
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
  enterRule(_localctx, 32, fxParser::RuleParamList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    expr(0);
    setState(214);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == fxParser::T__7) {
      setState(210);
      match(fxParser::T__7);
      setState(211);
      expr(0);
      setState(216);
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
  enterRule(_localctx, 34, fxParser::RuleBoolean);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    _la = _input->LA(1);
    if (!(_la == fxParser::T__19

    || _la == fxParser::T__20)) {
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
  enterRule(_localctx, 36, fxParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(222);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case fxParser::T__19:
      case fxParser::T__20: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<fxParser::ConstBoolContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(219);
        boolean();
        break;
      }

      case fxParser::INT: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<fxParser::ConstIntContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(220);
        match(fxParser::INT);
        break;
      }

      case fxParser::STR: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<fxParser::ConstStrContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(221);
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
  enterRule(_localctx, 38, fxParser::RuleBinOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__21)
      | (1ULL << fxParser::T__22)
      | (1ULL << fxParser::T__23)
      | (1ULL << fxParser::T__24)
      | (1ULL << fxParser::T__25))) != 0))) {
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
  enterRule(_localctx, 40, fxParser::RuleRelOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << fxParser::T__26)
      | (1ULL << fxParser::T__27)
      | (1ULL << fxParser::T__28)
      | (1ULL << fxParser::T__29)
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

bool fxParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 15: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

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
  "program", "topDef", "funcDef", "classDef", "classItem", "arg", "varDef", 
  "block", "stmt", "varAssignDef", "assignStmt", "returnStmt", "ifStmt", 
  "type_", "item", "expr", "paramList", "boolean", "constant", "binOp", 
  "relOp"
};

std::vector<std::string> fxParser::_literalNames = {
  "", "'('", "')'", "'class'", "'extends'", "'{'", "'}'", "';'", "','", 
  "'while'", "'='", "'return'", "'if'", "'else'", "'int'", "'str'", "'bool'", 
  "'void'", "'&&'", "'||'", "'true'", "'false'", "'+'", "'-'", "'*'", "'/'", 
  "'%'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='"
};

std::vector<std::string> fxParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "COMMENT", 
  "MULTICOMMENT", "INT", "ID", "WS", "STR"
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
    0x3, 0x28, 0xe7, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x3, 0x2, 0x6, 0x2, 0x2e, 0xa, 0x2, 0xd, 
    0x2, 0xe, 0x2, 0x2f, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x34, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x3a, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x43, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x47, 0xa, 0x5, 0xc, 0x5, 
    0xe, 0x5, 0x4a, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x56, 
    0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x5b, 0xa, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x60, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 
    0x63, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x7, 
    0x9, 0x6a, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x6d, 0xb, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x5, 0xa, 0x7f, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x7, 0xb, 0x85, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x88, 0xb, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x97, 0xa, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x5, 0xe, 0xa7, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x5, 0xf, 0xae, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x5, 0x10, 0xb4, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0xba, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0xbf, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0xcf, 0xa, 0x11, 0xc, 
    0x11, 0xe, 0x11, 0xd2, 0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 
    0x12, 0xd7, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xda, 0xb, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xe1, 0xa, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x2, 0x3, 0x20, 
    0x17, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2, 0x5, 0x3, 
    0x2, 0x16, 0x17, 0x3, 0x2, 0x18, 0x1c, 0x3, 0x2, 0x1d, 0x22, 0x2, 0xf2, 
    0x2, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x4, 0x33, 0x3, 0x2, 0x2, 0x2, 0x6, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x3e, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x5c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x64, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x67, 0x3, 0x2, 0x2, 0x2, 0x12, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x80, 0x3, 0x2, 0x2, 0x2, 0x16, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x96, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xad, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x20, 0xbe, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x24, 0xdb, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x28, 0xe2, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2e, 0x5, 0x4, 0x3, 0x2, 0x2d, 
    0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x34, 0x5, 0x6, 0x4, 0x2, 0x32, 0x34, 0x5, 0x8, 
    0x5, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x5, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x5, 0x1c, 0xf, 0x2, 
    0x36, 0x37, 0x7, 0x26, 0x2, 0x2, 0x37, 0x39, 0x7, 0x3, 0x2, 0x2, 0x38, 
    0x3a, 0x5, 0xc, 0x7, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 
    0x4, 0x2, 0x2, 0x3c, 0x3d, 0x5, 0x10, 0x9, 0x2, 0x3d, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0x3f, 0x7, 0x5, 0x2, 0x2, 0x3f, 0x42, 0x7, 0x26, 0x2, 
    0x2, 0x40, 0x41, 0x7, 0x6, 0x2, 0x2, 0x41, 0x43, 0x7, 0x26, 0x2, 0x2, 
    0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 
    0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0x48, 0x7, 0x7, 0x2, 0x2, 0x45, 0x47, 
    0x5, 0xa, 0x6, 0x2, 0x46, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x49, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 
    0x2, 0x4b, 0x4c, 0x7, 0x8, 0x2, 0x2, 0x4c, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x4e, 0x5, 0x1c, 0xf, 0x2, 0x4e, 0x4f, 0x7, 0x26, 0x2, 0x2, 0x4f, 
    0x50, 0x7, 0x9, 0x2, 0x2, 0x50, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 
    0x5, 0x1c, 0xf, 0x2, 0x52, 0x53, 0x7, 0x26, 0x2, 0x2, 0x53, 0x55, 0x7, 
    0x3, 0x2, 0x2, 0x54, 0x56, 0x5, 0xc, 0x7, 0x2, 0x55, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 
    0x2, 0x57, 0x58, 0x7, 0x4, 0x2, 0x2, 0x58, 0x59, 0x5, 0x10, 0x9, 0x2, 
    0x59, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x5b, 0xb, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x61, 
    0x5, 0xe, 0x8, 0x2, 0x5d, 0x5e, 0x7, 0xa, 0x2, 0x2, 0x5e, 0x60, 0x5, 
    0xe, 0x8, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x60, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 
    0x2, 0x62, 0xd, 0x3, 0x2, 0x2, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x65, 0x5, 0x1c, 0xf, 0x2, 0x65, 0x66, 0x7, 0x26, 0x2, 0x2, 0x66, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x67, 0x6b, 0x7, 0x7, 0x2, 0x2, 0x68, 0x6a, 
    0x5, 0x12, 0xa, 0x2, 0x69, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6d, 0x3, 
    0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x6f, 0x7, 0x8, 0x2, 0x2, 0x6f, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x7f, 0x7, 0x9, 0x2, 0x2, 0x71, 0x7f, 0x5, 0x14, 0xb, 0x2, 0x72, 
    0x7f, 0x5, 0x16, 0xc, 0x2, 0x73, 0x7f, 0x5, 0x18, 0xd, 0x2, 0x74, 0x7f, 
    0x5, 0x1a, 0xe, 0x2, 0x75, 0x76, 0x7, 0xb, 0x2, 0x2, 0x76, 0x77, 0x7, 
    0x3, 0x2, 0x2, 0x77, 0x78, 0x5, 0x20, 0x11, 0x2, 0x78, 0x79, 0x7, 0x4, 
    0x2, 0x2, 0x79, 0x7a, 0x5, 0x12, 0xa, 0x2, 0x7a, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x7b, 0x7c, 0x5, 0x20, 0x11, 0x2, 0x7c, 0x7d, 0x7, 0x9, 0x2, 0x2, 
    0x7d, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x70, 0x3, 0x2, 0x2, 0x2, 0x7e, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x72, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x73, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x74, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x75, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x81, 0x5, 0x1c, 0xf, 0x2, 0x81, 0x86, 0x5, 0x1e, 0x10, 
    0x2, 0x82, 0x83, 0x7, 0xa, 0x2, 0x2, 0x83, 0x85, 0x5, 0x1e, 0x10, 0x2, 
    0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 0x85, 0x88, 0x3, 0x2, 0x2, 0x2, 0x86, 
    0x84, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 0x89, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x7, 
    0x9, 0x2, 0x2, 0x8a, 0x15, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x5, 0x20, 
    0x11, 0x2, 0x8c, 0x8d, 0x7, 0xc, 0x2, 0x2, 0x8d, 0x8e, 0x5, 0x20, 0x11, 
    0x2, 0x8e, 0x8f, 0x7, 0x9, 0x2, 0x2, 0x8f, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x90, 0x91, 0x7, 0xd, 0x2, 0x2, 0x91, 0x92, 0x5, 0x20, 0x11, 0x2, 0x92, 
    0x93, 0x7, 0x9, 0x2, 0x2, 0x93, 0x97, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 
    0x7, 0xd, 0x2, 0x2, 0x95, 0x97, 0x7, 0x9, 0x2, 0x2, 0x96, 0x90, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x94, 0x3, 0x2, 0x2, 0x2, 0x97, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x99, 0x7, 0xe, 0x2, 0x2, 0x99, 0x9a, 0x7, 0x3, 0x2, 
    0x2, 0x9a, 0x9b, 0x5, 0x20, 0x11, 0x2, 0x9b, 0x9c, 0x7, 0x4, 0x2, 0x2, 
    0x9c, 0x9d, 0x5, 0x10, 0x9, 0x2, 0x9d, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x9e, 
    0x9f, 0x7, 0xe, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x3, 0x2, 0x2, 0xa0, 0xa1, 
    0x5, 0x20, 0x11, 0x2, 0xa1, 0xa2, 0x7, 0x4, 0x2, 0x2, 0xa2, 0xa3, 0x5, 
    0x10, 0x9, 0x2, 0xa3, 0xa4, 0x7, 0xf, 0x2, 0x2, 0xa4, 0xa5, 0x5, 0x10, 
    0x9, 0x2, 0xa5, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x98, 0x3, 0x2, 0x2, 
    0x2, 0xa6, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0xae, 0x7, 0x10, 0x2, 0x2, 0xa9, 0xae, 0x7, 0x11, 0x2, 0x2, 0xaa, 
    0xae, 0x7, 0x12, 0x2, 0x2, 0xab, 0xae, 0x7, 0x13, 0x2, 0x2, 0xac, 0xae, 
    0x7, 0x26, 0x2, 0x2, 0xad, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xad, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0xad, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0xac, 0x3, 0x2, 0x2, 0x2, 0xae, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0xb4, 0x7, 0x26, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0x26, 0x2, 0x2, 
    0xb1, 0xb2, 0x7, 0xc, 0x2, 0x2, 0xb2, 0xb4, 0x5, 0x20, 0x11, 0x2, 0xb3, 
    0xaf, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x8, 0x11, 0x1, 0x2, 0xb6, 0xb7, 0x7, 
    0x26, 0x2, 0x2, 0xb7, 0xb9, 0x7, 0x3, 0x2, 0x2, 0xb8, 0xba, 0x5, 0x22, 
    0x12, 0x2, 0xb9, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 
    0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbf, 0x7, 0x4, 0x2, 0x2, 
    0xbc, 0xbf, 0x7, 0x26, 0x2, 0x2, 0xbd, 0xbf, 0x5, 0x26, 0x14, 0x2, 0xbe, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbd, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0xc, 
    0x9, 0x2, 0x2, 0xc1, 0xc2, 0x5, 0x28, 0x15, 0x2, 0xc2, 0xc3, 0x5, 0x20, 
    0x11, 0xa, 0xc3, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0xc, 0x8, 0x2, 
    0x2, 0xc5, 0xc6, 0x5, 0x2a, 0x16, 0x2, 0xc6, 0xc7, 0x5, 0x20, 0x11, 
    0x9, 0xc7, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0xc, 0x7, 0x2, 0x2, 
    0xc9, 0xca, 0x7, 0x14, 0x2, 0x2, 0xca, 0xcf, 0x5, 0x20, 0x11, 0x7, 0xcb, 
    0xcc, 0xc, 0x6, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x15, 0x2, 0x2, 0xcd, 0xcf, 
    0x5, 0x20, 0x11, 0x6, 0xce, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xce, 0xc4, 0x3, 
    0x2, 0x2, 0x2, 0xce, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcb, 0x3, 0x2, 
    0x2, 0x2, 0xcf, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 
    0x2, 0xd0, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd1, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0xd2, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd8, 0x5, 0x20, 0x11, 0x2, 0xd4, 
    0xd5, 0x7, 0xa, 0x2, 0x2, 0xd5, 0xd7, 0x5, 0x20, 0x11, 0x2, 0xd6, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 
    0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd9, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x9, 0x2, 0x2, 
    0x2, 0xdc, 0x25, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xe1, 0x5, 0x24, 0x13, 0x2, 
    0xde, 0xe1, 0x7, 0x25, 0x2, 0x2, 0xdf, 0xe1, 0x7, 0x28, 0x2, 0x2, 0xe0, 
    0xdd, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xdf, 
    0x3, 0x2, 0x2, 0x2, 0xe1, 0x27, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x9, 
    0x3, 0x2, 0x2, 0xe3, 0x29, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x9, 0x4, 
    0x2, 0x2, 0xe5, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x17, 0x2f, 0x33, 0x39, 0x42, 
    0x48, 0x55, 0x5a, 0x61, 0x6b, 0x7e, 0x86, 0x96, 0xa6, 0xad, 0xb3, 0xb9, 
    0xbe, 0xce, 0xd0, 0xd8, 0xe0, 
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
