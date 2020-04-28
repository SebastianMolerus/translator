//
// Created by seb on 25.04.2020.
//

#ifndef TRANSLATOR_LEXER_H
#define TRANSLATOR_LEXER_H

#include "Word.h"

#include "Token.h"

#include <vector>
#include <memory>


class Lexer {
    int m_line_number = 1;
    char m_peek = ' ';
    std::vector<std::unique_ptr<Word>> m_words;

    public:
    void reserve(Word w);
    Lexer();
    std::unique_ptr<Token> scan();
};


#endif //TRANSLATOR_LEXER_H
