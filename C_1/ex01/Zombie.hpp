#ifndef ZOMBIE_CPP
#define ZOMBIE_CPP
#include <iostream>
#include <string>



class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string name);
    Zombie();
    void setName(std::string name);
    ~Zombie();
    void announce();
};

void randomChump( std::string name);
Zombie* newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name);
#endif