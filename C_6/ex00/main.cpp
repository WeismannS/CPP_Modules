#include "ScalarConverter.hpp"
#include <ios>
int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Usage: ./convert [value]" << std::endl;
        return 1;
    }
    
    std::string input = argv[1];
    ScalarConverter::convert<char>(input);
    ScalarConverter::convert<int>(input);
    ScalarConverter::convert<float>(input);
    ScalarConverter::convert<double>(input);
    
    return 0;
}