# include "../includes/ScalarConverter.hpp"

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
		if (flag && input[i] == '.')
			countDot++;
		if (flag == 2 && input[i] == 'f')
			countF++;
	}
	if (countSign > 1 || countSign < 0)
		return 1;
	if (countSign && input[0] != '+' && input[0] != '-')
		return 1;
	if (flag && countDot != 1)
		return 1;
	if (flag == 2 && countF != 1)
		return 1;
	return 0;
}

int find_type(std::string input)
{
	if (input.length() > 1 && !is_str_digits(input) && input != "-inff" && input != "+inff"
		&& input != "-inf" && input != "+inf" && input != "nanf" && input != "nan")
		return -4;
	if (input.length() == 1 && !std::isdigit(input[0]))
		return 0;
	if (is_str_digit(input))
	{
		if (counting(input, 0))
			return -1;
		return 1;
	}
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
