#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << name << " is born!" << std::endl;
}



FragTrap::~FragTrap()
{
    std::cout << "Frag Trap " << _name << " was destroyed!\n";
}

FragTrap::FragTrap(FragTrap const &other)
{
    _name = other._name;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    _hitPoints = other._hitPoints; 
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
     _name = other._name;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    _hitPoints = other._hitPoints;
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "High FIve!\n";
}