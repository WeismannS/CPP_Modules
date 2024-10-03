#ifndef PHONE_HPP
#define PHONE_HPP
#include "Contact.hpp"

class PhoneBook
{
private:
     int __contacts_counter;

public  :
            PhoneBook();
            contact contacts[7];
            void add(contact new_contact);
            void display();
            int get_counter();
};
#endif