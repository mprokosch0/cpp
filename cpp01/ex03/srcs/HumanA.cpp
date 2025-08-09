#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << GRAY << this->_name << " HumanA constructor called" RESET << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << GRAY << this->_name << " HumanA destructor called" RESET << std::endl;
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << PINK << this->_name << GREEN " attacks with their " RED
			  << this->_weapon.getType() << RESET << std::endl;
	return ;
}

