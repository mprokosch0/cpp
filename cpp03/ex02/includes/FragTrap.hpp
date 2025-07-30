
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const & name);
		FragTrap(FragTrap const & right);
		FragTrap & operator=(FragTrap const & right);
		~FragTrap(void);
	
	public:
		void setName(std::string const & name);
		void highFivesGuys(void);
		std::string const & getName(void);
};


#endif