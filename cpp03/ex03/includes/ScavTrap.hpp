#ifndef SCAVTRAP_HPP

# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & right);
		ScavTrap & operator=(ScavTrap const & right);
		~ScavTrap(void);
	
	public:
		void guardGate(void);
		void attack(const std::string& target);
		std::string const & getName(void);
};

#endif