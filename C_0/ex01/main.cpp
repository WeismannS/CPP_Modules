#include "PhoneBook.hpp"
#include <limits>

std::string getInput(std::string prompt)
{
    std::cout << prompt << '\n';
    std::string input;
    std::getline(std::cin >> std::ws,input);
    return (input);
}

void flush()
{
    std::cout << "Please insert a valid phone number!:\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}
contact getContact()
{
    contact new_contact;

    new_contact.firstName = getInput("Please Insert your first name!:");
    new_contact.LastName = getInput("Please Insert your second name!:");
    new_contact.NickName = getInput("Please Insert your Nickname!:");
    new_contact.DarkestSecret = getInput("Please Insert your DarkestSecret!");
    std::cout << "Please insert your phone number!" << '\n';
    while (!(std::cin >> new_contact.number))
        flush();
    return new_contact;
}

int main()
{
    PhoneBook book;
    std::string command;
    while (true)
    {
        std::cout << "INSERT YOUR COMMAND!: (ADD/SEARCH/EXIT) \n";
        std::cin >> command;
        if (command == "ADD")
            book.add(getContact());
        else if (command == "SEARCH")
            book.display();
        else if (command == "EXIT")
            break;
    }
}