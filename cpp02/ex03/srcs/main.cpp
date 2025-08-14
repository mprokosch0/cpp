
#include "../includes/Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(0, 2);
	Point c(2, 0);
	Point point(0.5f, 1);

	if (bsp(a, b, c, point))
		std::cout << GREEN "The point (" << point.getX() << ", "
				  << point.getY() << ") is in the triangle" RESET << std::endl;
	else
		std::cout << RED "The point (" << point.getX() << ", "
				  << point.getY() << ") isn't in the triangle" RESET << std::endl;


	Point point2(0, -5.0f);

	if (bsp(a, b, c, point2))
		std::cout << GREEN "The point (" << point2.getX() << ", "
				  << point2.getY() << ") is in the triangle" RESET << std::endl;
	else
		std::cout << RED "The point (" << point2.getX() << ", "
				  << point2.getY() << ") isn't in the triangle" RESET << std::endl;

	Point point3(0, 0.0f);

	if (bsp(a, b, c, point3))
		std::cout << GREEN "The point (" << point3.getX() << ", "
				  << point3.getY() << ") is in the triangle" RESET << std::endl;
	else
		std::cout << RED "The point (" << point3.getX() << ", "
				  << point3.getY() << ") isn't in the triangle" RESET << std::endl;
	return 0;
}