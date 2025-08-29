
#include "../includes/ScalarConverter.hpp"

//Operators-----------------------------------------------------------

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & right)
{
	(void)right;
	return (*this);
}

//Constructors/destructors--------------------------------------------

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const & right)
{
	*this = right;
	return ;
}

ScalarConverter::~ScalarConverter(void){}

//Member functions----------------------------------------------------

void ScalarConverter::convert(std::string input)
{
	int a = find_type(input);
	if (a < 0)
		return print_error(a);
	if (a == CHAR)
		Print_char(input);
	else if (a == INT)
		Print_int(input);
	else if (a == DOUBLE)
		Print_double(input);
	else if (a == FLOAT)
		Print_float(input);
	else if (a == SPECIALF)
		print_special(input, 0);
	else if (a == SPECIAL)
		print_special(input, 1);
	return ;
}