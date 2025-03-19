#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>



int main(int ac, char *av[])
{
   if (ac != 2)
        throw std::invalid_argument("No file to read from!");
    BitcoinExchange exchange("data.csv");
   exchange.consume(av[1]);
}