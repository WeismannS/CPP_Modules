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
    
    switch(determine_level(level))
    {
        case 0 : 
            (this->*arr[0])();
            // fall through
        case 1 : 
            (this->*arr[1])();
            // fall through
        case 2 :
            (this->*arr[2])();
            // fall through
        case 3 :
            (this->*arr[3])();
            // fall through
        default :
            std::cout << "Damn it all!\n";
            break;
    }
}