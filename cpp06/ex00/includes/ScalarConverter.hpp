#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define GRAY "\033[90m"
# define PINK "\033[35m"

enum
{
	CHAR,
	INT,
	DOUBLE,
	FLOAT
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


#endif