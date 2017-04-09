//
// Created by Tobe on 4/8/17.
//

#ifndef FORMULA_PARSER_H
#define FORMULA_PARSER_H
#include "ast/EquationContext.h"
#include "BaseParser.h"

class Parser : private BaseParser {
public:
    Parser(std::vector<Token *> *);
    EquationContext* parseEquation();
    FormulaContext* parseFormula();
    TermContext* parseTerm();
    TermMemberContext* parseTermMember();
    CompoundContext* parseCompound();
    ElementContext* parseElement();
};


#endif //FORMULA_PARSER_H
