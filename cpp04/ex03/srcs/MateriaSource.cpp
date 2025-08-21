
#include "../includes/MateriaSource.hpp"

//Operators----------------------------------------------------------

MateriaSource & MateriaSource::operator=(MateriaSource const & right)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_MateriaSrc[i])
			delete this->_MateriaSrc[i];
		if (!right._MateriaSrc[i])
			this->_MateriaSrc[i] = NULL;
		else
			this->_MateriaSrc[i] = right._MateriaSrc[i]->clone();
	}
	return *this;
}

//Constructors/destructors-------------------------------------------

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_MateriaSrc[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & right)
{
	for (int i = 0; i < 4; i++)
		this->_MateriaSrc[i] = NULL;
	*this = right;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_MateriaSrc[i])
			delete this->_MateriaSrc[i];
	return ;	
}

//Member functions--------------------------------------------------

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
	{
		std::cout << RED "Error: can't learn from a NULL materia" RESET
				  << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_MateriaSrc[i])
		{
			this->_MateriaSrc[i] = materia;
			std::cout << GRAY "Materia " << materia->getType()
					  << " learned at slot " << i << RESET
					  << std::endl;
			return ;
		}
	}
	std::cout << RED "Error: all learn spots are taken" RESET
				  << std::endl;
	delete materia;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (this->_MateriaSrc[i] && this->_MateriaSrc[i]->getType() == type)
			return this->_MateriaSrc[i]->clone();
	return NULL;
}