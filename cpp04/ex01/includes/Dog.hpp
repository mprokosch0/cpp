#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *_ideas;

	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const & right);

	public:
		Dog & operator=(Dog const & right);
		void makeSound(void) const;
		void GetIdeas();
		void SetIdea(int nb, std::string const & idea);
};

#endif