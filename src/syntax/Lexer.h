//
// Created by Tobe on 4/8/17.
//

#ifndef FORMULA_LEXER_H
#define FORMULA_LEXER_H

#include <iostream>
#include <sstream>
#include <vector>
#include "Token.h"

class Lexer {
public:
    bool scan(std::vector<Token *> &tokens, std::istream &input);
};


#endif //FORMULA_LEXER_H
