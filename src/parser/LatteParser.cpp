
// Generated from Latte.g4 by ANTLR 4.7


#include "LatteListener.h"
#include "LatteVisitor.h"

#include "LatteParser.h"


using namespace antlrcpp;
using namespace antlr4;

LatteParser::LatteParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

LatteParser::~LatteParser() {
  delete _interpreter;
}

std::string LatteParser::getGrammarFileName() const {
  return "Latte.g4";
}

const std::vector<std::string>& LatteParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& LatteParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

LatteParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LatteParser::TopDefContext *> LatteParser::ProgramContext::topDef() {
  return getRuleContexts<LatteParser::TopDefContext>();
}

LatteParser::TopDefContext* LatteParser::ProgramContext::topDef(size_t i) {
  return getRuleContext<LatteParser::TopDefContext>(i);
}


size_t LatteParser::ProgramContext::getRuleIndex() const {
  return LatteParser::RuleProgram;
}

void LatteParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void LatteParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any LatteParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

LatteParser::ProgramContext* LatteParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, LatteParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(28);
      topDef();
      setState(31); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LatteParser::T__2)
      | (1ULL << LatteParser::T__20)
      | (1ULL << LatteParser::T__21)
      | (1ULL << LatteParser::T__22)
      | (1ULL << LatteParser::T__23)
      | (1ULL << LatteParser::ID))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

LatteParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::Type_Context* LatteParser::FuncDefContext::type_() {
  return getRuleContext<LatteParser::Type_Context>(0);
}

tree::TerminalNode* LatteParser::FuncDefContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::BlockContext* LatteParser::FuncDefContext::block() {
  return getRuleContext<LatteParser::BlockContext>(0);
}

LatteParser::ArgContext* LatteParser::FuncDefContext::arg() {
  return getRuleContext<LatteParser::ArgContext>(0);
}


size_t LatteParser::FuncDefContext::getRuleIndex() const {
  return LatteParser::RuleFuncDef;
}

void LatteParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void LatteParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}


antlrcpp::Any LatteParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

LatteParser::FuncDefContext* LatteParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 2, LatteParser::RuleFuncDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    type_(0);
    setState(34);
    match(LatteParser::ID);
    setState(35);
    match(LatteParser::T__0);
    setState(37);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LatteParser::T__20)
      | (1ULL << LatteParser::T__21)
      | (1ULL << LatteParser::T__22)
      | (1ULL << LatteParser::T__23)
      | (1ULL << LatteParser::ID))) != 0)) {
      setState(36);
      arg();
    }
    setState(39);
    match(LatteParser::T__1);
    setState(40);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TopDefContext ------------------------------------------------------------------

LatteParser::TopDefContext::TopDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LatteParser::TopDefContext::getRuleIndex() const {
  return LatteParser::RuleTopDef;
}

void LatteParser::TopDefContext::copyFrom(TopDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ClassDefContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> LatteParser::ClassDefContext::ID() {
  return getTokens(LatteParser::ID);
}

tree::TerminalNode* LatteParser::ClassDefContext::ID(size_t i) {
  return getToken(LatteParser::ID, i);
}

LatteParser::ClassBodyContext* LatteParser::ClassDefContext::classBody() {
  return getRuleContext<LatteParser::ClassBodyContext>(0);
}

LatteParser::ClassDefContext::ClassDefContext(TopDefContext *ctx) { copyFrom(ctx); }

void LatteParser::ClassDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDef(this);
}
void LatteParser::ClassDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDef(this);
}

antlrcpp::Any LatteParser::ClassDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitClassDef(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunTopDefContext ------------------------------------------------------------------

LatteParser::FuncDefContext* LatteParser::FunTopDefContext::funcDef() {
  return getRuleContext<LatteParser::FuncDefContext>(0);
}

LatteParser::FunTopDefContext::FunTopDefContext(TopDefContext *ctx) { copyFrom(ctx); }

void LatteParser::FunTopDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunTopDef(this);
}
void LatteParser::FunTopDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunTopDef(this);
}

antlrcpp::Any LatteParser::FunTopDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitFunTopDef(this);
  else
    return visitor->visitChildren(this);
}
LatteParser::TopDefContext* LatteParser::topDef() {
  TopDefContext *_localctx = _tracker.createInstance<TopDefContext>(_ctx, getState());
  enterRule(_localctx, 4, LatteParser::RuleTopDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(50);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LatteParser::T__20:
      case LatteParser::T__21:
      case LatteParser::T__22:
      case LatteParser::T__23:
      case LatteParser::ID: {
        _localctx = dynamic_cast<TopDefContext *>(_tracker.createInstance<LatteParser::FunTopDefContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(42);
        funcDef();
        break;
      }

      case LatteParser::T__2: {
        _localctx = dynamic_cast<TopDefContext *>(_tracker.createInstance<LatteParser::ClassDefContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(43);
        match(LatteParser::T__2);
        setState(44);
        match(LatteParser::ID);
        setState(47);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == LatteParser::T__3) {
          setState(45);
          match(LatteParser::T__3);
          setState(46);
          match(LatteParser::ID);
        }
        setState(49);
        classBody();
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

//----------------- ClassItemContext ------------------------------------------------------------------

LatteParser::ClassItemContext::ClassItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LatteParser::ClassItemContext::getRuleIndex() const {
  return LatteParser::RuleClassItem;
}

void LatteParser::ClassItemContext::copyFrom(ClassItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ClassFunDefContext ------------------------------------------------------------------

LatteParser::FuncDefContext* LatteParser::ClassFunDefContext::funcDef() {
  return getRuleContext<LatteParser::FuncDefContext>(0);
}

LatteParser::ClassFunDefContext::ClassFunDefContext(ClassItemContext *ctx) { copyFrom(ctx); }

void LatteParser::ClassFunDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassFunDef(this);
}
void LatteParser::ClassFunDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassFunDef(this);
}

antlrcpp::Any LatteParser::ClassFunDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitClassFunDef(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassVarDefContext ------------------------------------------------------------------

LatteParser::Type_Context* LatteParser::ClassVarDefContext::type_() {
  return getRuleContext<LatteParser::Type_Context>(0);
}

std::vector<LatteParser::ItemContext *> LatteParser::ClassVarDefContext::item() {
  return getRuleContexts<LatteParser::ItemContext>();
}

LatteParser::ItemContext* LatteParser::ClassVarDefContext::item(size_t i) {
  return getRuleContext<LatteParser::ItemContext>(i);
}

LatteParser::ClassVarDefContext::ClassVarDefContext(ClassItemContext *ctx) { copyFrom(ctx); }

void LatteParser::ClassVarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassVarDef(this);
}
void LatteParser::ClassVarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassVarDef(this);
}

antlrcpp::Any LatteParser::ClassVarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitClassVarDef(this);
  else
    return visitor->visitChildren(this);
}
LatteParser::ClassItemContext* LatteParser::classItem() {
  ClassItemContext *_localctx = _tracker.createInstance<ClassItemContext>(_ctx, getState());
  enterRule(_localctx, 6, LatteParser::RuleClassItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(64);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ClassItemContext *>(_tracker.createInstance<LatteParser::ClassFunDefContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(52);
      funcDef();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ClassItemContext *>(_tracker.createInstance<LatteParser::ClassVarDefContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(53);
      type_(0);
      setState(54);
      item();
      setState(59);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LatteParser::T__4) {
        setState(55);
        match(LatteParser::T__4);
        setState(56);
        item();
        setState(61);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(62);
      match(LatteParser::T__5);
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

//----------------- ClassBodyContext ------------------------------------------------------------------

LatteParser::ClassBodyContext::ClassBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LatteParser::ClassItemContext *> LatteParser::ClassBodyContext::classItem() {
  return getRuleContexts<LatteParser::ClassItemContext>();
}

LatteParser::ClassItemContext* LatteParser::ClassBodyContext::classItem(size_t i) {
  return getRuleContext<LatteParser::ClassItemContext>(i);
}


size_t LatteParser::ClassBodyContext::getRuleIndex() const {
  return LatteParser::RuleClassBody;
}

void LatteParser::ClassBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassBody(this);
}

void LatteParser::ClassBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassBody(this);
}


antlrcpp::Any LatteParser::ClassBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitClassBody(this);
  else
    return visitor->visitChildren(this);
}

LatteParser::ClassBodyContext* LatteParser::classBody() {
  ClassBodyContext *_localctx = _tracker.createInstance<ClassBodyContext>(_ctx, getState());
  enterRule(_localctx, 8, LatteParser::RuleClassBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(LatteParser::T__6);
    setState(70);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LatteParser::T__20)
      | (1ULL << LatteParser::T__21)
      | (1ULL << LatteParser::T__22)
      | (1ULL << LatteParser::T__23)
      | (1ULL << LatteParser::ID))) != 0)) {
      setState(67);
      classItem();
      setState(72);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(73);
    match(LatteParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgContext ------------------------------------------------------------------

LatteParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LatteParser::Type_Context *> LatteParser::ArgContext::type_() {
  return getRuleContexts<LatteParser::Type_Context>();
}

LatteParser::Type_Context* LatteParser::ArgContext::type_(size_t i) {
  return getRuleContext<LatteParser::Type_Context>(i);
}

std::vector<tree::TerminalNode *> LatteParser::ArgContext::ID() {
  return getTokens(LatteParser::ID);
}

tree::TerminalNode* LatteParser::ArgContext::ID(size_t i) {
  return getToken(LatteParser::ID, i);
}


size_t LatteParser::ArgContext::getRuleIndex() const {
  return LatteParser::RuleArg;
}

void LatteParser::ArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArg(this);
}

void LatteParser::ArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArg(this);
}


