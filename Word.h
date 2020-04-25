//
// Created by seb on 25.04.2020.
//

#ifndef TRANSLATOR_WORD_H
#define TRANSLATOR_WORD_H

#include <string>
#include "Tag.h"
#include "Token.h"

// class is used for reserved words and Identifiers
// object for reserved word "true" can be created as Word(Tag::TRUE, "true")

struct Word : public Token
{
    std::string lexeme;
    Word(int tag, std::string s):Token{tag}, lexeme{s} {}
};

#endif //TRANSLATOR_WORD_H
