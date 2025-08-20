#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *_ideas;

	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const & right);

	public:
		Cat & operator=(Cat const & right);
		void makeSound(void) const;
		void GetIdeas();
		void SetIdea(int nb, std::string const & idea);
};

#endif