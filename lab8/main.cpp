#include <iostream>

#include "RationalNumber.h"
#include "Program.h"

int main() {

    RationalNumber<int> a{2,4};
    RationalNumber<int> b{3,4};
    Program show(a,b);

    std::cout << show.ShowAllOperations() << '\n';
    return 0;
}
