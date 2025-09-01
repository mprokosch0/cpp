# include "../includes/ScalarConverter.hpp"

void Print_char(std::string input)
{
	char c = input[0];
	std::cout << GREEN "char: ";
	if (isprint(c))
		std::cout << '\'' << c << '\'' << std::endl;
	else
		std::cout << RED "Non displayable" << std::endl;
	std::cout << YELLOW "int: " << static_cast<int>(c) << std::endl;
	std::cout << BLUE "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << PINK "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void Print_int(std::string input)
{
	long nb = std::atol(input.c_str());
	std::cout << GREEN "char: ";
	if (isprint(static_cast<int>(nb) % 256))
		std::cout << '\'' << static_cast<char>(static_cast<int>(nb) % 256) << '\'' << std::endl;
	else
		std::cout << RED "Non displayable" << std::endl;
	std::cout << YELLOW "int: ";
	if (nb < MIN_INT)
		std::cout << RED "underflow" << std::endl;
	else if (nb > MAX_INT)
		std::cout << RED "overflow" << std::endl;
	else
		std::cout << static_cast<int>(nb) << std::endl;
	std::cout << BLUE "float: " << static_cast<float>(nb)
			  << (static_cast<float>(nb) < 1000000 ? ".0f" : "f") << std::endl;
	std::cout << PINK "double: " << static_cast<double>(nb)
			  << (static_cast<double>(nb) < 1000000 ? ".0" : "") << std::endl;
}

void Print_float(std::string input)
{
	float nb = std::atof(input.c_str());
	std::cout << GREEN "char: ";
	if (isprint(static_cast<int>(nb) % 256))
		std::cout << '\'' << static_cast<char>(static_cast<int>(nb) % 256) << '\'' << std::endl;
	else
		std::cout << RED "Non displayable" << std::endl;
	std::cout << YELLOW "int: ";
	if (nb < MIN_INT)
		std::cout << RED "underflow" << std::endl;
	else if (nb > MAX_INT)
		std::cout << RED "overflow" << std::endl;
	else
		std::cout << static_cast<int>(nb) << std::endl;
	std::cout << BLUE "float: ";
	if (nb < MIN_FLOAT)
		std::cout << RED "underflow" << std::endl;
	else if (nb > MAX_FLOAT)
		std::cout << RED "overflow" << std::endl;
	else
		std::cout << nb << (nb == static_cast<int>(nb) ? ".0f" : "f") << std::endl;
	double nb2 = std::atof(input.c_str());
	std::cout << PINK "double: ";
	if (nb2 < MIN_DOUBLE)
		std::cout << RED "underflow" << std::endl;
	else if (nb2 > MAX_DOUBLE)
		std::cout << RED "overflow" << std::endl;
	else
		std::cout << nb2 << ((nb2 == static_cast<int>(nb2) && nb2 < 1000000) ? ".0" : "") << std::endl;
}

void Print_double(std::string input)
{
	double nb = std::atof(input.c_str());
	std::cout << GREEN "char: ";
	if (isprint(static_cast<int>(nb) % 256))
		std::cout << '\'' << static_cast<char>(static_cast<int>(nb) % 256) << '\'' << std::endl;
	else
		std::cout << RED "Non displayable" << std::endl;
	std::cout << YELLOW "int: ";
	if (nb < MIN_INT)
		std::cout << RED "underflow" << std::endl;
	else if (nb > MAX_INT)
		std::cout << RED "overflow" << std::endl;
	else
		std::cout << static_cast<int>(nb) << std::endl;
	std::cout << BLUE "float: ";
	if (nb < MIN_FLOAT)
		std::cout << RED "underflow" << std::endl;
	else if (nb > MAX_FLOAT)
		std::cout << RED "overflow" << std::endl;
	else
		std::cout << static_cast<float>(nb) << (nb == static_cast<int>(nb) ? ".0f" : "f") << std::endl;
	std::cout << PINK "double: ";
	if (nb < MIN_DOUBLE)
		std::cout << RED "underflow" << std::endl;
	else if (nb > MAX_DOUBLE)
		std::cout << RED "overflow" << std::endl;
	else
		std::cout << nb << ((nb == static_cast<int>(nb) && nb < 1000000) ? ".0" : "") << std::endl;
}

void print_special(std::string input, int flag)
{
	std::cout << GREEN "char: " RED "impossible" << std::endl;
	std::cout << YELLOW "int: " RED "impossible" << std::endl;
	std::cout << BLUE "float: " << (flag ? input + "f" : input) << std::endl;
	std::cout << PINK "double: " << (!flag ? input.erase(input.length() - 1) : input) << std::endl;
}

void print_error(int error)
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
	if (error == -4)
	{
		std::cout << RED "Error: imput is a string" RESET << std::endl;
		return ;
	}
}
