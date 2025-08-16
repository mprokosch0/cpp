#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const & right);

	public:
		Dog & operator=(Dog const & right);
		void makeSound(void) const;
};

#endif