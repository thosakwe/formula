//
// Created by Tobe on 4/8/17.
//

#include "TermContext.h"

TermContext::~TermContext() {
    for (unsigned long i = 0; i < members.size(); i++) {
        delete members.at(i);
    }
}

const std::vector<TermMemberContext *> *TermContext::getMembers() {
    return &members;
}

void TermContext::addMember(TermMemberContext *member) {
    members.push_back(member);
}

int TermContext::getCoefficient() const {
    return coefficient;
}

void TermContext::setCoefficient(int coefficient) {
    this->coefficient = coefficient;
}
