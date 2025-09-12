#include "../includes/PmergeMe.hpp"

int main(void)
{
	std::list<int> list;
	list.push_back(11);
	list.push_back(2);
	list.push_back(17);
	list.push_back(0);
	list.push_back(16);
	list.push_back(8);
	list.push_back(6);
	list.push_back(15);
	list.push_back(10);
	list.push_back(3);
	list.push_back(21);
	list.push_back(1);
	list.push_back(18);
	list.push_back(9);
	list.push_back(14);
	list.push_back(19);
	list.push_back(12);
	list.push_back(5);
	list.push_back(4);
	list.push_back(20);
	list.push_back(13);
	list.push_back(7);
	PmergeMe::sortList(list);
	return 0;
}