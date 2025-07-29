#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

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