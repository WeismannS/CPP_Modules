#include "PhoneBook.hpp"
#include <limits>
#include <fstream>

void flush()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

std::string getInput(std::string prompt)
{
    std::cout << prompt << '\n';
    std::string input;
    std::getline(std::cin >> std::ws,input);
    return (input);
}


contact getContact()
{
    contact new_contact;
    while ((new_contact.firstName = getInput("Please Insert your First name!:")).empty() && !std::cin.eof())
        std::cout << "Please Insert your First name!:" << '\n';
    while ( !std::cin.eof() && (new_contact.LastName = getInput("Please Insert your second name!:")).empty())
        std::cout << "Please Insert your second name!:" << '\n';
    while ( !std::cin.eof() &&(new_contact.NickName = getInput("Please Insert your Nickname!:")).empty())
        std::cout << "Please Insert your Nickname!:" << '\n';
    while ( !std::cin.eof() && (new_contact.DarkestSecret = getInput("Please Insert your Darkest Secret!:")).empty())
        std::cout << "Please Insert your Darkest Secret!:" << '\n';
    while (!std::cin.eof() && (std::cout << "Please insert your phone number!" << '\n') && !(std::cin >> new_contact.number))
        flush();
    return new_contact;
}

int main()
{
    PhoneBook book;
    std::string command;
    
        while (!std::cin.eof())
        {
            std::cout << "INSERT YOUR COMMAND!: (ADD/SEARCH/EXIT) \n";
            std::cin >> command;
            if (std::cin.eof())
                break;
            if (command == "ADD" && !std::cin.eof())
                book.add(getContact());
            else if (command == "SEARCH")
                book.display();
            else if (command == "EXIT")
                break;
        }
}