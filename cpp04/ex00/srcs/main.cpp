#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	const WrongAnimal* anim1 = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << anim1->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;
	anim1->makeSound();
	wrongcat->makeSound();
	delete anim1;
	delete wrongcat;
	return 0;
}
