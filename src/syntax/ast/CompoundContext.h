//
// Created by Tobe on 4/8/17.
//

#ifndef FORMULA_COMPOUNDCONTEXT_H
#define FORMULA_COMPOUNDCONTEXT_H
#include <vector>
#include "ElementContext.h"

class CompoundContext {
private:
    std::vector<ElementContext*> elements;
public:
    ~CompoundContext();
    const std::vector<ElementContext*>* getElements();
    void addElement(ElementContext *element);
};


#endif //FORMULA_COMPOUNDCONTEXT_H
