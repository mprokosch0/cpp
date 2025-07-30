#ifndef DIAMONDTRAP_HPP

# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	
	public:
		DiamondTrap(void);
		DiamondTrap(DiamondTrap const & right);
		DiamondTrap(std::string const & name);
		DiamondTrap & operator=(DiamondTrap const & right);
		~DiamondTrap(void);
	
	public:
		void whoAmI(void);
};

#endif