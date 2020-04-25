#include <iostream>
#include <sstream>
#include "Parser.h"

#include "Word.h"
#include "Token.h"
#include "Num.h"

using namespace std;

stringstream read_input()
{
    stringstream ss;
    for(char cc; cin.get(cc) && 'q' != tolower(cc);)
    {
        ss<<cc;
    }
    return ss;
}


int main() {


    auto p = Parser(read_input());
    p.expr();
}
