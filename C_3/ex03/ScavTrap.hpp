#ifndef ScavTrap_HPP

# define ScavTrap_HPP

# include <iostream>

# include <string>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap 
{
    public:
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(ScavTrap const &other);
        ScavTrap &operator=(ScavTrap const &other);
        ScavTrap();
        void attack(std::string const &target);
        void guardGate();
};

#endif