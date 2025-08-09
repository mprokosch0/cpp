#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define GRAY "\033[90m"
# define PINK "\033[35m"

class Weapon
{
	private:
		std::string	_type;
	
	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string	getType(void) const;
		void	setType(std::string nType);
};

#endif