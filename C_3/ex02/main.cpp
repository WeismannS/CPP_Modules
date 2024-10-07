
#include "FragTrap.hpp"


int main()
{
    FragTrap fragtrap("Fragtrap");
    FragTrap fragtrap2("Fragtrap2");
    
    fragtrap.attack("Fragtrap2");
    fragtrap2.takeDamage(20);
    fragtrap2.takeDamage(20);
    fragtrap2.takeDamage(20);
    fragtrap2.highFivesGuys();
    
    return 0;
}