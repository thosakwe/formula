#include <fstream>
#include <iostream>
#include "src/syntax/Lexer.h"
#include "src/syntax/Parser.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "fatal error: no input file" << std::endl;
        return 1;
    }

    std::ifstream ifs(argv[1]);

    if (!ifs) {
        std::cerr << "fatal error: could not open file " << argv[1] << std::endl;
        return 1;
    }

    std::vector<Token*> tokens;
    Lexer *lexer = new Lexer();

    if (!lexer->scan(tokens, ifs >> std::skipws)) {
        std::cerr << "fatal error: syntax error, could not parse." << std::endl;
        delete lexer;
        return 1;
    }

#if(DEBUG)
    std::cout << tokens.size() << " token(s):" << std::endl;

    for (unsigned long i = 0; i < tokens.size(); i++) {
        Token *token = tokens.at(i);
        token->dump();
    }
#endif

    Parser *parser = new Parser(&tokens);

    try {
        EquationContext *equation = parser->parseEquation();

        if (equation == nullptr) {
            std::cerr << "fatal error: invalid chemical equation supplied." << std::endl;
            return 1;
        }

        std::cout << "TODO: Balance equation..." << std::endl;

        return 0;
    } catch(const char *err) {
        std::cerr << err << std::endl;
        return 1;
    }
}