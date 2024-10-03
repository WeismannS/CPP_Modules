#include "Zombie.hpp"



Zombie::Zombie(std::string name) : name(name) {};

void Zombie::announce()
{
    std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::~Zombie()
{
    std::cout << this->name << " Destroyed!";
}

