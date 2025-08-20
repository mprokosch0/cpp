
#include "../includes/AMateria.hpp"

//Operators----------------------------------------------------------

AMateria & AMateria::operator=(AMateria const & right)
{
	if (this != &right)
		this->_type = right._type;
	return *this;
}

//Constructors/destructors-------------------------------------------

AMateria::AMateria(void){}

AMateria::AMateria(std::string const & type): _type(type){}

AMateria::AMateria(AMateria const & right): _type(right._type){}

AMateria::~AMateria(void){}

//Member functions--------------------------------------------------

std::string const & AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter & target)
{
	std::cout << "Use of materia (no type) on "
			  << target.getName() << std::endl;
}
