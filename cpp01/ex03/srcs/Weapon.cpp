#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
	std::cout << GRAY << this->_type << " Weapon constructor called" RESET << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << GRAY << this->_type << " Weapon destructor called" << RESET << std::endl;
	return ;
}

std::string Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string nType)
{
	std::cout << BLUE << this->_type << YELLOW " weapon changed to " BLUE
			  << nType << RESET << std::endl;
	this->_type = nType;
	return ;
}