antlrcpp::Any LatteParser::ArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitArg(this);
  else
    return visitor->visitChildren(this);
}

LatteParser::ArgContext* LatteParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 10, LatteParser::RuleArg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    type_(0);
    setState(76);
    match(LatteParser::ID);
    setState(83);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LatteParser::T__4) {
      setState(77);
      match(LatteParser::T__4);
      setState(78);
      type_(0);
      setState(79);
      match(LatteParser::ID);
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

//----------------- BlockContext ------------------------------------------------------------------

LatteParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LatteParser::StmtContext *> LatteParser::BlockContext::stmt() {
  return getRuleContexts<LatteParser::StmtContext>();
}

LatteParser::StmtContext* LatteParser::BlockContext::stmt(size_t i) {
  return getRuleContext<LatteParser::StmtContext>(i);
}


size_t LatteParser::BlockContext::getRuleIndex() const {
  return LatteParser::RuleBlock;
}

void LatteParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void LatteParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any LatteParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

LatteParser::BlockContext* LatteParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 12, LatteParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    match(LatteParser::T__6);
    setState(90);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LatteParser::T__0)
      | (1ULL << LatteParser::T__5)
      | (1ULL << LatteParser::T__6)
      | (1ULL << LatteParser::T__14)
      | (1ULL << LatteParser::T__15)
      | (1ULL << LatteParser::T__17)
      | (1ULL << LatteParser::T__18)
      | (1ULL << LatteParser::T__20)
      | (1ULL << LatteParser::T__21)
      | (1ULL << LatteParser::T__22)
      | (1ULL << LatteParser::T__23)
      | (1ULL << LatteParser::T__24)
      | (1ULL << LatteParser::T__25)
      | (1ULL << LatteParser::T__28)
      | (1ULL << LatteParser::T__29)
      | (1ULL << LatteParser::T__30)
      | (1ULL << LatteParser::INT)
      | (1ULL << LatteParser::ID)
      | (1ULL << LatteParser::STR))) != 0)) {
      setState(87);
      stmt();
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(93);
    match(LatteParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

LatteParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LatteParser::StmtContext::getRuleIndex() const {
  return LatteParser::RuleStmt;
}

void LatteParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AssContext ------------------------------------------------------------------

tree::TerminalNode* LatteParser::AssContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::ExprContext* LatteParser::AssContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

LatteParser::AssContext::AssContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::AssContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAss(this);
}
void LatteParser::AssContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAss(this);
}

antlrcpp::Any LatteParser::AssContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitAss(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RetContext ------------------------------------------------------------------

LatteParser::ExprContext* LatteParser::RetContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

LatteParser::RetContext::RetContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::RetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRet(this);
}
void LatteParser::RetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRet(this);
}

antlrcpp::Any LatteParser::RetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitRet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CondContext ------------------------------------------------------------------

LatteParser::ExprContext* LatteParser::CondContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

LatteParser::StmtContext* LatteParser::CondContext::stmt() {
  return getRuleContext<LatteParser::StmtContext>(0);
}

LatteParser::CondContext::CondContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}
void LatteParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}

antlrcpp::Any LatteParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CondElseContext ------------------------------------------------------------------

LatteParser::ExprContext* LatteParser::CondElseContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

std::vector<LatteParser::StmtContext *> LatteParser::CondElseContext::stmt() {
  return getRuleContexts<LatteParser::StmtContext>();
}

LatteParser::StmtContext* LatteParser::CondElseContext::stmt(size_t i) {
  return getRuleContext<LatteParser::StmtContext>(i);
}

LatteParser::CondElseContext::CondElseContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::CondElseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondElse(this);
}
void LatteParser::CondElseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondElse(this);
}

antlrcpp::Any LatteParser::CondElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitCondElse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VRetContext ------------------------------------------------------------------

LatteParser::VRetContext::VRetContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::VRetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVRet(this);
}
void LatteParser::VRetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVRet(this);
}

antlrcpp::Any LatteParser::VRetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitVRet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrAssContext ------------------------------------------------------------------

std::vector<LatteParser::ExprContext *> LatteParser::ArrAssContext::expr() {
  return getRuleContexts<LatteParser::ExprContext>();
}

LatteParser::ExprContext* LatteParser::ArrAssContext::expr(size_t i) {
  return getRuleContext<LatteParser::ExprContext>(i);
}

LatteParser::ArrAssContext::ArrAssContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::ArrAssContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrAss(this);
}
void LatteParser::ArrAssContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrAss(this);
}

antlrcpp::Any LatteParser::ArrAssContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitArrAss(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlockStmtContext ------------------------------------------------------------------

LatteParser::BlockContext* LatteParser::BlockStmtContext::block() {
  return getRuleContext<LatteParser::BlockContext>(0);
}

LatteParser::BlockStmtContext::BlockStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::BlockStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStmt(this);
}
void LatteParser::BlockStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStmt(this);
}

antlrcpp::Any LatteParser::BlockStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitBlockStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclContext ------------------------------------------------------------------

LatteParser::Type_Context* LatteParser::DeclContext::type_() {
  return getRuleContext<LatteParser::Type_Context>(0);
}

std::vector<LatteParser::ItemContext *> LatteParser::DeclContext::item() {
  return getRuleContexts<LatteParser::ItemContext>();
}

