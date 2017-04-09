//
// Created by Tobe on 4/8/17.
//

#ifndef FORMULA_EQUATIONBALANCER_H
#define FORMULA_EQUATIONBALANCER_H
#include <map>
#include <string>
#include "syntax/ast/EquationContext.h"

class EquationBalancer {
public:
    static bool isBalanced(const EquationContext&);
};


#endif //FORMULA_EQUATIONBALANCER_H
