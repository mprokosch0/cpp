#ifndef ARRAY_HPP

# define ARRAY_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <exception>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define GRAY "\033[90m"
# define PINK "\033[35m"

template<typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;

	public:
		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(Array<T> const & right);
		Array<T> & operator=(Array<T> const & right);
		T & operator[](unsigned int index);
		~Array<T>();

	class IndexOutOfBonds: public std::exception
	{
		public:
			const char * what() const throw();
	};

	public:
		unsigned int size(void) const;

};

#include "Array.tpp"

#endif