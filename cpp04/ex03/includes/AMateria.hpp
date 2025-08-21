#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define GRAY "\033[90m"
# define PINK "\033[35m"

class	ICharacter;

class AMateria
{
	protected:
		std::string _type;
		int	_assigned;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & right);
		virtual ~AMateria(void);

	public:
		AMateria & operator=(AMateria const & right);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter & target);
		int getAssigned() const;
		void setAssigned(int nb);
};

#endif