LatteParser::ItemContext* LatteParser::DeclContext::item(size_t i) {
  return getRuleContext<LatteParser::ItemContext>(i);
}

LatteParser::DeclContext::DeclContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}
void LatteParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}

antlrcpp::Any LatteParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileContext ------------------------------------------------------------------

LatteParser::ExprContext* LatteParser::WhileContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

LatteParser::StmtContext* LatteParser::WhileContext::stmt() {
  return getRuleContext<LatteParser::StmtContext>(0);
}

LatteParser::WhileContext::WhileContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::WhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile(this);
}
void LatteParser::WhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile(this);
}

antlrcpp::Any LatteParser::WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SExpContext ------------------------------------------------------------------

LatteParser::ExprContext* LatteParser::SExpContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

LatteParser::SExpContext::SExpContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::SExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSExp(this);
}
void LatteParser::SExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSExp(this);
}

antlrcpp::Any LatteParser::SExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitSExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DecrContext ------------------------------------------------------------------

tree::TerminalNode* LatteParser::DecrContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::DecrContext::DecrContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::DecrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecr(this);
}
void LatteParser::DecrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecr(this);
}

antlrcpp::Any LatteParser::DecrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitDecr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EmptyContext ------------------------------------------------------------------

LatteParser::EmptyContext::EmptyContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::EmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmpty(this);
}
void LatteParser::EmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmpty(this);
}

antlrcpp::Any LatteParser::EmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEmpty(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassAssContext ------------------------------------------------------------------

std::vector<LatteParser::ExprContext *> LatteParser::ClassAssContext::expr() {
  return getRuleContexts<LatteParser::ExprContext>();
}

LatteParser::ExprContext* LatteParser::ClassAssContext::expr(size_t i) {
  return getRuleContext<LatteParser::ExprContext>(i);
}

tree::TerminalNode* LatteParser::ClassAssContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::ClassAssContext::ClassAssContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::ClassAssContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassAss(this);
}
void LatteParser::ClassAssContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassAss(this);
}

antlrcpp::Any LatteParser::ClassAssContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitClassAss(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IncrContext ------------------------------------------------------------------

tree::TerminalNode* LatteParser::IncrContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::IncrContext::IncrContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::IncrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIncr(this);
}
void LatteParser::IncrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIncr(this);
}

antlrcpp::Any LatteParser::IncrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitIncr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForArrContext ------------------------------------------------------------------

LatteParser::Type_Context* LatteParser::ForArrContext::type_() {
  return getRuleContext<LatteParser::Type_Context>(0);
}

tree::TerminalNode* LatteParser::ForArrContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::ExprContext* LatteParser::ForArrContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

LatteParser::StmtContext* LatteParser::ForArrContext::stmt() {
  return getRuleContext<LatteParser::StmtContext>(0);
}

LatteParser::ForArrContext::ForArrContext(StmtContext *ctx) { copyFrom(ctx); }

void LatteParser::ForArrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForArr(this);
}
void LatteParser::ForArrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForArr(this);
}

antlrcpp::Any LatteParser::ForArrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitForArr(this);
  else
    return visitor->visitChildren(this);
}
LatteParser::StmtContext* LatteParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 14, LatteParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::EmptyContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(95);
      match(LatteParser::T__5);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::BlockStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(96);
      block();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::DeclContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(97);
      type_(0);
      setState(98);
      item();
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LatteParser::T__4) {
        setState(99);
        match(LatteParser::T__4);
        setState(100);
        item();
        setState(105);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(106);
      match(LatteParser::T__5);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::AssContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(108);
      match(LatteParser::ID);
      setState(109);
      match(LatteParser::T__8);
      setState(110);
      expr(0);
      setState(111);
      match(LatteParser::T__5);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::ClassAssContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(113);
      expr(0);
      setState(114);
      match(LatteParser::T__9);
      setState(115);
      match(LatteParser::ID);
      setState(116);
      match(LatteParser::T__8);
      setState(117);
      expr(0);
      setState(118);
      match(LatteParser::T__5);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::ArrAssContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(120);
      expr(0);
      setState(121);
      match(LatteParser::T__10);
      setState(122);
      expr(0);
      setState(123);
      match(LatteParser::T__11);
      setState(124);
      match(LatteParser::T__8);
      setState(125);
      expr(0);
      setState(126);
      match(LatteParser::T__5);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::IncrContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(128);
      match(LatteParser::ID);
      setState(129);
      match(LatteParser::T__12);
      setState(130);
      match(LatteParser::T__5);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::DecrContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(131);
      match(LatteParser::ID);
      setState(132);
      match(LatteParser::T__13);
      setState(133);
      match(LatteParser::T__5);
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::RetContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(134);
      match(LatteParser::T__14);
      setState(135);
      expr(0);
      setState(136);
      match(LatteParser::T__5);
      break;
    }

    case 10: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::VRetContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(138);
      match(LatteParser::T__14);
      setState(139);
      match(LatteParser::T__5);
      break;
    }

    case 11: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::CondContext>(_localctx));
      enterOuterAlt(_localctx, 11);
      setState(140);
      match(LatteParser::T__15);
      setState(141);
      match(LatteParser::T__0);
      setState(142);
      expr(0);
      setState(143);
      match(LatteParser::T__1);
      setState(144);
      stmt();
      break;
    }

    case 12: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::CondElseContext>(_localctx));
      enterOuterAlt(_localctx, 12);
      setState(146);
      match(LatteParser::T__15);
      setState(147);
      match(LatteParser::T__0);
      setState(148);
      expr(0);
      setState(149);
      match(LatteParser::T__1);
      setState(150);
      stmt();
      setState(151);
      match(LatteParser::T__16);
      setState(152);
      stmt();
      break;
    }

    case 13: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::WhileContext>(_localctx));
      enterOuterAlt(_localctx, 13);
      setState(154);
      match(LatteParser::T__17);
      setState(155);
      match(LatteParser::T__0);
      setState(156);
      expr(0);
      setState(157);
      match(LatteParser::T__1);
      setState(158);
      stmt();
      break;
    }

    case 14: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::ForArrContext>(_localctx));
      enterOuterAlt(_localctx, 14);
      setState(160);
      match(LatteParser::T__18);
      setState(161);
      match(LatteParser::T__0);
      setState(162);
      type_(0);
      setState(163);
      match(LatteParser::ID);
      setState(164);
      match(LatteParser::T__19);
      setState(165);
      expr(0);
      setState(166);
      match(LatteParser::T__1);
      setState(167);
      stmt();
      break;
    }

    case 15: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<LatteParser::SExpContext>(_localctx));
      enterOuterAlt(_localctx, 15);
      setState(169);
      expr(0);
      setState(170);
      match(LatteParser::T__5);
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

LatteParser::Type_Context::Type_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LatteParser::Type_Context::getRuleIndex() const {
  return LatteParser::RuleType_;
}

void LatteParser::Type_Context::copyFrom(Type_Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StrContext ------------------------------------------------------------------

LatteParser::StrContext::StrContext(Type_Context *ctx) { copyFrom(ctx); }

void LatteParser::StrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStr(this);
}
void LatteParser::StrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStr(this);
}

antlrcpp::Any LatteParser::StrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitStr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrTypeContext ------------------------------------------------------------------

LatteParser::Type_Context* LatteParser::ArrTypeContext::type_() {
  return getRuleContext<LatteParser::Type_Context>(0);
}

