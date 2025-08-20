
#include "AMateria.hpp"


#include "../includes/AMateria.hpp"

//Operators----------------------------------------------------------

AMateria & AMateria::operator=(AMateria const & right)
{
	return *this;
}

//Constructors/destructors-------------------------------------------

AMateria::AMateria(void){}

AMateria::AMateria(AMateria const & right)
{
	*this = right;
	return ;
}

AMateria::~AMateria(void)
{
	
	return ;	
}

//Member functions--------------------------------------------------
