
#include "../includes/IceMateria.hpp"

//Operators----------------------------------------------------------

IceMateria & IceMateria::operator=(IceMateria const & right)
{
	if (this != &right)
	{
		this->_type = right._type;
		this->_assigned = right._assigned;
	}
	return *this;
}

//Constructors/destructors-------------------------------------------

IceMateria::IceMateria(void): AMateria("ice"){}

IceMateria::IceMateria(IceMateria const & right): AMateria(right){}

IceMateria::~IceMateria(void){}

//Member functions--------------------------------------------------

void	IceMateria::use(ICharacter & target)
{
	std::cout << BLUE "* shoots an ice bolt at " YELLOW
			  << target.getName() << BLUE " *" RESET << std::endl;
}

AMateria *IceMateria::clone() const
{
	return new IceMateria(*this);
}
