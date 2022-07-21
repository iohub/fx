
// Generated from fx.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  fxLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, Break = 3, Case = 4, Char = 5, Const = 6, Continue = 7, 
    Default = 8, Do = 9, Else = 10, Enum = 11, Float = 12, For = 13, If = 14, 
    Inline = 15, Int = 16, Return = 17, Struct = 18, Switch = 19, Void = 20, 
    While = 21, Bool = 22, LeftParen = 23, RightParen = 24, LeftBracket = 25, 
    RightBracket = 26, LeftBrace = 27, RightBrace = 28, Less = 29, LessEqual = 30, 
    Greater = 31, GreaterEqual = 32, LeftShift = 33, RightShift = 34, Plus = 35, 
    PlusPlus = 36, Minus = 37, MinusMinus = 38, Star = 39, Div = 40, Mod = 41, 
    And = 42, Or = 43, AndAnd = 44, OrOr = 45, Caret = 46, Not = 47, Tilde = 48, 
    Question = 49, Colon = 50, Semi = 51, Comma = 52, Assign = 53, StarAssign = 54, 
    DivAssign = 55, ModAssign = 56, PlusAssign = 57, MinusAssign = 58, LeftShiftAssign = 59, 
    RightShiftAssign = 60, AndAssign = 61, XorAssign = 62, OrAssign = 63, 
    Equal = 64, NotEqual = 65, Arrow = 66, Dot = 67, Identifier = 68, Constant = 69, 
    DigitSequence = 70, Whitespace = 71, Newline = 72, BlockComment = 73, 
    LineComment = 74
  };

  fxLexer(antlr4::CharStream *input);
  ~fxLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

