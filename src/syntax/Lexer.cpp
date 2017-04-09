//
// Created by Tobe on 4/8/17.
//

#include "Lexer.h"

bool Lexer::scan(std::vector<Token *> &tokens, std::istream &input) {
    char ch;
    input.read(&ch, 1);

    while (input.gcount() == 1) {
        if (ch == '+') {
            tokens.push_back(new Token(TokenType::PLUS, "+"));
        } else if (ch == '(') {
            tokens.push_back(new Token(TokenType::LPAREN, "("));
        } else if (ch == ')') {
            tokens.push_back(new Token(TokenType::RPAREN, ")"));
        } else if (ch == '-' && input.peek() == '>') {
            input.read(&ch, 1); // Consume '>'
            tokens.push_back(new Token(TokenType::ARROW, "->"));
        } else if (isupper(ch)) {
            std::stringstream ss;
            ss << ch;

            while (islower(input.peek())) {
                input.read(&ch, 1);
                ss << ch;
            }

            tokens.push_back(new Token(TokenType::NAME, ss.str()));
        } else if (isnumber(ch)) {
            std::stringstream ss;
            ss << ch;

            while (isnumber(input.peek())) {
                input.read(&ch, 1);
                ss << ch;
            }

            tokens.push_back(new Token(TokenType::NUMBER, ss.str()));
        }

        input.read(&ch, 1);
    }

    return true;
}
