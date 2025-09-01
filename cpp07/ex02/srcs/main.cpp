#include <iostream>
#include "../includes/Array.hpp"

int main(int, char**)
{
	Array<int> numbers(10);
	srand(time(NULL));
	std::cout << BLUE "------ARRAY OF INT TEST------\n" RESET << std::endl;
	std::cout << BLUE "INITIAL ARRAY\n" RESET << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		numbers[i] = rand() % 255;
		std::cout << GRAY "Index: " YELLOW << i << GRAY ", value: " GREEN
				  << numbers[i] << RESET << std::endl;
	}
	try
	{
		numbers[-1];
	}
	catch(const std::exception& e)
	{
		std::cerr << '\n' << e.what() << "\n\n";
	}
	try
	{
		numbers[numbers.size()];
	}
	catch(const std::exception& e)
	{
		std::cerr << '\n' << e.what() << "\n\n";
	}
	{
		Array<int> dup = numbers;
		dup[3] = 6;
		Array<int> dup2(dup);
		std::cout << BLUE "DUPLICATE ARRAY\n" RESET << std::endl;
		for (size_t i = 0; i < dup2.size(); i++)
		{
			std::cout << GRAY "Index: " YELLOW << i << GRAY ", value: " GREEN
					  << dup2[i] << RESET << std::endl;
		}
		std::cout << BLUE "\nINITIAL ARRAY\n" RESET << std::endl;
		for (size_t i = 0; i < numbers.size(); i++)
		{
			std::cout << GRAY "Index: " YELLOW << i << GRAY ", value: " GREEN
					  << numbers[i] << RESET << std::endl;
		}
	}
	std::cout << BLUE "\n\n------ARRAY OF CHAR TEST------\n" RESET << std::endl;
	Array<char> text(10);
	std::cout << BLUE "INITIAL ARRAY\n" RESET << std::endl;
	for (size_t i = 0; i < text.size(); i++)
	{
		text[i] = (rand() % 94) + 32;
		std::cout << GRAY "Index: " YELLOW << i << GRAY ", value: " GREEN
				  << text[i] << RESET << std::endl;
	}
	{
		Array<char> dupT = text;
		dupT[0] = 65;
		Array<char> dupT2(dupT);
		std::cout << BLUE "\nDUPLICATE ARRAY\n" RESET << std::endl;
		for (size_t i = 0; i < dupT2.size(); i++)
		{
			std::cout << GRAY "Index: " YELLOW << i << GRAY ", value: " GREEN
					  << dupT2[i] << RESET << std::endl;
		}
		std::cout << BLUE "\nINITIAL ARRAY\n" RESET << std::endl;
		for (size_t i = 0; i < text.size(); i++)
		{
			std::cout << GRAY "Index: " YELLOW << i << GRAY ", value: " GREEN
					  << text[i] << RESET << std::endl;
		}
	}
	return 0;
}