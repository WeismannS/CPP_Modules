#ifndef SCALAR_HPP

#define SCALAR_HPP
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
class ScalarConverter {
private:
  ScalarConverter();
  ~ScalarConverter();
  static void convert_to_char(std::string str);
  static void convert_to_int(std::string str);
  static void convert_to_float(std::string str); 
  static void convert_to_double(std::string str);
public:
  template <typename T> static void convert(std::string str) {
    if (typeid(T) == typeid(char))
        return  convert_to_char(str);
    if (typeid(T) == typeid(int))
        return  convert_to_int(str);
    if (typeid(T) == typeid(double))
        return  convert_to_float(str);
    if (typeid(T) == typeid(float))
        return  convert_to_double(str);
    return ;
  }
};

#endif

