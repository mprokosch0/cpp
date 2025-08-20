
#include "../includes/Character.hpp"

//Operators----------------------------------------------------------

Character & Character::operator=(Character const & right)
{
	if (this == &right)
		return *this;

	this->_name = right._name;
	this->_index = right._index;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (right._inventory[i] == NULL)
			this->_inventory[i] = NULL;
		else
			this->_inventory[i] = right._inventory[i]->clone();
	}

	for (int i = 0; i < 200; i++)
	{
		if (this->_ground[i])
			delete this->_ground[i];
		if (right._ground[i] == NULL)
			this->_ground[i] = NULL;
		else
			this->_ground[i] = right._ground[i]->clone();
	}
	
	return *this;
}

//Constructors/destructors-------------------------------------------

Character::Character(void): _name("default")
{
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 200; i++)
		this->_ground[i] = NULL;
	return ;	
}

Character::Character(std::string const & type): _name(type)
{
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 200; i++)
		this->_ground[i] = NULL;
	return ;
}

Character::Character(Character const & right)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 200; i++)
		this->_ground[i] = NULL;
	*this = right;
	return ;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
	for (int i = 0; i < 200; i++)
		if (this->_ground[i])
			delete this->_ground[i];
	return ;	
}

//Member functions--------------------------------------------------

std::string const & Character::getName(void) const
{
	return this->_name;
}

void	Character::use(int idx, ICharacter & target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << RED "Error: couldn't use materia, index not in range" RESET
				  << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << RED "Error: the inventory slot is empty" RESET
				  << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
	return ;
}

void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << RED "Error: couldn't equip materia because NULL pointer" RESET
				  << std::endl;
		return ;
	}
	int idx;
	for (idx = 0; idx < 4; idx++)
	{
		if (!this->_inventory[idx])
			break ;
	}
	if (idx > 4)
	{
		std::cout << RED "Error: couldn't equip materia because no inventory slots available" RESET
				  << std::endl;
		return ;
	}
	this->_inventory[idx] = m;
	std::cout << GRAY "Materia " << m->getType()
			  << " equiped at inventory slot " << idx << RESET
			  << std::endl;
	return ;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << RED "Error: couldn't unequip materia, index not in range" RESET
				  << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << RED "Error: couldn't unequip materia, the inventory slot is empty" RESET
				  << std::endl;
		return ;
	}
	std::cout << GRAY "Materia " << this->_inventory[idx]->getType()
			  << " in inventory slot " << idx << " is unequipped" RESET
			  << std::endl;
	if (_index == 200)
		_index = 0;
	if (!this->_ground[_index])
		this->_ground[_index] = this->_inventory[idx];
	else
	{
		delete this->_ground[_index];
		this->_ground[_index] = this->_inventory[idx];
	}
	_index++;
	this->_inventory[idx] = NULL;
	return ;
}
