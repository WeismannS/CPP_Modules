#include "Zombie.hpp"



Zombie::Zombie(std::string name) : name(name) {};

void Zombie::announce()
{
    std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ...\n" << std::endl;
}
Zombie::~Zombie()
{
    std::cout << this->name << " Destroyed!\n";
}

Zombie::Zombie()
{
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
