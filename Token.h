//
// Created by seb on 25.04.2020.
//

#ifndef TRANSLATOR_TOKEN_H
#define TRANSLATOR_TOKEN_H

#include "Tag.h"

struct Token {
    int m_tag;
    explicit Token(int tag):m_tag{tag} {}
};


#endif //TRANSLATOR_TOKEN_H
