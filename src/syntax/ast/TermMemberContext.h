//
// Created by Tobe on 4/8/17.
//

#ifndef FORMULA_TERMMEMBER_H
#define FORMULA_TERMMEMBER_H
#include "CompoundContext.h"
#include "ElementContext.h"

class TermMemberContext {
private:
    CompoundContext *compound = nullptr;
    ElementContext *element = nullptr;
public:
    ~TermMemberContext();
    const CompoundContext* getCompound();
    const ElementContext* getElement();
    void setCompound(CompoundContext*);
    void setElement(ElementContext*);
};


#endif //FORMULA_TERMMEMBER_H
