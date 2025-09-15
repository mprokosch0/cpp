#include "PmergeMe.hpp"

//templates utils

template<typename Container>
void printList(Container list)
{
	typename Container::iterator it = list.begin();
	while (it != list.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	return ;
}

template<typename Iterator, typename T>
Iterator lower_bound_step(Iterator begin, Iterator end, const T& value, int step)
{
    Iterator result = end;
	Iterator it2 = begin;
	Iterator it;

	std::advance(it2, -step + 1);
    for (it = begin; it != end; std::advance(it, step))
	{
        if (*it >= value)
		{
            result = it2;
            break;
        }
		std::advance(it2, step);
    }
	if (it == end && *it >= value)
		result = it2;
	else if (it == end)
		result++;
    return result;
}

//Member fonctions

template<typename Container>
void PmergeMe::sortNbr(Container &list)
{
	mergeInsert(list, sortPairs(list, 2));
	return ;
}

template<typename Container>
void PmergeMe::parsing(Container &list, char **tab)
{
	for (int i = 1; tab[i]; i++)
	{
		std::string input(tab[i]);
		unsigned long j = 0;
		while (std::isdigit(input[j]))
			j++;
		if (!std::isdigit(input[j]) && j != input.size())
			throw PmergeMe::InvalidCharFound();
		std::string tmp = input.substr(0, j);
		long nb = std::atol(tmp.c_str());
		if (nb > 2147483647 || nb < -2147483648)
			throw PmergeMe::OverflowFound();
		typename Container::iterator it = std::find(list.begin(), list.end(), nb);
		if (it != list.end())
			throw PmergeMe::DoubleNumberFound();
		list.push_back(nb);
	}
}