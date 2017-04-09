//
// Created by Tobe on 4/8/17.
//

#include "Parser.h"

Parser::Parser(std::vector<Token *> *tokens) : BaseParser(tokens) {
    consume();
}

EquationContext *Parser::parseEquation() {
    FormulaContext *left = parseFormula();

    if (left != nullptr) {
        if (current != nullptr && current->getType() == TokenType::ARROW) {
            consume();
            FormulaContext *right = parseFormula();

            if (right != nullptr) {
                return new EquationContext(left, right);
            } else throw "syntax error: expected formula after arrow";
        } else throw "syntax error: expected arrow after formula";
    }

    return nullptr;
}

FormulaContext *Parser::parseFormula() {
    std::vector<TermContext *> terms;
    TermContext *term = parseTerm();

    while (term != nullptr) {
        terms.push_back(term);

        if (current != nullptr && current->getType() == PLUS) {
            consume();
            term = parseTerm();
        } else break;
    }

    if (!terms.empty()) {
        FormulaContext *formula = new FormulaContext();

        for (unsigned long i = 0; i < terms.size(); i++)
            formula->addTerm(terms.at(i));

        return formula;
    }

    return nullptr;
}

TermContext *Parser::parseTerm() {
    int coefficient = 1;

    if (current != nullptr && current->getType() == TokenType::NUMBER) {
        coefficient = atoi(current->getText().c_str());
        consume();
    }

    std::vector<TermMemberContext *> members;
    TermMemberContext *member = parseTermMember();

    while (member != nullptr) {
        members.push_back(member);
        member = parseTermMember();
    }

    if (!members.empty()) {
        TermContext *term = new TermContext();

        for (unsigned long i = 0; i < members.size(); i++)
            term->addMember(members.at(i));

        term->setCoefficient(coefficient);
        return term;
    }

    return nullptr;
}

TermMemberContext *Parser::parseTermMember() {
    CompoundContext *compound = parseCompound();

    if (compound != nullptr) {
        TermMemberContext *member = new TermMemberContext();
        member->setCompound(compound);
        return member;
    }

    ElementContext *element = parseElement();

    if (element != nullptr) {
        TermMemberContext *member = new TermMemberContext();
        member->setElement(element);
        return member;
    }

    if (current != nullptr && current->getType() == TokenType::LPAREN) {
        consume();
        TermMemberContext *member = parseTermMember();

        if (member != nullptr) {
            if (current != nullptr && current->getType() == TokenType::RPAREN) {
                consume();
                return member;
            } else throw "syntax error: unclosed parenthesis";
        } else throw "syntax error: expected term member after parenthesis";
    }

    return nullptr;
}

CompoundContext *Parser::parseCompound() {
    std::vector<ElementContext*> elements;
    ElementContext *element =parseElement();

    while (element != nullptr) {
        elements.push_back(element);
        element = parseElement();
    }

    if (!elements.empty()) {
        CompoundContext *compound = new CompoundContext();

        for (unsigned long i = 0; i < elements.size(); i++) {
            compound->addElement(elements.at(i));
        }

        return compound;
    }

    return nullptr;
}

ElementContext *Parser::parseElement() {
    if (current != nullptr && current->getType() == TokenType::NAME) {
        Token *name = current;
        int subscript = 1;
        consume();

        if (current != nullptr && current->getType() == TokenType::NUMBER) {
            subscript = atoi(current->getText().c_str());
            consume();
        }

        return new ElementContext(name->getText(), subscript);
    }

    return nullptr;
}
