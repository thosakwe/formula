//
// Created by Tobe on 4/8/17.
//

#include "FormulaContext.h"

FormulaContext::~FormulaContext() {
    for (unsigned long i = 0; i < terms.size(); i++) {
        delete terms.at(i);
    }
}

const std::vector<TermContext *> *FormulaContext::getTerms() {
    return &terms;
}

void FormulaContext::addTerm(TermContext *term) {
    terms.push_back(term);
}
