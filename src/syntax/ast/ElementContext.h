//
// Created by Tobe on 4/8/17.
//

#ifndef FORMULA_ELEMENT_CONTEXT_H
#define FORMULA_ELEMENT_CONTEXT_H
#include <string>

class ElementContext {
private:
    std::string name;
    int subscript;
public:
    ElementContext(std::string, int subscript = 1);
    ~ElementContext();
    const std::string getName();
    const int getSubscript();
};


#endif //FORMULA_ELEMENT_CONTEXT_H
