//
// Created by Tobe on 4/8/17.
//

#include "CompoundContext.h"

CompoundContext::~CompoundContext() {
    for (unsigned long i = 0; i < elements.size(); i++) {
        delete elements.at(i);
    }
}

const std::vector<ElementContext *>* CompoundContext::getElements() {
    return &elements;
}

void CompoundContext::addElement(ElementContext *element) {
    elements.push_back(element);
}
