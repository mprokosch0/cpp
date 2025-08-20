#ifndef CUREMATERIA_HPP
# define CUREMATERIA_HPP

#include "AMateria.hpp"

class CureMateria: public AMateria
{
	public:
		CureMateria(void);
		CureMateria(CureMateria const & right);
		CureMateria & operator=(CureMateria const & right);
		~CureMateria(void);

	public:
		void use(ICharacter & target);
		AMateria* clone() const;
};

#endif