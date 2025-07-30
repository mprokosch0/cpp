#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GRAY "\033[90m"

class Fixed
{
	private:
		int _value;
		static int const _fracBits = 8;

	public:
		Fixed(void);
		Fixed(Fixed const & rhs);
		~Fixed();

	public:
		Fixed & operator=(Fixed const & rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif