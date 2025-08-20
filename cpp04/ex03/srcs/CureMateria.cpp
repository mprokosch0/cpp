
#include "../includes/CureMateria.hpp"

//Operators----------------------------------------------------------

CureMateria & CureMateria::operator=(CureMateria const & right)
{
	if (this != &right)
		this->_type = right._type;
	return *this;
}

//Constructors/destructors-------------------------------------------

CureMateria::CureMateria(void): AMateria("cure"){}

CureMateria::CureMateria(CureMateria const & right): AMateria(right){}

CureMateria::~CureMateria(void){}

//Member functions--------------------------------------------------

void	CureMateria::use(ICharacter & target)
{
	std::cout << GREEN "* heals " YELLOW << target.getName()
			  << GREEN "’s wounds *" RESET << std::endl;
}

AMateria *CureMateria::clone() const
{
	return new CureMateria(*this);
}
