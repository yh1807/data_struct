#include <iostream>
#include "complex.h"

int main()
{
    complex a(2, 0);
    complex b(3, 4);
    complex c = 2 + a + b;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    auto r1 = (a != b);
    auto r2 = (0 != a);
    auto r3 = (a != 2);
    std::cout << r1 << std::endl; 
    std::cout << r2 << std::endl;
    std::cout << r3 << std::endl;


    return 0;
}