LatteParser::ArrTypeContext::ArrTypeContext(Type_Context *ctx) { copyFrom(ctx); }

void LatteParser::ArrTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrType(this);
}
void LatteParser::ArrTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrType(this);
}

antlrcpp::Any LatteParser::ArrTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitArrType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolContext ------------------------------------------------------------------

LatteParser::BoolContext::BoolContext(Type_Context *ctx) { copyFrom(ctx); }

void LatteParser::BoolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBool(this);
}
void LatteParser::BoolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBool(this);
}

antlrcpp::Any LatteParser::BoolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitBool(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassContext ------------------------------------------------------------------

tree::TerminalNode* LatteParser::ClassContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::ClassContext::ClassContext(Type_Context *ctx) { copyFrom(ctx); }

void LatteParser::ClassContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClass(this);
}
void LatteParser::ClassContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClass(this);
}

antlrcpp::Any LatteParser::ClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitClass(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VoidContext ------------------------------------------------------------------

LatteParser::VoidContext::VoidContext(Type_Context *ctx) { copyFrom(ctx); }

void LatteParser::VoidContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVoid(this);
}
void LatteParser::VoidContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVoid(this);
}

antlrcpp::Any LatteParser::VoidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitVoid(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

LatteParser::IntContext::IntContext(Type_Context *ctx) { copyFrom(ctx); }

void LatteParser::IntContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt(this);
}
void LatteParser::IntContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt(this);
}

antlrcpp::Any LatteParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
}

LatteParser::Type_Context* LatteParser::type_() {
   return type_(0);
}

LatteParser::Type_Context* LatteParser::type_(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LatteParser::Type_Context *_localctx = _tracker.createInstance<Type_Context>(_ctx, parentState);
  LatteParser::Type_Context *previousContext = _localctx;
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, LatteParser::RuleType_, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(180);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LatteParser::T__20: {
        _localctx = _tracker.createInstance<IntContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(175);
        match(LatteParser::T__20);
        break;
      }

      case LatteParser::T__21: {
        _localctx = _tracker.createInstance<StrContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(176);
        match(LatteParser::T__21);
        break;
      }

      case LatteParser::T__22: {
        _localctx = _tracker.createInstance<BoolContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(177);
        match(LatteParser::T__22);
        break;
      }

      case LatteParser::T__23: {
        _localctx = _tracker.createInstance<VoidContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(178);
        match(LatteParser::T__23);
        break;
      }

      case LatteParser::ID: {
        _localctx = _tracker.createInstance<ClassContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(179);
        match(LatteParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(187);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ArrTypeContext>(_tracker.createInstance<Type_Context>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleType_);
        setState(182);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(183);
        match(LatteParser::T__10);
        setState(184);
        match(LatteParser::T__11); 
      }
      setState(189);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
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

LatteParser::ItemContext::ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::ItemContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::ExprContext* LatteParser::ItemContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}


size_t LatteParser::ItemContext::getRuleIndex() const {
  return LatteParser::RuleItem;
}

void LatteParser::ItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterItem(this);
}

void LatteParser::ItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitItem(this);
}


antlrcpp::Any LatteParser::ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitItem(this);
  else
    return visitor->visitChildren(this);
}

LatteParser::ItemContext* LatteParser::item() {
  ItemContext *_localctx = _tracker.createInstance<ItemContext>(_ctx, getState());
  enterRule(_localctx, 18, LatteParser::RuleItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(194);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(190);
      match(LatteParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(191);
      match(LatteParser::ID);
      setState(192);
      match(LatteParser::T__8);
      setState(193);
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

LatteParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LatteParser::ExprContext::getRuleIndex() const {
  return LatteParser::RuleExpr;
}

void LatteParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- EIdContext ------------------------------------------------------------------

tree::TerminalNode* LatteParser::EIdContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::EIdContext::EIdContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EIdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEId(this);
}
void LatteParser::EIdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEId(this);
}

antlrcpp::Any LatteParser::EIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EFunCallContext ------------------------------------------------------------------

tree::TerminalNode* LatteParser::EFunCallContext::ID() {
  return getToken(LatteParser::ID, 0);
}

std::vector<LatteParser::ExprContext *> LatteParser::EFunCallContext::expr() {
  return getRuleContexts<LatteParser::ExprContext>();
}

LatteParser::ExprContext* LatteParser::EFunCallContext::expr(size_t i) {
  return getRuleContext<LatteParser::ExprContext>(i);
}

LatteParser::EFunCallContext::EFunCallContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EFunCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEFunCall(this);
}
void LatteParser::EFunCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEFunCall(this);
}

antlrcpp::Any LatteParser::EFunCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEFunCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EClassDefContext ------------------------------------------------------------------

tree::TerminalNode* LatteParser::EClassDefContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::EClassDefContext::EClassDefContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EClassDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEClassDef(this);
}
void LatteParser::EClassDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEClassDef(this);
}

antlrcpp::Any LatteParser::EClassDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEClassDef(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ERelOpContext ------------------------------------------------------------------

std::vector<LatteParser::ExprContext *> LatteParser::ERelOpContext::expr() {
  return getRuleContexts<LatteParser::ExprContext>();
}

LatteParser::ExprContext* LatteParser::ERelOpContext::expr(size_t i) {
  return getRuleContext<LatteParser::ExprContext>(i);
}

LatteParser::RelOpContext* LatteParser::ERelOpContext::relOp() {
  return getRuleContext<LatteParser::RelOpContext>(0);
}

LatteParser::ERelOpContext::ERelOpContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::ERelOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterERelOp(this);
}
void LatteParser::ERelOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitERelOp(this);
}

antlrcpp::Any LatteParser::ERelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitERelOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EClassFieldContext ------------------------------------------------------------------

LatteParser::ExprContext* LatteParser::EClassFieldContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

tree::TerminalNode* LatteParser::EClassFieldContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::EClassFieldContext::EClassFieldContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EClassFieldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEClassField(this);
}
void LatteParser::EClassFieldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEClassField(this);
}

antlrcpp::Any LatteParser::EClassFieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEClassField(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ETrueContext ------------------------------------------------------------------

LatteParser::ETrueContext::ETrueContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::ETrueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterETrue(this);
}
void LatteParser::ETrueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitETrue(this);
}

antlrcpp::Any LatteParser::ETrueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitETrue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ENewArrContext ------------------------------------------------------------------

LatteParser::Type_Context* LatteParser::ENewArrContext::type_() {
  return getRuleContext<LatteParser::Type_Context>(0);
}

LatteParser::ExprContext* LatteParser::ENewArrContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

LatteParser::ENewArrContext::ENewArrContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::ENewArrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterENewArr(this);
}
void LatteParser::ENewArrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitENewArr(this);
}

antlrcpp::Any LatteParser::ENewArrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitENewArr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EOrContext ------------------------------------------------------------------

std::vector<LatteParser::ExprContext *> LatteParser::EOrContext::expr() {
  return getRuleContexts<LatteParser::ExprContext>();
}

LatteParser::ExprContext* LatteParser::EOrContext::expr(size_t i) {
  return getRuleContext<LatteParser::ExprContext>(i);
}

LatteParser::EOrContext::EOrContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EOrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEOr(this);
}
void LatteParser::EOrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEOr(this);
}

antlrcpp::Any LatteParser::EOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EIntContext ------------------------------------------------------------------

tree::TerminalNode* LatteParser::EIntContext::INT() {
  return getToken(LatteParser::INT, 0);
}

