#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),FragTrap(name), ScavTrap(name)
{
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    std ::cout << "ScavTrap energy points: " << ScavTrap::_energyPoints << std::endl;
    this->_attackDamage = FragTrap::_attackDamage;
    std ::cout << "FragTrap attack damage: " << FragTrap::_attackDamage << std::endl;
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name   <<   " destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other._name + "_clap_name"), ScavTrap(other._name), FragTrap(other._name)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
