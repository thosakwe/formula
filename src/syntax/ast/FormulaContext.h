//
// Created by Tobe on 4/8/17.
//

#ifndef FORMULA_FORMULACONTEXT_H
#define FORMULA_FORMULACONTEXT_H
#include <vector>
#include "TermContext.h"

class FormulaContext {
private:
    std::vector<TermContext*> terms;
public:
    ~FormulaContext();
    const std::vector<TermContext*>* getTerms();
    void addTerm(TermContext*);
};


#endif //FORMULA_FORMULACONTEXT_H
