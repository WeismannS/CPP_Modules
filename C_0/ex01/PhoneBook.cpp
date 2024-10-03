#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : __contacts_counter(0) {}

void PhoneBook::add(contact new_contact)
{
    contacts[this->__contacts_counter] = new_contact;
    this->__contacts_counter = (this->__contacts_counter + 1) > 7 ? 7 : this->__contacts_counter + 1;
}

int PhoneBook::get_counter()
{
    return this->__contacts_counter;
}

void displayContacts(PhoneBook *book)
{
    const static char *av[] = {"FirstName", "LastName", "NickName"};

    for (int i = 0; i < book->get_counter(); i++)
        for (int e = 0; e < 3; e++)
            std::cout << std::right << std::setw(C_WIDE) << (book->contacts[i][av[e]].size() > 10 ? (book->contacts[i][av[e]].substr(0, 9) + ".") : book->contacts[i][av[e]]) << " |";
    std::cout << std::endl;
}

void PhoneBook::display()
{
    const static char *av[] = {"FirstName", "LastName", "NickName", "DarkestSecret"};
    short index;
    std::cout << std::right << std::setw(C_WIDE) << "Index" << " |";
    std::cout << std::right << std::setw(C_WIDE) << "FirstName" << " |";
    std::cout << std::right << std::setw(C_WIDE) << "LastName" << " |";
    std::cout << std::right << std::setw(C_WIDE) << "NickName" << " |";
    std::cout << std::endl;
    for (int i = 0; i < this->__contacts_counter; i++)
    {
        std::cout << std::right << std::setw(C_WIDE) << i << " |";
        displayContacts(this);
    }
    std::cout << "Insert your contact's index to display more info\n";
    std::cin >> (index);
    if (index > this->__contacts_counter - 1)
        return;
    for (int e = 0; e < 4; e++)
        std::cout << "First Name: " << contacts[index][av[e]] << std::endl;
}