
#include "../includes/Point.hpp"

int main( void )
{
	Point a(0, 0);
	Point b(0, 2);
	Point c(2, 0);
	Point point(0.5f, 1);

	if (bsp(a, b, c, point))
		std::cout << "The point (" << point.getX() << ", "
				  << point.getY() << ") is in the triangle" << std::endl;
	else
		std::cout << "The point (" << point.getX() << ", "
				  << point.getY() << ") isn't in the triangle" << std::endl;


	point = Point(-1, 1);

	if (bsp(a, b, c, point))
		std::cout << "The point (" << point.getX() << ", "
				  << point.getY() << ") is in the triangle" << std::endl;
	else
		std::cout << "The point (" << point.getX() << ", "
				  << point.getY() << ") isn't in the triangle" << std::endl;


	return 0;
}