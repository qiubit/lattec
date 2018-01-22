//
// Created by Pawel Golinski on 21.01.2018.
//

#ifndef TESTLLVM_LATTEERRORLISTENER_H
#define TESTLLVM_LATTEERRORLISTENER_H


#include <sstream>
#include <string>

#include "antlr4-runtime.h"


class LatteErrorListener : public antlr4::BaseErrorListener {
private:
  std::vector<std::string> errorMsgs;
  bool errorCatched = false;
public:
  virtual void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token * offendingSymbol,
                           size_t line, size_t charPositionInLine,
                           const std::string &msg, std::exception_ptr e) override;
  const bool getErrorCatched() { return errorCatched; }
  void printErrors();
};



#endif //TESTLLVM_LATTEERRORLISTENER_H
