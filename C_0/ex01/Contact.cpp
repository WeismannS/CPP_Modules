#include "Contact.hpp"

contact::contact() : number(0) {}

contact::contact(std::string first, std::string last, std::string nick, std::string secret, int num) : 
firstName(first),
LastName(last),
NickName(nick),
DarkestSecret(secret),
number(num)
{}