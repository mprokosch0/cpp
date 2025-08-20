
#include "../includes/MateriaSource.hpp"
#include "../includes/IceMateria.hpp"
#include "../includes/CureMateria.hpp"
#include "../includes/Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new IceMateria());
	src->learnMateria(new CureMateria());
	src->learnMateria(new IceMateria());
	src->learnMateria(new IceMateria());
	src->learnMateria(new IceMateria());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	me->equip(NULL);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	me->unequip(1);
	delete bob;
	delete me;
	delete src;
	return 0;
}