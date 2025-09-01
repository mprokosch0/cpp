#ifndef MAIN_HPP

# define MAIN_HPP

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
void swap(T &a, T  &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T & min(T & a, T & b)
{
	return a < b ? a : b;
}

template<typename T>
T & max(T & a, T & b)
{
	return a > b ? a : b;
}

#endif