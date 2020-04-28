//
// Created by seb on 25.04.2020.
//

#include "Lexer.h"
#include "Num.h"
#include "Token.h"
#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::ostringstream;
using std::string;

void Lexer::reserve(Word w) {
   m_words.push_back(std::make_unique<Word>(w));
}

Lexer::Lexer() {
    reserve(Word(static_cast<int>(Tag::TRUE), "true"));
    reserve(Word(static_cast<int>(Tag::FALSE), "false"));
}

std::unique_ptr<Token> Lexer::scan() {

    // Eat white spaces
    for(;;cin.get(m_peek))
    {
        if(m_peek == ' ' || m_peek == '\t')
            continue;
        else if(m_peek == '\n')
            ++m_line_number;
        else
            break;
    }

    // One line comment // ...
    if(m_peek == '/' && static_cast<char>(cin.peek()) == '/')
    {
        do{
            cin.get(m_peek);
        }
        while(m_peek != '\n');
        return scan();
    }
    // Multi-line comment /* ... */
    else if(m_peek == '/' && static_cast<char>(cin.peek()) == '*')
    {
        while(!(m_peek == '*' && static_cast<char>(cin.peek()) == '/'))
            cin.get(m_peek);
        return scan();
    }

    // Numerical founded
    if(isdigit(m_peek))
    {
        int v = 0;
        do{
            v = 10 * v + (static_cast<int>(m_peek) - 48);
            cin.get(m_peek);
        }
        while(isdigit(m_peek));
        return std::make_unique<Num>(v);
    }

    // Alphanum founded
    if(isalpha(m_peek))
    {
        ostringstream oss;
        do{
            oss<<m_peek;
            cin.get(m_peek);
        }while(isalpha(m_peek));
        string s = oss.str();

        auto result = std::find_if(begin(m_words), end(m_words),
                [&s](auto& w) {return w->lexeme == s;});

        if(result != m_words.end())
            return std::make_unique<Word>(*result->get());

        return std::make_unique<Word>(static_cast<int>(Tag::ID), s);
    }

    return std::make_unique<Token>(m_peek);
}
