#include <iostream>
#include <sstream>

#include "Lexer.h"
#include "Num.h"

using namespace std;

int main() {

    auto t2 = Lexer{}.scan();

    cout<<static_cast<Num*>(t2.get())->m_value;
}

