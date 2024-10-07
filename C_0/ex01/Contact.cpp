#include "Contact.hpp"

contact::contact() : number(0) {}

contact::contact(std::string first, std::string last, std::string nick, std::string secret, int num) : 
firstName(first),
LastName(last),
NickName(nick),
DarkestSecret(secret),
number(num)
{}
std::string contact::operator[](std::string prop)
    {
        if (prop == "FirstName")
            return this->firstName;
        else if (prop == "LastName")
            return this->LastName;
        else if (prop == "NickName")
            return this->NickName;
        else if (prop == "DarkestSecret")
            return this->DarkestSecret;
        return "";
    }