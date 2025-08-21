
#include "../includes/MateriaSource.hpp"
#include "../includes/IceMateria.hpp"
#include "../includes/CureMateria.hpp"
#include "../includes/Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	AMateria* tmp;
	me->equip(NULL);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	src->learnMateria(new IceMateria());
	src->learnMateria(new CureMateria());
	src->learnMateria(new IceMateria());
	src->learnMateria(new IceMateria());
	src->learnMateria(new IceMateria());
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	bob->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	delete me;
	delete bob;
	delete src;
	return 0;
}