
# include "../includes/main.hpp"

int main( void )
{
	std::cout << BLUE "TEST ON INTS\n" RESET << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << GRAY "a = " GREEN << a << GRAY ", b = " GREEN << b << RESET << std::endl;
	std::cout << GRAY "min( a, b ) = " YELLOW << ::min(a, b) << RESET << std::endl;
	std::cout << GRAY "max( a, b ) = " YELLOW << ::max(a, b) << RESET << std::endl;

	std::cout << BLUE "\nTEST ON STRINGS\n" RESET << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << GRAY "c = " GREEN << c << GRAY ", d = " GREEN << d << RESET << std::endl;
	std::cout << GRAY "min( c, d ) = " YELLOW << ::min( c, d ) << RESET << std::endl;
	std::cout << GRAY "max( c, d ) = " YELLOW << ::max( c, d ) << RESET << std::endl;
return 0;
}