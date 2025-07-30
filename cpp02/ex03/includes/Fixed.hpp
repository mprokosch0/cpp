#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

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
		Fixed(int const nb);
		Fixed(float const nb);
		Fixed(Fixed const & rhs);
		~Fixed();

	public:
		float toFloat(void) const;
		int toInt(void) const;
		Fixed & operator=(Fixed const & rhs);
		int operator>(Fixed const & right) const;
		int operator<(Fixed const & right) const;
		int operator>=(Fixed const & right) const;
		int operator<=(Fixed const & right) const;
		int operator==(Fixed const & right) const;
		int operator!=(Fixed const & right) const;
		Fixed operator+(Fixed const & right) const;
		Fixed operator-(Fixed const & right) const;
		Fixed operator*(Fixed const & right) const;
		Fixed operator/(Fixed const & right) const;
		Fixed &operator--(void);
		Fixed &operator++(void);
		Fixed operator--(int);
		Fixed operator++(int);
		static Fixed min(Fixed &nb1, Fixed &nb2);
		static Fixed max(Fixed &nb1, Fixed &nb2);
		static Fixed const & min(Fixed const &nb1, Fixed const &nb2);
		static Fixed const & max(Fixed const &nb1, Fixed const &nb2);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &o, Fixed const &obj);

#endif