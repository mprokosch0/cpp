#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

//Constructors/destructors--------------------------------------------

Base::~Base(void){}

//other functions

void	identify(Base* p)
{
	if (!p)
	{
		std::cout << RED "Error: Pointer on base is NULL" RESET << std::endl;
		return ;
	}
	if (dynamic_cast<A *>(p))
		std::cout << GRAY "This is a " GREEN "A" GRAY " class" RESET << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << GRAY "This is a " YELLOW "B" GRAY " class" RESET << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << GRAY "This is a " BLUE "C" GRAY " class" RESET << std::endl;
}


void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << GRAY "This is a " GREEN "A" GRAY " class" RESET << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << GRAY "This is a " YELLOW "B" GRAY " class" RESET << std::endl;
			return ;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << GRAY "This is a " BLUE "C" GRAY " class" RESET << std::endl;
				return ;
			}
			catch(const std::exception& e)
			{
				std::cout << RED "Error: Type not found" RESET << std::endl;
			}
		}
	}
}


Base	*generate(void)
{
	srand(time(NULL));
	int nb = (rand() % 3) + 1;
	switch (nb)
	{
	case 1:
		return new A;

	case 2:
		return new B;
	
	case 3:
		return new C;
	default:
		return NULL;
	}
	return NULL;
}