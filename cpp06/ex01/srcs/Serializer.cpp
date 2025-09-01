#include "../includes/Serializer.hpp"

//Operators-----------------------------------------------------------

Serializer & Serializer::operator=(Serializer const & right)
{
	(void)right;
	return (*this);
}

//Constructors/destructors--------------------------------------------

Serializer::Serializer(void) {}

Serializer::Serializer(Serializer const & right)
{
	*this = right;
	return ;
}

Serializer::~Serializer(void){}

//Member functions----------------------------------------------------

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}