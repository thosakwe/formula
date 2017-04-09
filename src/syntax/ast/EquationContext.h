//
// Created by Tobe on 4/8/17.
//

#ifndef FORMULA_EQUATIONCONTEXT_H
#define FORMULA_EQUATIONCONTEXT_H
#include "FormulaContext.h"

class EquationContext {
private:
    FormulaContext *left = nullptr, *right = nullptr;
public:
    ~EquationContext();
    EquationContext(FormulaContext*, FormulaContext*);

    FormulaContext *getLeft() const;

    FormulaContext *getRight() const;
};


#endif //FORMULA_EQUATIONCONTEXT_H
