
#include "ScavTrap.hpp"


int main()
{
    ScavTrap scavtrap("Scavtrap");
    ScavTrap scavtrap2("Scavtrap2");

    scavtrap.attack("Scavtrap2");
    scavtrap2.takeDamage(20);
    scavtrap2.takeDamage(20);
    scavtrap2.takeDamage(20);
    scavtrap2.guardGate();

    return 0;
}