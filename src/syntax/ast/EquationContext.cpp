//
// Created by Tobe on 4/8/17.
//

#include "EquationContext.h"

EquationContext::~EquationContext() {
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
}

FormulaContext *EquationContext::getLeft() const {
    return left;
}

FormulaContext *EquationContext::getRight() const {
    return right;
}

EquationContext::EquationContext(FormulaContext *left, FormulaContext *right) : left(left), right(right) {}
