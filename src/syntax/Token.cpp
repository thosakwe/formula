//
// Created by Tobe on 4/8/17.
//

#include "Token.h"

Token::~Token() {
    text.erase();
}

Token::Token(TokenType type, std::string text) : type(type), text(text) {}

const TokenType Token::getType() {
    return type;
}

const std::string Token::getText() {
    return text;
}

const void Token::dump() {
    std::cout << "\"" << getText() << "\" => " << getType() << std::endl;
    return;
}
