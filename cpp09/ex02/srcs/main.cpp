#include "../includes/PmergeMe.hpp"

int main(void)
{
	std::list<int> list;
	std::vector<int> array;
	// list.push_back(11);
	// list.push_back(2);
	// list.push_back(17);
	// list.push_back(0);
	// list.push_back(16);
	// list.push_back(8);
	// list.push_back(6);
	// list.push_back(15);
	// list.push_back(10);
	// list.push_back(3);
	// list.push_back(21);
	// list.push_back(1);
	// list.push_back(18);
	// list.push_back(9);
	// list.push_back(14);
	// list.push_back(19);
	// list.push_back(12);
	list.push_back(5);
	list.push_back(4);
	list.push_back(20);
	list.push_back(13);
	list.push_back(7);
	
	// array.push_back(11);
	// array.push_back(2);
	// array.push_back(17);
	// array.push_back(0);
	// array.push_back(16);
	// array.push_back(8);
	// array.push_back(6);
	// array.push_back(15);
	// array.push_back(10);
	// array.push_back(3);
	// array.push_back(21);
	// array.push_back(1);
	// array.push_back(18);
	// array.push_back(9);
	// array.push_back(14);
	// array.push_back(19);
	// array.push_back(12);
	array.push_back(5);
	array.push_back(4);
	array.push_back(20);
	array.push_back(13);
	array.push_back(7);
	std::cout << BLUE "-----LIST-----" RESET << std::endl << std::endl;
	PmergeMe::sortNbr(list);
	std::cout << std::endl << BLUE "-----VECTOR-----" RESET << std::endl << std::endl;
	PmergeMe::sortNbr(array);
	return 0;
}