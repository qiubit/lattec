//
// Created by Pawel Golinski on 21.01.2018.
//

#include "LatteErrorListener.h"

void LatteErrorListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token * offendingSymbol,
                                     size_t line, size_t charPositionInLine, const std::string &msg,
                                     std::exception_ptr e)
{
    std::ostringstream os;
    os << "line " << line << ":" << charPositionInLine << " " << msg;
    this->errorMsgs.push_back(os.str());
    this->errorCatched = true;
}

void LatteErrorListener::printErrors()
{
    for (auto errorStr : this->errorMsgs) {
        std::cerr << errorStr << std::endl;
    }
}