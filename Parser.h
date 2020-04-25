//
// Created by seb on 25.04.2020.
//
// program to translate infix -> postfix expression

// expr -> term rest
// rest -> + term {print('+')} rest
//      |  - term {print('-')} rest
//      |  E
// term -> 0 {print('0')}
//      | ...
//      |  9 {print('9')}


#ifndef TRANSLATOR_PARSER_H
#define TRANSLATOR_PARSER_H

#include <sstream>

class Parser {
    char m_lookahead;
    std::stringstream m_ss;
    void term();
    void match(char cc);
public:
    explicit Parser(std::stringstream ss);
    void expr();
};


#endif //TRANSLATOR_PARSER_H
