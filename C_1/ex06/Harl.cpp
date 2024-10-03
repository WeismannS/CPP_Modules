#include "Harl.hpp"

int determine_level(std::string &level)
{
    if (level == "DEBUG")
        return 0;
    if (level == "INFO")
        return 1;
    if (level == "WARNING")
        return 2;
    if (level == "ERROR")
        return 3;
    return 4;
}
void Harl::complain(std::string level)
{
    void (Harl::*arr[4])(void) = {&Harl::debug,&Harl::info,&Harl::warning,&Harl::error};
    
    switch(int lvl = determine_level(level))
    {
        case 0 : 
            (this->*arr[lvl])();
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