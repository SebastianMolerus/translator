//
// Created by seb on 25.04.2020.
//

#include "Parser.h"
#include <iostream>

using std::cout;
using std::runtime_error;
using std::stringstream;

Parser::Parser(stringstream ss)
:m_ss{std::move(ss)}
{
    m_lookahead = m_ss.get();
}

void Parser::term() {
    if(isdigit(m_lookahead))
    {
        char x = m_lookahead;
        match(m_lookahead);
        cout<<x;
    } else
        throw runtime_error("Expected term as digit.");
}

void Parser::match(char cc) {
    if(m_lookahead == cc)
    {
        m_lookahead = m_ss.get();
    }
    else{
        throw runtime_error("Invalid syntax");
    }
}

void Parser::expr() {
    term();
    while(true)
    {
        if(m_lookahead == '+') {
            match('+');
            term();
            cout << '+';
            continue;
        }
        else if(m_lookahead == '-') {
            match('-');
            term();
            cout << '-';
            continue;
        } else
            return;
    }
}
