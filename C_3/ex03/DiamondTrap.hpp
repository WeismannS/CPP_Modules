#ifndef DIAMONDTRAP_HPP

# define DIAMONDTRAP_HPP

# include <iostream>

# include <string>

#include "FragTrap.hpp"

class DiamondTrap :  public FragTrap, public ScavTrap
{
private:
    std::string _name;

public:
    DiamondTrap(std::string name);
    ~DiamondTrap();
    void whoAmI();
    DiamondTrap &operator=(DiamondTrap const &other);
    DiamondTrap(DiamondTrap const &other);
};




#endif