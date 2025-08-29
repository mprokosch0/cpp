#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308
# define GREEN "\033[32m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define GRAY "\033[90m"
# define PINK "\033[35m"

enum
{
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	SPECIALF = 6,
	SPECIAL = 4
};

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & right);
		ScalarConverter & operator=(ScalarConverter const & right);
		~ScalarConverter(void);

	public:
		static void convert(std::string str);
};

void	print_error(int error);
void	print_special(std::string input, int flag);
void	Print_double(std::string input);
void	Print_float(std::string input);
void	Print_int(std::string input);
void	Print_char(std::string input);
int		find_type(std::string input);

#endif