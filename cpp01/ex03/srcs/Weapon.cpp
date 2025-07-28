#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
	std::cout << this->_type << " Weapon constructor called" << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << this->_type << " Weapon destructor called" << std::endl;
	return ;
}

std::string Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string nType)
{
	this->_type = nType;
	return ;
}
