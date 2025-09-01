#include "Array.hpp"
//operators------------------------------------------

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const & right)
{
	if (this == &right)
		return *this;
	if (this->_array)
		delete this->_array;
	this->_array = new T[right._size];
	this->_size = right._size;
	for (size_t i = 0; i < this->_size; i++)
		this->_array[i] = right._array[i];
	return *this;
}

template<typename T>
T & Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw Array<T>::IndexOutOfBonds();
	return this->_array[index];
}

//Constructor/destructors----------------------------

template<typename T>
Array<T>::Array(void)
{
	this->_array = new T[0];
	this->_size = 0;
	return ;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
	this->_size = n;
	for (size_t i = 0; i < n; i++)
		this->_array[i] = 0;
	return ;
}

template<typename T>
Array<T>::Array(Array<T> const & right): _array(NULL), _size(0)
{
	*this = right;
	return ;
}

template<typename T>
Array<T>::~Array(void)
{
	delete [] this->_array;
	return ;
}

//Member function----------------------------------

template<typename T>
unsigned int Array<T>::size(void) const
{
	return this->_size;
}

template<typename T>
const char * Array<T>::IndexOutOfBonds::what() const throw()
{
	return "\033[31mError: Index is out of bonds\033[0m";
}