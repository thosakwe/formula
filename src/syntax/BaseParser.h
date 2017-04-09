//
// Created by Tobe on 4/8/17.
//

#ifndef FORMULA_BASE_PARSER_H
#define FORMULA_BASE_PARSER_H

#include <vector>
#include "Token.h"

class BaseParser {
private:
    long index = -1;
    std::vector<Token *> *tokens;
protected:
    BaseParser(std::vector<Token *> *);
    bool done();
    Token *peek();
    Token *consume();
    TokenType peekType();
    Token *current = nullptr;
};


#endif //FORMULA_BASE_PARSER_H