LatteParser::EIntContext::EIntContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EIntContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEInt(this);
}
void LatteParser::EIntContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEInt(this);
}

antlrcpp::Any LatteParser::EIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EUnOpContext ------------------------------------------------------------------

LatteParser::ExprContext* LatteParser::EUnOpContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

LatteParser::EUnOpContext::EUnOpContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EUnOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEUnOp(this);
}
void LatteParser::EUnOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEUnOp(this);
}

antlrcpp::Any LatteParser::EUnOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEUnOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ETypedNullContext ------------------------------------------------------------------

tree::TerminalNode* LatteParser::ETypedNullContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::ETypedNullContext::ETypedNullContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::ETypedNullContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterETypedNull(this);
}
void LatteParser::ETypedNullContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitETypedNull(this);
}

antlrcpp::Any LatteParser::ETypedNullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitETypedNull(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EStrContext ------------------------------------------------------------------

tree::TerminalNode* LatteParser::EStrContext::STR() {
  return getToken(LatteParser::STR, 0);
}

LatteParser::EStrContext::EStrContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EStrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEStr(this);
}
void LatteParser::EStrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEStr(this);
}

antlrcpp::Any LatteParser::EStrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEStr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EMulOpContext ------------------------------------------------------------------

std::vector<LatteParser::ExprContext *> LatteParser::EMulOpContext::expr() {
  return getRuleContexts<LatteParser::ExprContext>();
}

LatteParser::ExprContext* LatteParser::EMulOpContext::expr(size_t i) {
  return getRuleContext<LatteParser::ExprContext>(i);
}

LatteParser::MulOpContext* LatteParser::EMulOpContext::mulOp() {
  return getRuleContext<LatteParser::MulOpContext>(0);
}

LatteParser::EMulOpContext::EMulOpContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EMulOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEMulOp(this);
}
void LatteParser::EMulOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEMulOp(this);
}

antlrcpp::Any LatteParser::EMulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEMulOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EAndContext ------------------------------------------------------------------

std::vector<LatteParser::ExprContext *> LatteParser::EAndContext::expr() {
  return getRuleContexts<LatteParser::ExprContext>();
}

LatteParser::ExprContext* LatteParser::EAndContext::expr(size_t i) {
  return getRuleContext<LatteParser::ExprContext>(i);
}

LatteParser::EAndContext::EAndContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EAndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEAnd(this);
}
void LatteParser::EAndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEAnd(this);
}

antlrcpp::Any LatteParser::EAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EArrIdxContext ------------------------------------------------------------------

tree::TerminalNode* LatteParser::EArrIdxContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::ExprContext* LatteParser::EArrIdxContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

LatteParser::EArrIdxContext::EArrIdxContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EArrIdxContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEArrIdx(this);
}
void LatteParser::EArrIdxContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEArrIdx(this);
}

antlrcpp::Any LatteParser::EArrIdxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEArrIdx(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EParenContext ------------------------------------------------------------------

LatteParser::ExprContext* LatteParser::EParenContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

LatteParser::EParenContext::EParenContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EParenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEParen(this);
}
void LatteParser::EParenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEParen(this);
}

antlrcpp::Any LatteParser::EParenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEParen(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EFalseContext ------------------------------------------------------------------

LatteParser::EFalseContext::EFalseContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EFalseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEFalse(this);
}
void LatteParser::EFalseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEFalse(this);
}

antlrcpp::Any LatteParser::EFalseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEFalse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EAddOpContext ------------------------------------------------------------------

std::vector<LatteParser::ExprContext *> LatteParser::EAddOpContext::expr() {
  return getRuleContexts<LatteParser::ExprContext>();
}

LatteParser::ExprContext* LatteParser::EAddOpContext::expr(size_t i) {
  return getRuleContext<LatteParser::ExprContext>(i);
}

LatteParser::AddOpContext* LatteParser::EAddOpContext::addOp() {
  return getRuleContext<LatteParser::AddOpContext>(0);
}

LatteParser::EAddOpContext::EAddOpContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EAddOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEAddOp(this);
}
void LatteParser::EAddOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEAddOp(this);
}

antlrcpp::Any LatteParser::EAddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEAddOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EClassFunContext ------------------------------------------------------------------

std::vector<LatteParser::ExprContext *> LatteParser::EClassFunContext::expr() {
  return getRuleContexts<LatteParser::ExprContext>();
}

LatteParser::ExprContext* LatteParser::EClassFunContext::expr(size_t i) {
  return getRuleContext<LatteParser::ExprContext>(i);
}

tree::TerminalNode* LatteParser::EClassFunContext::ID() {
  return getToken(LatteParser::ID, 0);
}

LatteParser::EClassFunContext::EClassFunContext(ExprContext *ctx) { copyFrom(ctx); }

void LatteParser::EClassFunContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEClassFun(this);
}
void LatteParser::EClassFunContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEClassFun(this);
}

antlrcpp::Any LatteParser::EClassFunContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitEClassFun(this);
  else
    return visitor->visitChildren(this);
}

LatteParser::ExprContext* LatteParser::expr() {
   return expr(0);
}

LatteParser::ExprContext* LatteParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LatteParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  LatteParser::ExprContext *previousContext = _localctx;
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, LatteParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(238);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<EUnOpContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(197);
      _la = _input->LA(1);
      if (!(_la == LatteParser::T__24

      || _la == LatteParser::T__25)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(198);
      expr(17);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<EIdContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(199);
      match(LatteParser::ID);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<EIntContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(200);
      match(LatteParser::INT);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ETrueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(201);
      match(LatteParser::T__28);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<EFalseContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(202);
      match(LatteParser::T__29);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<EFunCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(203);
      match(LatteParser::ID);
      setState(204);
      match(LatteParser::T__0);
      setState(213);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << LatteParser::T__0)
        | (1ULL << LatteParser::T__24)
        | (1ULL << LatteParser::T__25)
        | (1ULL << LatteParser::T__28)
        | (1ULL << LatteParser::T__29)
        | (1ULL << LatteParser::T__30)
        | (1ULL << LatteParser::INT)
        | (1ULL << LatteParser::ID)
        | (1ULL << LatteParser::STR))) != 0)) {
        setState(205);
        expr(0);
        setState(210);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == LatteParser::T__4) {
          setState(206);
          match(LatteParser::T__4);
          setState(207);
          expr(0);
          setState(212);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(215);
      match(LatteParser::T__1);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<EStrContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(216);
      match(LatteParser::STR);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<EParenContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(217);
      match(LatteParser::T__0);
      setState(218);
      expr(0);
      setState(219);
      match(LatteParser::T__1);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<EClassDefContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(221);
      match(LatteParser::T__30);
      setState(222);
      match(LatteParser::ID);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<ENewArrContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(223);
      match(LatteParser::T__30);
      setState(224);
      type_(0);
      setState(225);
      match(LatteParser::T__10);
      setState(226);
      expr(0);
      setState(227);
      match(LatteParser::T__11);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<EArrIdxContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(229);
      match(LatteParser::ID);
      setState(230);
      match(LatteParser::T__10);
      setState(231);
      expr(0);
      setState(232);
      match(LatteParser::T__11);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<ETypedNullContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(234);
      match(LatteParser::T__0);
      setState(235);
      match(LatteParser::ID);
      setState(236);
      match(LatteParser::T__1);
      setState(237);
      match(LatteParser::T__31);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(278);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(276);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<EMulOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(240);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(241);
          mulOp();
          setState(242);
          expr(17);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<EAddOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(244);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(245);
          addOp();
          setState(246);
          expr(16);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ERelOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(248);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(249);
          relOp();
          setState(250);
          expr(15);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EAndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(252);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(253);
          match(LatteParser::T__26);
          setState(254);
          expr(13);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<EOrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(255);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(256);
          match(LatteParser::T__27);
          setState(257);
          expr(12);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<EClassFieldContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(258);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(259);
          match(LatteParser::T__9);
          setState(260);
          match(LatteParser::ID);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<EClassFunContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(261);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(262);
          match(LatteParser::T__9);
          setState(263);
          match(LatteParser::ID);
          setState(264);
          match(LatteParser::T__0);
          setState(273);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << LatteParser::T__0)
            | (1ULL << LatteParser::T__24)
            | (1ULL << LatteParser::T__25)
            | (1ULL << LatteParser::T__28)
            | (1ULL << LatteParser::T__29)
            | (1ULL << LatteParser::T__30)
            | (1ULL << LatteParser::INT)
            | (1ULL << LatteParser::ID)
            | (1ULL << LatteParser::STR))) != 0)) {
            setState(265);
            expr(0);
            setState(270);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == LatteParser::T__4) {
              setState(266);
              match(LatteParser::T__4);
              setState(267);
              expr(0);
              setState(272);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(275);
          match(LatteParser::T__1);
          break;
        }

        } 
      }
      setState(280);
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

