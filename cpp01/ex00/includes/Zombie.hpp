#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

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