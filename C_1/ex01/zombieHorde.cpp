#include "Zombie.hpp"



Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return NULL;
    Zombie *zomb =  new Zombie[N] ;
    for (int i = 0; i < N; i++)
        zomb[i].setName(name);
    return zomb;
}