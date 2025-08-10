
#include "../includes/FragTrap.hpp"

//Operators---------------------------------------------------------------

FragTrap &FragTrap::operator=(FragTrap const & right)
{
	std::cout << GRAY "FragTrap operator = called" RESET << std::endl;
	this->_attackDamage = right._attackDamage;
	this->_energyPoints = right._energyPoints;
	this->_hitPoints = right._hitPoints;
	this->_name = right._name;
	return *this;
}

//Constructor/destructors-------------------------------------------------

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << GRAY "Default FragTrap constructor called" RESET << std::endl;
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	return ;
}

FragTrap::FragTrap(std::string const & name): ClapTrap()
{
	std::cout << GRAY "Named FragTrap constructor called" RESET << std::endl;
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_name = name;
	return ;
}

FragTrap::FragTrap(FragTrap const & right): ClapTrap(right)
{
	std::cout << GRAY "Copy ClapTrap constructor called" RESET << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << GRAY "FragTrap destructor called" RESET << std::endl;
	return ;
}

//Member functions

void FragTrap::highFivesGuys(void)
{
	std::cout << PINK "FragTrap named: " << this->_name
			  << ", raise his hand spontaneously to make a high-five !" RESET
			  << std::endl;
	return ;
}

void FragTrap::setName(std::string const & name)
{
	std::cout << GRAY "FragTrap named " << this->_name
			  << " changed name to: " << name << RESET << std::endl;
	this->_name = name;
	return ;
}

std::string const & FragTrap::getName(void)
{
	return this->_name;
}