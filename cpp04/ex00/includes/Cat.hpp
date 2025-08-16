#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const & right);

	public:
		Cat & operator=(Cat const & right);
		void makeSound(void) const;
};

#endif