cmake_minimum_required(VERSION 3.7)
project(formula)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES
        src/syntax/TokenType.h src/syntax/Token.cpp src/syntax/Token.h src/syntax/Lexer.cpp
        src/syntax/Lexer.h src/syntax/BaseParser.cpp src/syntax/BaseParser.h
        src/syntax/Parser.cpp src/syntax/Parser.h src/syntax/ast/ElementContext.cpp src/syntax/ast/ElementContext.h src/syntax/ast/CompoundContext.cpp src/syntax/ast/CompoundContext.h src/syntax/ast/TermMemberContext.cpp src/syntax/ast/TermMemberContext.h src/syntax/ast/TermContext.cpp src/syntax/ast/TermContext.h src/syntax/ast/FormulaContext.cpp src/syntax/ast/FormulaContext.h src/syntax/ast/EquationContext.cpp src/syntax/ast/EquationContext.h src/EquationBalancer.cpp src/EquationBalancer.h)
add_executable(formula ${SOURCE_FILES} main.cpp)
add_executable(formula_debug ${SOURCE_FILES} main.cpp)

set_target_properties(formula_debug PROPERTIES COMPILE_DEFINITIONS "DEBUG")