#include "../includes/Serializer.hpp"

int main(void)
{
	Data		src = (Data){50, "Jambon"};
	Data		*vide = NULL;
	Data		*srcptr = &src;
	uintptr_t	res;

	std::cout << BLUE "TEST ON NULL PTR\n" RESET << std::endl;
	res = Serializer::serialize(vide);
	Data *dest = Serializer::deserialize(res);
	if (dest)
		std::cout << GRAY "Data content: " GREEN << dest->content 
				  << GRAY "\nData name: " PINK << dest->name << std::endl;
	else
		std::cout << RED "Data is NULL" RESET << std::endl;

	std::cout << BLUE "\nTEST ON NORMAL DATA\n" RESET << std::endl;
	res = Serializer::serialize(srcptr);
	dest = Serializer::deserialize(res);
	if (dest)
		std::cout << GRAY "Data content: " GREEN << dest->content 
				  << GRAY "\nData name: " PINK << dest->name << std::endl;
	else
		std::cout << RED "Data is NULL" RESET << std::endl;
	return 0;
}