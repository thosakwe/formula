//
// Created by Tobe on 4/8/17.
//

#ifndef FORMULA_TOKEN_H
#define FORMULA_TOKEN_H
#include <iostream>
#include <string>
#include "TokenType.h"

class Token {
private:
    TokenType type;
    std::string text;
public:
    ~Token();
    Token(TokenType, std::string);
    const TokenType getType();
    const std::string getText();
    const void dump();
};


#endif //FORMULA_TOKEN_H
