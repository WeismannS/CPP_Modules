#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iomanip>
#include <iostream>
#include <string>

#define C_WIDE 10
class contact
{
public:
    std::string firstName;
    std::string LastName;
    std::string NickName;
    std::string DarkestSecret;
    int         number;
    contact();
    contact(std::string first, std::string last, std::string nick, std::string secret, int num);
    std::string operator[](std::string prop);
};

#endif