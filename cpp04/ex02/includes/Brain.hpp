#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define GRAY "\033[90m"
#define PINK "\033[35m"


class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain(void);
		Brain(Brain const & right);
		~Brain(void);
	
	public:
		Brain & operator=(Brain const & right);
		void GetIdeas();
		void SetIdea(int nb, std::string const & idea);
};

#endif