#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(WrongCat const & right);

	public:
		WrongCat & operator=(WrongCat const & right);
		void makeSound(void) const;
};

#endif