
#ifndef CLAPTRAP_CPP

# define CLAPTRAP_CPP

# include <iostream>
# include <string>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define GRAY "\033[90m"

class ClapTrap
{
	private:
		std::string	_name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;


	public:
		ClapTrap(void);
		ClapTrap(ClapTrap const & right);
		~ClapTrap(void);
	
	public:
		ClapTrap & operator=(ClapTrap const & right);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif