//
// Created by Tobe on 4/8/17.
//

#include "TermMemberContext.h"

TermMemberContext::~TermMemberContext() {
    if (compound != nullptr)
        delete compound;
    else if (element != nullptr)
        delete element;
}

const CompoundContext *TermMemberContext::getCompound() {
    return compound;
}

const ElementContext *TermMemberContext::getElement() {
    return element;
}

void TermMemberContext::setCompound(CompoundContext *compound) {
    if (element != nullptr || this->compound != nullptr)
        throw "Cannot overwrite term member.";
    else this->compound = compound;
}

void TermMemberContext::setElement(ElementContext *element) {
    if (this->element != nullptr || compound != nullptr)
        throw "Cannot overwrite term member.";
    else this->element = element;
}
