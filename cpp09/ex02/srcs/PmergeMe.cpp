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

static int sortPairs(std::list<int> &list, int pair)
{
	//printList(list);
	if (pair > static_cast<int>(list.size()))
		return pair / 8;
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator a, b, tmp;
	//std::cout << "-------" << pair << "-------" << std::endl;
	while (it != list.end() || pair < static_cast<int>(list.size()))
	{
		a = b = it;
		std::advance(b, pair / 2 - 1);
		int remaining = 0;
		for (std::list<int>::iterator tmp = it; tmp != list.end(); ++tmp)
			remaining++;
		std::advance(a, (remaining >= pair - 1) ? pair - 1 : remaining);
		if (a == list.end())
			return sortPairs(list, pair * 2);
		//std::cout << *b << ", " << *a << std::endl;
		if (*b > *a)
		{
			tmp = b;
			list.splice(it, list, ++tmp, ++a);
			it = b;
		}
		else
			it = a;
		it++;
	}
	return pair;
}

static void initiateSort(std::list<int> &list, std::list<int> &pend, std::list<int> &trash, int depth)
{
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator tmp;
	int left = list.size() - 2 * depth;
	int i = 0;

	std::advance(it, 2 * depth);
	while (it != list.end())
	{
		tmp = it;
		std::advance(tmp, depth);
		if (!(i % depth) && left - i < depth)
		{
			trash.splice(trash.end(), list, it, list.end());
			break ;
		}
		std::list<int>::iterator nextIt = tmp;
		if (!((i / depth) % 2))
			pend.splice(pend.end(), list, it, tmp);
		it = nextIt;
		i += depth;
	}
}

static void mergeInsert(std::list<int> list, int depth)
{
	if (!depth)
		return ;
	std::list<int> trash, pend;
	initiateSort(list, pend, trash, depth);
	printList(list);
	printList(pend);
	printList(trash);
	// while (pend.size() != 0)
	// {
		
	// }
	
}

void PmergeMe::sortList(std::list<int> list)
{
	int depth = sortPairs(list, 2);
	mergeInsert(list, depth);
	return ;
}