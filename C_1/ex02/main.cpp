#include <string>
#include <iostream>



int main()
{
    std::string s = "HI THIS IS BRAIN";
    std::string *stringPTR = &s;
    std::string &stringREF = s;

    std::cout << &s << '\n';
    std::cout << &stringPTR << '\n';
    std::cout << &stringREF << '\n';

    std::cout << s << '\n';
    std::cout << *stringPTR << '\n';
    std::cout << stringREF << '\n';
}