//----------------- AddOpContext ------------------------------------------------------------------

LatteParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LatteParser::AddOpContext::getRuleIndex() const {
  return LatteParser::RuleAddOp;
}

void LatteParser::AddOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddOp(this);
}

void LatteParser::AddOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddOp(this);
}


antlrcpp::Any LatteParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

LatteParser::AddOpContext* LatteParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 22, LatteParser::RuleAddOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    _la = _input->LA(1);
    if (!(_la == LatteParser::T__24

    || _la == LatteParser::T__32)) {
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

LatteParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LatteParser::MulOpContext::getRuleIndex() const {
  return LatteParser::RuleMulOp;
}

void LatteParser::MulOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulOp(this);
}

void LatteParser::MulOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulOp(this);
}


antlrcpp::Any LatteParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}

LatteParser::MulOpContext* LatteParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 24, LatteParser::RuleMulOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LatteParser::T__33)
      | (1ULL << LatteParser::T__34)
      | (1ULL << LatteParser::T__35))) != 0))) {
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

LatteParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LatteParser::RelOpContext::getRuleIndex() const {
  return LatteParser::RuleRelOp;
}

void LatteParser::RelOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelOp(this);
}

void LatteParser::RelOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelOp(this);
}


antlrcpp::Any LatteParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LatteVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

LatteParser::RelOpContext* LatteParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 26, LatteParser::RuleRelOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LatteParser::T__36)
      | (1ULL << LatteParser::T__37)
      | (1ULL << LatteParser::T__38)
      | (1ULL << LatteParser::T__39)
      | (1ULL << LatteParser::T__40)
      | (1ULL << LatteParser::T__41))) != 0))) {
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

bool LatteParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 8: return type_Sempred(dynamic_cast<Type_Context *>(context), predicateIndex);
    case 10: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool LatteParser::type_Sempred(Type_Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool LatteParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 16);
    case 2: return precpred(_ctx, 15);
    case 3: return precpred(_ctx, 14);
    case 4: return precpred(_ctx, 13);
    case 5: return precpred(_ctx, 12);
    case 6: return precpred(_ctx, 19);
    case 7: return precpred(_ctx, 18);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> LatteParser::_decisionToDFA;
atn::PredictionContextCache LatteParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN LatteParser::_atn;
std::vector<uint16_t> LatteParser::_serializedATN;

std::vector<std::string> LatteParser::_ruleNames = {
  "program", "funcDef", "topDef", "classItem", "classBody", "arg", "block", 
  "stmt", "type_", "item", "expr", "addOp", "mulOp", "relOp"
};

std::vector<std::string> LatteParser::_literalNames = {
  "", "'('", "')'", "'class'", "'extends'", "','", "';'", "'{'", "'}'", 
  "'='", "'.'", "'['", "']'", "'++'", "'--'", "'return'", "'if'", "'else'", 
  "'while'", "'for'", "':'", "'int'", "'string'", "'boolean'", "'void'", 
  "'-'", "'!'", "'&&'", "'||'", "'true'", "'false'", "'new'", "'null'", 
  "'+'", "'*'", "'/'", "'%'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='"
};

std::vector<std::string> LatteParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "COMMENT", "MULTICOMMENT", "INT", "ID", "WS", 
  "STR"
};

dfa::Vocabulary LatteParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> LatteParser::_tokenNames;

