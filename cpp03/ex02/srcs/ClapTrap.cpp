
#include "../includes/ClapTrap.hpp"

//Operators-------------------------------------------------------------------

ClapTrap & ClapTrap::operator=(ClapTrap const & right)
{
	std::cout << GRAY "ClapTrap operator = called" RESET << std::endl;
	this->_attackDamage = right._attackDamage;
	this->_energyPoints = right._energyPoints;
	this->_hitPoints = right._hitPoints;
	this->_name = right._name;
	return *this;
}

//Constructors/destructors----------------------------------------------------

ClapTrap::ClapTrap(void): _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GRAY "Default ClapTrap constructor called" RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & right)
{
	std::cout << GRAY "Copy ClapTrap constructor called" RESET << std::endl;
	*this = right;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << GRAY "ClapTrap destructor called" RESET << std::endl;
	return ;
}

//Member fuctions--------------------------------------------------------------

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints && this->_hitPoints > 0 && this->_hitPoints + amount <= 10)
	{
		std::cout << GREEN "ClapTrap " << this->_name << " repairs himself "
			  << amount << " hitPoints !" << RESET << std::endl;
		if (amount + this->_hitPoints > 10)
			this->_hitPoints = 10;
		else
			this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << PINK "ClapTrap " << this->_name << " can't be repaired, he has no "
					 YELLOW "energy" PINK " left" << RESET << std::endl;
	else if (this->_hitPoints <= 0)
		std::cout << PINK "ClapTrap " << this->_name << " can't be repaired, he already " RED "died"
				   << RESET << std::endl;
	else
		std::cout << PINK "ClapTrap " << this->_name << " can't repair himself to have more than 10 hp"
				   << RESET << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > (int)amount)
	{
		std::cout << RED "ClapTrap " << this->_name << " took "
			  << amount << " points of damage !" << RESET << std::endl;
		this->_hitPoints -= amount;
	}
	else if (this->_hitPoints > 0)
	{
		this->_hitPoints = 0;
		std::cout << PINK "ClapTrap " << this->_name << " took " << amount
				  << " damages and is now" RED " dead." << RESET << std::endl;
	}
	else
		std::cout << PINK "ClapTrap " << this->_name << " is already " RED "dead."
				<< RESET << std::endl;
	return ;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints && this->_hitPoints)
	{
		std::cout << BLUE "ClapTrap " << this->_name << " attacks "
			  << target << ", causing " << this->_attackDamage
			  << " points of damage !" << RESET << std::endl;
		this->_energyPoints--;
	}
	else if (!this->_energyPoints)
		std::cout << PINK "ClapTrap " << this->_name << " can't attack, he has no "
					YELLOW "energy" PINK " left" << RESET << std::endl;
	else
		std::cout << PINK "ClapTrap " << this->_name << " can't attack, he is " RED "dead."
				  << RESET << std::endl;
	return ;
}
