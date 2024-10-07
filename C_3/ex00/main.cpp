#include "ClapTrap.hpp"



int main()
{
    ClapTrap claptrap("Claptrap");
    ClapTrap claptrap2("Claptrap2");

    claptrap.attack("Claptrap2");
    claptrap2.takeDamage(5);
    claptrap2.takeDamage(5);
    claptrap2.takeDamage(5);

    return 0;
}