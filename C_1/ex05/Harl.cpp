#include "Harl.hpp"

int determine_level(std::string &level)
{
    const char *levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            return i;
    }
    return -1;
}

void Harl::complain(std::string level)
{
    void (Harl::*arr[4])(void) = {&Harl::debug,&Harl::info,&Harl::warning,&Harl::error};
    int lvl;
    if (( lvl = determine_level(level)) != -1)
        std::cout << "[ " << lvl << " ]\n";
    else
        std::cout << "Damn it all!\n";
}
