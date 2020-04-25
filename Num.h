//
// Created by seb on 25.04.2020.
//

#ifndef TRANSLATOR_NUM_H
#define TRANSLATOR_NUM_H

#include "Token.h"
#include "Tag.h"

struct Num : public Token {
    int m_value;
    explicit Num(int value):Token{static_cast<int>(Tag::NUM)}, m_value{value} {}
};


#endif //TRANSLATOR_NUM_H
