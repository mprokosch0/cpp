#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string const _type;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & right);
		~AMateria(void);

	public:
		AMateria & operator=(AMateria const & right);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif