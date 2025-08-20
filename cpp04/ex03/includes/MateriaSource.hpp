#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *_MateriaSrc[4];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & right);
		~MateriaSource(void);
	
	public:
		MateriaSource & operator=(MateriaSource const & right);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif