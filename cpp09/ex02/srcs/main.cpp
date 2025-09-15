#include "../includes/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << RED "Error: Wrong number of argument, expected at leat 1 got 0" << std::endl;
		return 1;
	}
	std::list<int> list;
	std::vector<int> array;
	try
	{
		PmergeMe::parsing(list, av);
		PmergeMe::parsing(array, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 2;
	}

	std::cout << BLUE "List before   : " GREEN;
	printList(list);
	std::cout << BLUE "Vector before : " PINK;
	printList(array);
	std::clock_t start1 = std::clock();
	PmergeMe::sortNbr(list);
	std::clock_t end1 = std::clock();
	std::clock_t start2 = std::clock();
	PmergeMe::sortNbr(array);
	std::clock_t end2 = std::clock();
	double duration1 = double(end1 - start1) * 1000000 / CLOCKS_PER_SEC;
	double duration2 = double(end2 - start2) * 1000000 / CLOCKS_PER_SEC;
	std::cout << YELLOW "List after    : " GREEN;
	printList(list);
	std::cout << YELLOW "Vector after  : " PINK;
	printList(array);
	std::cout << RESET "Time to process the range with " BLUE "std::list: " RESET << duration1 << " usec" << std::endl;
	std::cout << "Time to process the range with " YELLOW "std::vector: " RESET << duration2 << " usec" << std::endl;
	return 0;
}