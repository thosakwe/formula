//
// Created by Tobe on 4/8/17.
//

#ifndef FORMULA_TERM_H
#define FORMULA_TERM_H
#include <vector>
#include "TermMemberContext.h"

class TermContext {
private:
    std::vector<TermMemberContext*> members;
    int coefficient;
public:
    ~TermContext();
    const std::vector<TermMemberContext*>* getMembers();
    void addMember(TermMemberContext*);

    int getCoefficient() const;

    void setCoefficient(int coefficient);
};


#endif //FORMULA_TERM_H
