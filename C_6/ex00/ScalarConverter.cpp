
#include "ScalarConverter.hpp"
#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <cmath>
#include <iomanip>
#include <ios>
#include <limits.h>
#include <limits>
ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}
void ScalarConverter::convert_to_char(std::string str) {
    std::cout << "char: ";
    char *end;
        int value = strtod(str.c_str(), &end);
        if (str.length() == 1 && isascii(str[0]))
            return std::cout << "'" << str[0] << "'" << std::endl, (void) 0;
        if (value < 0 || value > 127|| (*end != '\0')) 
            return std::cout << "impossible" << std::endl, (void) 0;
        if (!isprint(value))
            return std::cout << "Non displayable" << std::endl, (void) 0;
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::convert_to_int(std::string str) {
    std::cout << "int: ";
    try {
        char* end;
        double value = strtod(str.c_str(), &end);
        if ((*end != '\0' && *end != 'f')|| errno == ERANGE || value > INT_MAX || value < INT_MIN)
            throw std::exception();
        std::cout << (int) value << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "impossible" << std::endl;
    }
}




void ScalarConverter::convert_to_float(std::string str) {
    std::cout << "float: ";
    try {
        char* end;
        float value = strtof(str.c_str(), &end);
        if (value == INFINITY || value == -INFINITY || value != value)
            return std::cout << value  << std::endl, (void) 0;
        if ((*end != '\0' && *end != 'f') || errno == ERANGE || (static_cast<int>(value) != atoi(str.c_str())) )
            throw std::exception();
        std::cout << std::setprecision(str.length() - (str.find_first_of(".") != std::string::npos) - (str.find_first_of("f") != std::string::npos)) << value <<  
        (value == static_cast<int>(value) ? ".0" : "")
        << "f" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "impossible" << std::endl;
    }
}

void ScalarConverter::convert_to_double(std::string str) {
    std::cout << "double: ";
    try {
        char* end;
        double value = strtod(str.c_str(), &end);
        if ((*end != '\0' && *end != 'f') || errno == ERANGE)
            throw std::exception();
        std::cout << std::setprecision(str.length() - (str.find_first_of(".") != std::string::npos) - (str.find_first_of("f") != std::string::npos)) << value <<  
        (value == static_cast<int>(value) ? ".0" : "")
        << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "impossible" << std::endl;
    }
}