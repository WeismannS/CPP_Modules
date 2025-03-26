#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(std::string database_file) {
  std::ifstream data(database_file.c_str());
  std::string buffer;
  if (!data.is_open())
    throw std::invalid_argument("File could not be opened!");
  std::getline(data, buffer);
  while (std::getline(data, buffer)) {
    unsigned int date;
    double rate;
    std::stringstream extracted(buffer);
    parse_line(extracted, ',');
    extracted >> date >> rate;
    this->add(date, rate);
  }
}
void extract_date(std::stringstream &line)
{
    std::string buffr;
    std::getline(line, buffr, '|');

    std::cout << buffr.substr(0, buffr.find_first_of(" "));
}
void BitcoinExchange::consume(std::string input_file) {
  std::ifstream data(input_file.c_str());
  std::string buffer;
  if (!data.is_open())
    throw std::invalid_argument("File could not be opened!");
  std::getline(data, buffer);
  while (std::getline(data, buffer)) {
    unsigned int date;
    double rate;
    try {
        std::stringstream extracted(buffer);
      parse_line(extracted, '|');
      extracted >> date >> rate;
      std::stringstream tmp(buffer);
      extract_date(tmp);
      std::cout << " => " << rate << " = " << (rate * this->getRate(date)->second) << "\n" ;
    } catch (std::exception &e) {
       std::cout << "Error : " << e.what() << "\n";
    }
  }
}

void BitcoinExchange::parse_line(std::stringstream &sline, char delim) {
  int year;
  int month;
  int day;
  double rate;
  sline >> year;
  if (sline.get() != '-')
    throw BitcoinExchange::invalid_date();
  sline >> month;
  if (sline.get() != '-')
    throw BitcoinExchange::invalid_date();
  sline >> day;
  if (year <= 0 || (day > 31 || day <= 0) || (month > 12 || month <= 0))
    throw BitcoinExchange::invalid_date();
  skip_spaces(sline);
  if (sline.get() != delim)
    throw BitcoinExchange::invalid_rate();
  if (!(sline >> rate))
    throw BitcoinExchange::invalid_rate();
  if (rate < 0 || rate >= static_cast<double>(std::numeric_limits<int>::max()))
    throw BitcoinExchange::invalid_rate();
  sline.str(""), sline.seekg(0);
  sline << year << month << day << " " << rate;
}

void BitcoinExchange::add(Date date, double rate) { this->rates[date] = rate; }



std::map<Date, double>::iterator BitcoinExchange::getRate(Date date) {
    std::map<Date, double>::iterator it = this->rates.upper_bound(date);
    if (it != this->rates.begin())
        it--;
    return it;
}

void BitcoinExchange::skip_spaces(std::stringstream &s) {
  char c;
  c = s.get();
  while (c == ' ' || c == '\t')
    c = s.get();
  s.unget();
}
BitcoinExchange::~BitcoinExchange() {}