LatteParser::Initializer::Initializer() {
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
    0x3, 0x32, 0x122, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x3, 0x2, 0x6, 0x2, 0x20, 0xa, 0x2, 0xd, 0x2, 0xe, 
    0x2, 0x21, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x28, 0xa, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x32, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0x35, 0xa, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x3c, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x3f, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x43, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x47, 0xa, 0x6, 0xc, 
    0x6, 0xe, 0x6, 0x4a, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x54, 0xa, 0x7, 0xc, 
    0x7, 0xe, 0x7, 0x57, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x5b, 0xa, 
    0x8, 0xc, 0x8, 0xe, 0x8, 0x5e, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x68, 0xa, 
    0x9, 0xc, 0x9, 0xe, 0x9, 0x6b, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x5, 0x9, 0xaf, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0xb7, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x7, 0xa, 0xbc, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xbf, 0xb, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xc5, 0xa, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xd3, 0xa, 0xc, 0xc, 0xc, 
    0xe, 0xc, 0xd6, 0xb, 0xc, 0x5, 0xc, 0xd8, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0xf1, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x10f, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 
    0x112, 0xb, 0xc, 0x5, 0xc, 0x114, 0xa, 0xc, 0x3, 0xc, 0x7, 0xc, 0x117, 
    0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x11a, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x2, 0x4, 0x12, 0x16, 0x10, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x2, 0x6, 0x3, 0x2, 0x1b, 0x1c, 0x4, 0x2, 0x1b, 0x1b, 0x23, 0x23, 
    0x3, 0x2, 0x24, 0x26, 0x3, 0x2, 0x27, 0x2c, 0x2, 0x147, 0x2, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x23, 0x3, 0x2, 0x2, 0x2, 0x6, 0x34, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x42, 0x3, 0x2, 0x2, 0x2, 0xa, 0x44, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0xe, 0x58, 0x3, 0x2, 0x2, 0x2, 0x10, 0xae, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x14, 0xc4, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x18, 0x11b, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x11f, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x20, 0x5, 0x6, 0x4, 0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 
    0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x3, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 
    0x5, 0x12, 0xa, 0x2, 0x24, 0x25, 0x7, 0x30, 0x2, 0x2, 0x25, 0x27, 0x7, 
    0x3, 0x2, 0x2, 0x26, 0x28, 0x5, 0xc, 0x7, 0x2, 0x27, 0x26, 0x3, 0x2, 
    0x2, 0x2, 0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0x29, 0x2a, 0x7, 0x4, 0x2, 0x2, 0x2a, 0x2b, 0x5, 0xe, 0x8, 0x2, 
    0x2b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x35, 0x5, 0x4, 0x3, 0x2, 0x2d, 
    0x2e, 0x7, 0x5, 0x2, 0x2, 0x2e, 0x31, 0x7, 0x30, 0x2, 0x2, 0x2f, 0x30, 
    0x7, 0x6, 0x2, 0x2, 0x30, 0x32, 0x7, 0x30, 0x2, 0x2, 0x31, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x35, 0x5, 0xa, 0x6, 0x2, 0x34, 0x2c, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x35, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x36, 0x43, 0x5, 0x4, 0x3, 0x2, 0x37, 0x38, 0x5, 0x12, 0xa, 0x2, 0x38, 
    0x3d, 0x5, 0x14, 0xb, 0x2, 0x39, 0x3a, 0x7, 0x7, 0x2, 0x2, 0x3a, 0x3c, 
    0x5, 0x14, 0xb, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0x40, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x41, 0x7, 0x8, 0x2, 0x2, 0x41, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x36, 0x3, 0x2, 0x2, 0x2, 0x42, 0x37, 0x3, 0x2, 0x2, 0x2, 0x43, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x44, 0x48, 0x7, 0x9, 0x2, 0x2, 0x45, 0x47, 
    0x5, 0x8, 0x5, 0x2, 0x46, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x49, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 
    0x2, 0x4b, 0x4c, 0x7, 0xa, 0x2, 0x2, 0x4c, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x4e, 0x5, 0x12, 0xa, 0x2, 0x4e, 0x55, 0x7, 0x30, 0x2, 0x2, 0x4f, 
    0x50, 0x7, 0x7, 0x2, 0x2, 0x50, 0x51, 0x5, 0x12, 0xa, 0x2, 0x51, 0x52, 
    0x7, 0x30, 0x2, 0x2, 0x52, 0x54, 0x3, 0x2, 0x2, 0x2, 0x53, 0x4f, 0x3, 
    0x2, 0x2, 0x2, 0x54, 0x57, 0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5c, 0x7, 0x9, 0x2, 0x2, 
    0x59, 0x5b, 0x5, 0x10, 0x9, 0x2, 0x5a, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 
    0x5e, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x5d, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x5f, 0x60, 0x7, 0xa, 0x2, 0x2, 0x60, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0xaf, 0x7, 0x8, 0x2, 0x2, 0x62, 0xaf, 0x5, 0xe, 0x8, 
    0x2, 0x63, 0x64, 0x5, 0x12, 0xa, 0x2, 0x64, 0x69, 0x5, 0x14, 0xb, 0x2, 
    0x65, 0x66, 0x7, 0x7, 0x2, 0x2, 0x66, 0x68, 0x5, 0x14, 0xb, 0x2, 0x67, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6c, 0x3, 
    0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x8, 
    0x2, 0x2, 0x6d, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x30, 0x2, 
    0x2, 0x6f, 0x70, 0x7, 0xb, 0x2, 0x2, 0x70, 0x71, 0x5, 0x16, 0xc, 0x2, 
    0x71, 0x72, 0x7, 0x8, 0x2, 0x2, 0x72, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x73, 
    0x74, 0x5, 0x16, 0xc, 0x2, 0x74, 0x75, 0x7, 0xc, 0x2, 0x2, 0x75, 0x76, 
    0x7, 0x30, 0x2, 0x2, 0x76, 0x77, 0x7, 0xb, 0x2, 0x2, 0x77, 0x78, 0x5, 
    0x16, 0xc, 0x2, 0x78, 0x79, 0x7, 0x8, 0x2, 0x2, 0x79, 0xaf, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x7b, 0x5, 0x16, 0xc, 0x2, 0x7b, 0x7c, 0x7, 0xd, 0x2, 
    0x2, 0x7c, 0x7d, 0x5, 0x16, 0xc, 0x2, 0x7d, 0x7e, 0x7, 0xe, 0x2, 0x2, 
    0x7e, 0x7f, 0x7, 0xb, 0x2, 0x2, 0x7f, 0x80, 0x5, 0x16, 0xc, 0x2, 0x80, 
    0x81, 0x7, 0x8, 0x2, 0x2, 0x81, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 
    0x7, 0x30, 0x2, 0x2, 0x83, 0x84, 0x7, 0xf, 0x2, 0x2, 0x84, 0xaf, 0x7, 
    0x8, 0x2, 0x2, 0x85, 0x86, 0x7, 0x30, 0x2, 0x2, 0x86, 0x87, 0x7, 0x10, 
    0x2, 0x2, 0x87, 0xaf, 0x7, 0x8, 0x2, 0x2, 0x88, 0x89, 0x7, 0x11, 0x2, 
    0x2, 0x89, 0x8a, 0x5, 0x16, 0xc, 0x2, 0x8a, 0x8b, 0x7, 0x8, 0x2, 0x2, 
    0x8b, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x11, 0x2, 0x2, 0x8d, 
    0xaf, 0x7, 0x8, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x12, 0x2, 0x2, 0x8f, 0x90, 
    0x7, 0x3, 0x2, 0x2, 0x90, 0x91, 0x5, 0x16, 0xc, 0x2, 0x91, 0x92, 0x7, 
    0x4, 0x2, 0x2, 0x92, 0x93, 0x5, 0x10, 0x9, 0x2, 0x93, 0xaf, 0x3, 0x2, 
    0x2, 0x2, 0x94, 0x95, 0x7, 0x12, 0x2, 0x2, 0x95, 0x96, 0x7, 0x3, 0x2, 
    0x2, 0x96, 0x97, 0x5, 0x16, 0xc, 0x2, 0x97, 0x98, 0x7, 0x4, 0x2, 0x2, 
    0x98, 0x99, 0x5, 0x10, 0x9, 0x2, 0x99, 0x9a, 0x7, 0x13, 0x2, 0x2, 0x9a, 
    0x9b, 0x5, 0x10, 0x9, 0x2, 0x9b, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 
    0x7, 0x14, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x3, 0x2, 0x2, 0x9e, 0x9f, 0x5, 
    0x16, 0xc, 0x2, 0x9f, 0xa0, 0x7, 0x4, 0x2, 0x2, 0xa0, 0xa1, 0x5, 0x10, 
    0x9, 0x2, 0xa1, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x15, 0x2, 
    0x2, 0xa3, 0xa4, 0x7, 0x3, 0x2, 0x2, 0xa4, 0xa5, 0x5, 0x12, 0xa, 0x2, 
    0xa5, 0xa6, 0x7, 0x30, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0x16, 0x2, 0x2, 0xa7, 
    0xa8, 0x5, 0x16, 0xc, 0x2, 0xa8, 0xa9, 0x7, 0x4, 0x2, 0x2, 0xa9, 0xaa, 
    0x5, 0x10, 0x9, 0x2, 0xaa, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x5, 
    0x16, 0xc, 0x2, 0xac, 0xad, 0x7, 0x8, 0x2, 0x2, 0xad, 0xaf, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0x61, 0x3, 0x2, 0x2, 0x2, 0xae, 0x62, 0x3, 0x2, 0x2, 
    0x2, 0xae, 0x63, 0x3, 0x2, 0x2, 0x2, 0xae, 0x6e, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0x73, 0x3, 0x2, 0x2, 0x2, 0xae, 0x7a, 0x3, 0x2, 0x2, 0x2, 0xae, 
    0x82, 0x3, 0x2, 0x2, 0x2, 0xae, 0x85, 0x3, 0x2, 0x2, 0x2, 0xae, 0x88, 
    0x3, 0x2, 0x2, 0x2, 0xae, 0x8c, 0x3, 0x2, 0x2, 0x2, 0xae, 0x8e, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0x94, 0x3, 0x2, 0x2, 0x2, 0xae, 0x9c, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xae, 0xab, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0x11, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x8, 0xa, 0x1, 0x2, 
    0xb1, 0xb7, 0x7, 0x17, 0x2, 0x2, 0xb2, 0xb7, 0x7, 0x18, 0x2, 0x2, 0xb3, 
    0xb7, 0x7, 0x19, 0x2, 0x2, 0xb4, 0xb7, 0x7, 0x1a, 0x2, 0x2, 0xb5, 0xb7, 
    0x7, 0x30, 0x2, 0x2, 0xb6, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0xb6, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb4, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xbd, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xb9, 0xc, 0x3, 0x2, 0x2, 0xb9, 0xba, 0x7, 0xd, 0x2, 0x2, 
    0xba, 0xbc, 0x7, 0xe, 0x2, 0x2, 0xbb, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xbc, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0x13, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xc5, 0x7, 0x30, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x30, 
    0x2, 0x2, 0xc2, 0xc3, 0x7, 0xb, 0x2, 0x2, 0xc3, 0xc5, 0x5, 0x16, 0xc, 
    0x2, 0xc4, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xc5, 0x15, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x8, 0xc, 0x1, 0x2, 0xc7, 
    0xc8, 0x9, 0x2, 0x2, 0x2, 0xc8, 0xf1, 0x5, 0x16, 0xc, 0x13, 0xc9, 0xf1, 
    0x7, 0x30, 0x2, 0x2, 0xca, 0xf1, 0x7, 0x2f, 0x2, 0x2, 0xcb, 0xf1, 0x7, 
    0x1f, 0x2, 0x2, 0xcc, 0xf1, 0x7, 0x20, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x30, 
    0x2, 0x2, 0xce, 0xd7, 0x7, 0x3, 0x2, 0x2, 0xcf, 0xd4, 0x5, 0x16, 0xc, 
    0x2, 0xd0, 0xd1, 0x7, 0x7, 0x2, 0x2, 0xd1, 0xd3, 0x5, 0x16, 0xc, 0x2, 
    0xd2, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd4, 
    0xd2, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd8, 
    0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xcf, 0x3, 
    0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 0x2, 
    0x2, 0x2, 0xd9, 0xf1, 0x7, 0x4, 0x2, 0x2, 0xda, 0xf1, 0x7, 0x32, 0x2, 
    0x2, 0xdb, 0xdc, 0x7, 0x3, 0x2, 0x2, 0xdc, 0xdd, 0x5, 0x16, 0xc, 0x2, 
    0xdd, 0xde, 0x7, 0x4, 0x2, 0x2, 0xde, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xdf, 
    0xe0, 0x7, 0x21, 0x2, 0x2, 0xe0, 0xf1, 0x7, 0x30, 0x2, 0x2, 0xe1, 0xe2, 
    0x7, 0x21, 0x2, 0x2, 0xe2, 0xe3, 0x5, 0x12, 0xa, 0x2, 0xe3, 0xe4, 0x7, 
    0xd, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x16, 0xc, 0x2, 0xe5, 0xe6, 0x7, 0xe, 
    0x2, 0x2, 0xe6, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x30, 0x2, 
    0x2, 0xe8, 0xe9, 0x7, 0xd, 0x2, 0x2, 0xe9, 0xea, 0x5, 0x16, 0xc, 0x2, 
    0xea, 0xeb, 0x7, 0xe, 0x2, 0x2, 0xeb, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xec, 
    0xed, 0x7, 0x3, 0x2, 0x2, 0xed, 0xee, 0x7, 0x30, 0x2, 0x2, 0xee, 0xef, 
    0x7, 0x4, 0x2, 0x2, 0xef, 0xf1, 0x7, 0x22, 0x2, 0x2, 0xf0, 0xc6, 0x3, 
    0x2, 0x2, 0x2, 0xf0, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xca, 0x3, 0x2, 
    0x2, 0x2, 0xf0, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0xf0, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xda, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xec, 
    0x3, 0x2, 0x2, 0x2, 0xf1, 0x118, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0xc, 
    0x12, 0x2, 0x2, 0xf3, 0xf4, 0x5, 0x1a, 0xe, 0x2, 0xf4, 0xf5, 0x5, 0x16, 
    0xc, 0x13, 0xf5, 0x117, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0xc, 0x11, 0x2, 
    0x2, 0xf7, 0xf8, 0x5, 0x18, 0xd, 0x2, 0xf8, 0xf9, 0x5, 0x16, 0xc, 0x12, 
    0xf9, 0x117, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0xc, 0x10, 0x2, 0x2, 0xfb, 
    0xfc, 0x5, 0x1c, 0xf, 0x2, 0xfc, 0xfd, 0x5, 0x16, 0xc, 0x11, 0xfd, 0x117, 
    0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0xc, 0xf, 0x2, 0x2, 0xff, 0x100, 0x7, 
    0x1d, 0x2, 0x2, 0x100, 0x117, 0x5, 0x16, 0xc, 0xf, 0x101, 0x102, 0xc, 
    0xe, 0x2, 0x2, 0x102, 0x103, 0x7, 0x1e, 0x2, 0x2, 0x103, 0x117, 0x5, 
    0x16, 0xc, 0xe, 0x104, 0x105, 0xc, 0x15, 0x2, 0x2, 0x105, 0x106, 0x7, 
    0xc, 0x2, 0x2, 0x106, 0x117, 0x7, 0x30, 0x2, 0x2, 0x107, 0x108, 0xc, 
    0x14, 0x2, 0x2, 0x108, 0x109, 0x7, 0xc, 0x2, 0x2, 0x109, 0x10a, 0x7, 
    0x30, 0x2, 0x2, 0x10a, 0x113, 0x7, 0x3, 0x2, 0x2, 0x10b, 0x110, 0x5, 
    0x16, 0xc, 0x2, 0x10c, 0x10d, 0x7, 0x7, 0x2, 0x2, 0x10d, 0x10f, 0x5, 
    0x16, 0xc, 0x2, 0x10e, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x112, 0x3, 
    0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 
    0x2, 0x2, 0x2, 0x111, 0x114, 0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 
    0x2, 0x2, 0x2, 0x113, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 
    0x2, 0x2, 0x2, 0x114, 0x115, 0x3, 0x2, 0x2, 0x2, 0x115, 0x117, 0x7, 
    0x4, 0x2, 0x2, 0x116, 0xf2, 0x3, 0x2, 0x2, 0x2, 0x116, 0xf6, 0x3, 0x2, 
    0x2, 0x2, 0x116, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x116, 0xfe, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x101, 0x3, 0x2, 0x2, 0x2, 0x116, 0x104, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x107, 0x3, 0x2, 0x2, 0x2, 0x117, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x118, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 0x2, 
    0x2, 0x119, 0x17, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 0x2, 
    0x11b, 0x11c, 0x9, 0x3, 0x2, 0x2, 0x11c, 0x19, 0x3, 0x2, 0x2, 0x2, 0x11d, 
    0x11e, 0x9, 0x4, 0x2, 0x2, 0x11e, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 
    0x9, 0x5, 0x2, 0x2, 0x120, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x17, 0x21, 0x27, 
    0x31, 0x34, 0x3d, 0x42, 0x48, 0x55, 0x5c, 0x69, 0xae, 0xb6, 0xbd, 0xc4, 
    0xd4, 0xd7, 0xf0, 0x110, 0x113, 0x116, 0x118, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

LatteParser::Initializer LatteParser::_init;
