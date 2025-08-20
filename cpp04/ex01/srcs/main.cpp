#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"
#include "../includes/WrongCat.hpp"

int main()
{

	Animal *animals[10];
	for (int i = 0; i < 10; i++)
	{
		if (!(i % 2))
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		if (animals[i])
			animals[i]->makeSound();
	}
	for (int i = 0; i < 10; i++)
		if (animals[i])
			delete animals[i];
	std::cout << GREEN "\n\nDEEP COPY TEST" RESET << std::endl;
	std::cout << BLUE "Constructing" RESET << std::endl;
	Dog *a = new Dog();
	if (a == NULL)
	{
		std::cout << "Allocation failed\n";
		return 1;
	}

	a->SetIdea(0, "I have to sniff it");
	a->SetIdea(1, "I have to pee on it");
	a->SetIdea(2, "I have to sniff it again");
	a->SetIdea(88, "again");
	a->SetIdea(101, "some shit");

	Dog *b = new Dog(*a);
	if (b == NULL)
	{
		std::cout << "Allocation failed\n";
		return 1;
	}
	std::cout << std::endl;

	std::cout << BLUE "Testing a" RESET << std::endl;
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	a->GetIdeas();
	std::cout << std::endl;

	std::cout << BLUE "Deconstructing a" RESET << std::endl;
	delete(a);
	std::cout << std::endl;

	std::cout << BLUE "Testing b" RESET << std::endl;
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	b->GetIdeas();
	std::cout << std::endl;

	std::cout << BLUE "Deconstructing b" RESET << std::endl;
	delete(b);

	return (0);
}
