
#include "../includes/Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	a = 5.45f;
	std::cout << a << std::endl;
	a = a / 2;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	if (a == b)
		std::cout << "a and b are equal" << std::endl;
	if (a != b)
		std::cout << "a and b aren't equal" << std::endl;
	return 0;
}
