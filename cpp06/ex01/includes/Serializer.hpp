#ifndef SERIALIZER_HPP

# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define GRAY "\033[90m"
# define PINK "\033[35m"

typedef struct s_Serializer
{
	int			content;
	std::string	name;
}	Data;


class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const & right);
		Serializer & operator=(Serializer const & right);
		~Serializer(void);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};





#endif