#include <iostream>
#include <sstream>
#include "Parser.h"

using namespace std;

stringstream read_input()
{
    stringstream ss;
    for(char cc; cin>>cc && tolower(cc) != 'q';)
    {
        ss<<cc;
    }
    return ss;
}


int main() {
    auto p = Parser(read_input());
    p.expr();
}
