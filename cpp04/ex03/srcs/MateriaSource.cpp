
#include "../includes/MateriaSource.hpp"

//Operators----------------------------------------------------------

MateriaSource & MateriaSource::operator=(MateriaSource const & right)
{
	for (int i = 0; i < 4; i++)
		this->_MateriaSrc[i] = right._MateriaSrc[i];
	return *this;
}

//Constructors/destructors-------------------------------------------

MateriaSource::MateriaSource(void){}

MateriaSource::MateriaSource(MateriaSource const & right)
{
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
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_MateriaSrc[i])
		{
			this->_MateriaSrc[i] = materia;
			return ;
		}
	}
	delete materia;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (this->_MateriaSrc[i]->getType() == type)
			return this->_MateriaSrc[i]->clone();
	return NULL;
}