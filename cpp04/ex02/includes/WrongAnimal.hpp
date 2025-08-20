#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define GRAY "\033[90m"
# define PINK "\033[35m"

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string const & name);
		WrongAnimal(WrongAnimal const & right);
		~WrongAnimal(void);

	public:
		WrongAnimal & operator=(WrongAnimal const & right);
		void makeSound() const;
		std::string const & getType() const;
};

#endif