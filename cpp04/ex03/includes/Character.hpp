#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
		AMateria *_ground[200];
		int	_index;

	public:
		Character(void);
		Character(std::string const & name);
		Character(Character const & right);
		~Character(void);

	public:
		Character & operator=(Character const & right);
		std::string const & getName() const;
		void use(int idx, ICharacter & target);
		void unequip(int idx);
		void equip(AMateria *m);
};

#endif