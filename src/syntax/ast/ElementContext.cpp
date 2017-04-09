//
// Created by Tobe on 4/8/17.
//

#include "ElementContext.h"

ElementContext::ElementContext(std::string name, int subscript) : name(name), subscript(subscript) {}

ElementContext::~ElementContext() {
    name.erase();
}

const std::string ElementContext::getName() {
    return name;
}

const int ElementContext::getSubscript() {
    return subscript;
}
