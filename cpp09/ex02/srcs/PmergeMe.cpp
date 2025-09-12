#include "../includes/PmergeMe.hpp"

//Operators-----------------------------------------------------------

PmergeMe & PmergeMe::operator=(PmergeMe const &right)
{
	(void)right;
	return *this;
}

//Constructors/destructors--------------------------------------------

PmergeMe::PmergeMe(void){}

PmergeMe::PmergeMe(PmergeMe const &right)
{
	(void)right;
	return ;
}

PmergeMe::~PmergeMe(void){}

//Member functions----------------------------------------------------

// 7, 3, 8, 2, 6, 5, 4, 1, 10, 9
// 3, 7, 2, 8, 5, 6, 1, 4, 9, 10
// 3, 7, 2, 8, 1, 4, 5, 6, 9, 10

static void sortPairs(std::list<int> &list, int pair)
{
	if (pair > static_cast<int>(list.size() / 2))
		return ;
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator b;
	std::list<int>::iterator a;
	std::list<int>::iterator tmp3;
	std::list<int>::iterator tmp4;
	std::cout << "-------" << pair << "-------" << std::endl;
	while (it != list.end() || pair < static_cast<int>(list.size() / 2))
	{
		int i = 0;
		while (it != list.end() && ++i <= pair)
		{
			if (i == pair / 2)
				b = it;
			if (i == pair)
				a = it;
			it++;
		}
		if (it == list.end() && i < pair)
		{
			sortPairs(list, pair * 2);
			return ;
		}
		std::cout << *b << ", " << *a << std::endl;
		if (*b > *a)
		{
			i = 1;
			tmp3 = b;
			while (i++ < pair / 2)
				b--;
			tmp3++;
			while (tmp3 != a)
			{
				tmp4 = tmp3;
				tmp3++;
				int nb = *tmp4;
				list.erase(tmp4);
				list.insert(b, nb);
			}
			int nb = *a;
			list.erase(a);
			list.insert(b, nb);
		}
	}
	return ;
}

static void printList(std::list<int> list)
{
	std::list<int>::iterator it = list.begin();
	while (it != list.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	return ;
}

void PmergeMe::sortList(std::list<int> list)
{
	printList(list);
	sortPairs(list, 2);
	//mergeInsert(list);
	printList(list);
	return ;
}