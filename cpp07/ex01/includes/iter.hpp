#ifndef ITER_HPP

# define ITER_HPP

# include <iostream>
# include <string>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define GRAY "\033[90m"
# define PINK "\033[35m"

template<typename T>
void iter(T const *addr, int const size, void (*f)(T const &))
{
	for (int i = 0; i < size; i++)
		(*f)(addr[i]);
}

#endif