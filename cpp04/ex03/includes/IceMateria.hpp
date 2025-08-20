#ifndef ICEMATERIA_HPP
# define ICEMATERIA_HPP

#include "AMateria.hpp"

class IceMateria: public AMateria
{
	public:
		IceMateria(void);
		IceMateria(IceMateria const & right);
		IceMateria & operator=(IceMateria const & right);
		~IceMateria(void);

	public:
		void use(ICharacter & target);
		AMateria* clone() const;
};

#endif