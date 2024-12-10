#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : __contacts_counter(0) {}

void PhoneBook::add(contact new_contact)
{
    contacts[this->__contacts_counter % 8] = new_contact;
    this->__contacts_counter++;
}

int PhoneBook::get_counter()
{
    return this->__contacts_counter;
}

void displayContacts(contact contacts)
{
    const static char *av[] = {"FirstName", "LastName", "NickName"};
    
        for (int e = 0; e < 3; e++)
            std::cout << std::right << std::setw(C_WIDE) << (contacts[av[e]].size() > 10 ? (contacts[av[e]].substr(0, 9) + ".") : contacts[av[e]]) << " |";
    std::cout << std::endl;
}

void PhoneBook::display()
{
    const static char *av[] = {"FirstName", "LastName", "NickName", "DarkestSecret"};
    unsigned short index;
    std::cout << std::right << std::setw(C_WIDE) << "Index" << " |";
    std::cout << std::right << std::setw(C_WIDE) << "FirstName" << " |";
    std::cout << std::right << std::setw(C_WIDE) << "LastName" << " |";
    std::cout << std::right << std::setw(C_WIDE) << "NickName" << " |";
    std::cout << std::endl;
    int min = std::min(this->__contacts_counter, 8);
    for (int i = 0; i < min; i++)
    {
        std::cout << std::right << std::setw(C_WIDE) << i << " |";
        displayContacts(this->contacts[i]);
    }
    index = 0;
    while (!std::cin.eof() && (std::cout << "Insert your contact's index to display more info\n") && !(std::cin >> index))
        flush();
    if (std::cin.eof())
    	return;
    if (index > (this->__contacts_counter % 8))
        return;
    for (int e = 0; e < 4; e++)
        std::cout << av[e]<<": " << contacts[index][av[e]] << std::endl;
}