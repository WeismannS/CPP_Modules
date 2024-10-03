#include "Zombie.hpp"


int main()
{
    Zombie *zom = newZombie("Zom");
    zom->announce();
    randomChump("Chump");
    delete zom;
    return 0;
}