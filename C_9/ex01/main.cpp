
#include "RPN.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>
int main(int ac, char *av[]) {
  if (ac != 2)
    throw std::invalid_argument("wrong number of arguments");
  try {

    RPN a(av[1]);
    std::cout << a.result() << "\n";
  } catch (std::exception &e) {
    std::cout << "Error\n";
  }
}
