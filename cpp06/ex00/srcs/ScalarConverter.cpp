
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

static int is_str_digits(std::string str)	
{
	for (unsigned long i = 0; i < str.length(); i++)
	{
		if (!(std::isdigit(str[i]) || str[i] == '.' || str[i] == '+' || str[i] == '-' || str[i] == 'f'))
			return 0;
	}
	return 1;
}

static int is_str_digit(std::string str)	
{
	for (unsigned long i = 0; i < str.length(); i++)
	{
		if (!(std::isdigit(str[i]) || str[i] == '+' || str[i] == '-'))
			return 0;
	}
	return 1;
}

int	is_double(std::string str)
{
	for (unsigned long i = 0; i < str.length(); i++)
	{
		if (!(std::isdigit(str[i]) || str[i] == '.' || str[i] == '+' || str[i] == '-'))
			return 0;
	}
	return 1;
}

static int counting(std::string input, int flag)
{
	int countSign = 0, countDot = 0, countF = 0;
	for (unsigned long i = 0; i < input.length(); i++)
	{
		if (input[i] == '+' || input[i] == '-')
			countSign++;
		if (flag == 1 && input[i] == '.')
			countDot++;
		if (flag == 2 && input[i] == 'f')
			countF++;
	}
	if (flag && countDot != 1)
		return 1;
	if (countSign > 1 || countSign < 0)
		return 1;
	if (countSign && input[0] != '+' && input[0] != '-')
		return 1;
	if (flag == 2 && countF != 1)
		return 1;
	return 0;
}

static int find_type(std::string input)
{
	if (input.length() == 1)
		return 0;
	if (is_str_digit(input))
	{
		if (counting(input, 0))
			return -1;
		return 1;
	}
		return 1;
	if (is_double(input))
	{
		if (counting(input, 1) || input[0] == '.'
			|| input[input.length() -1] == '.')
			return -2;
		return 2;
	}
	else if (input == "nan" || input == "+inf" || input == "-inf")
		return 4;
	if (is_str_digits(input))
	{
		if (counting(input, 2) || input[0] == '.' || input[input.length() -1] != 'f'
			|| input[input.length() - 2] == '.')
			return -3;
		return 3;
	}
	else if (input == "nanf" || input == "+inff" || input == "-inff")
		return 6;
	return -4;
}

static void print_error(int error)
{
	if (error == -1)
	{
		std::cout << RED "Error: Literal int is not formated correctly" RESET << std::endl;
		return ;
	}
	if (error == -2)
	{
		std::cout << RED "Error: Literal double is not formated correctly" RESET << std::endl;
		return ;
	}
	if (error == -3)
	{
		std::cout << RED "Error: Literal float is not formated correctly" RESET << std::endl;
		return ;
	}
}

void print_conversion(char c, int nb, float nbf, double nbd, std::string otherf, std::string other)
{
	std::cout << GREEN "char: ";
	if (other.length())
		std::cout << "impossible" << std::endl;
	else if (c % 256 >= 32 && c % 256 < 127)
		std::cout << '\'' << c << '\'' << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << YELLOW "int: ";
	if (other.length())
		std::cout << "impossible" << std::endl;
	else
		std::cout << nb << std::endl;

	std::cout << BLUE "float: ";
	if (other.length())
		std::cout << otherf << std::endl;
	else
	{
		std::cout << nbf;
		if (nbf == nb)
			std::cout << ".0";
		std::cout << 'f' << std::endl;
	}
	std::cout << PINK "double: ";
	if (other.length())
		std::cout << other << std::endl;
	else
	{
		std::cout << nbd;
		if (nbf == nb)
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void ScalarConverter::convert(std::string input)
{
	if (input.length() > 1 && !is_str_digits(input) && input != "-inff" && input != "+inff"
		&& input != "-inf" && input != "+inf" && input != "nanf" && input != "nan")
	{
		std::cout << RED "Error: imput is a string" RESET << std::endl;
		return ;
	}
	int a = find_type(input);
	if (a < 0)
		return print_error(a);
	if (a == CHAR)
	{
		int res = static_cast<int>(input[0]);
		float resf = static_cast<float>(res);
		double resd = static_cast<double>(res);
		print_conversion(input[0], res, resf, resd, "", "");
	}
	else if (a == INT)
	{
		int res = std::atoi(input.c_str());
		char c = static_cast<char>(res);
		float resf = static_cast<float>(res);
		float resd = static_cast<double>(res);
		print_conversion(c, res, resf, resd, "", "");
	}
	else if (a == DOUBLE || a == 4)
	{
		float resf = std::atof(input.c_str());
		double resd = static_cast<double>(resf);
		int res = static_cast<int>(resf);
		char c = res;
		if (a == 4)
			print_conversion(c, res, resf, resd, input + 'f', input);
		else
			print_conversion(c, res, resf, resd, "", "");
	}
	else if (a == FLOAT || a == 6)
	{
		float resf = std::atof(input.c_str());
		double resd = static_cast<double>(resf);
		int res = static_cast<int>(resf);
		char c = res;
		if (a == 6)
			print_conversion(c, res, resf, resd, input, input.erase(input.length() - 1));
		else
			print_conversion(c, res, resf, resd, "", "");
	}
	return ;
}