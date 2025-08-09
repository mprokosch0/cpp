#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define GRAY "\033[90m"
# define PINK "\033[35m"

class	Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	annouce(void) const;
};

void	randomChunp(std::string name);
Zombie	*newZombie(std::string name);

#endif