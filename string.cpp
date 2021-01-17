#include "string.h"
#include <iostream>

int main()
{
    string s1;
    string s2("hello");
    string s3(s2);
    s2 = "world";
    string s4 { "hello bash!"};
    string s5 = { "yes or no" };

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
    std::cout << s5 << std::endl;

    return 0;
}