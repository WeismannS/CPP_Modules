#pragma once

#include <exception>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <exception>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
typedef unsigned int Date;
class BitcoinExchange {

public:
  std::map<Date, double> rates;
  BitcoinExchange(std::string database_file);
  BitcoinExchange(const BitcoinExchange &other);
  ~BitcoinExchange();
  const BitcoinExchange &operator=(const BitcoinExchange &other);
  void parse_line(std::stringstream &stream, char delim);
  void add(Date date, double rate);
  void skip_spaces(std::stringstream &str);
  std::map<Date, double>::iterator getRate(Date date);
  void consume(std::string input_file);
  class invalid_date : public std::exception {
  public:
    virtual const char *what() const throw() { return "invalid data"; }
  };
  class invalid_rate : public std::exception {
  public:
    virtual const char *what() const throw() { return "invalid rate!"; }
  };
};
