//
// Created by Tobe on 4/8/17.
//

#include "BaseParser.h"

BaseParser::BaseParser(std::vector<Token *> *tokens) : tokens(tokens) {}

bool BaseParser::done() {
    if (index == -1) {
        return tokens->empty();
    } else return index >= tokens->size() - 1;
}

Token *BaseParser::peek() {
    if (done())
        return nullptr;
    else {
        Token *result = tokens->at((unsigned long) (index + 1));

#if(DEBUG)
        std::cout << "peeked: " << index + 1 << "; got: ";
        result->dump();
#endif

        return result;
    }
}

Token *BaseParser::consume() {
    if (done()) {
#if (DEBUG)
        std::cout << "index: " << index << "; current: NULLPTR" << std::endl;
#endif
        return current = nullptr;
    } else {
        current = tokens->at((unsigned long) ++index);

#if(DEBUG)
        std::cout << "index: " << index << "; current: ";
        current->dump();
#endif

        return current;
    }
}

TokenType BaseParser::peekType() {
    Token *token = peek();
    return (TokenType) (token == nullptr ? -1 : token->getType());
}
