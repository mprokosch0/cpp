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

//SORT FOR LIST

int sortPairs(std::list<int> &list, int pair)
{
	//printList(list);
	if (pair > static_cast<int>(list.size()))
		return pair / 4;
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
	return pair / 4;
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

static std::list<int>::iterator *insertionOrder(std::list<int> &pend, int depth)
{
	int nb = pend.size() / depth;
	std::list<int>::iterator *tab = new std::list<int>::iterator[nb];
	std::list<int>::iterator *tabIt = new std::list<int>::iterator[pend.size()];
	int j1 = depth, j2 = depth, i = 0, j = 0;

	for (std::list<int>::iterator it = pend.begin(); it != pend.end(); it++)
		tabIt[i++] = it;
	tab[j++] = tabIt[depth - 1];
	while (j1 <= static_cast<int>(pend.size()))
    {
		i = j1;
		while (i > j2)
		{
			tab[j++] = tabIt[i - 1];
			i -= depth;
		}
        int next = j1 + 2 * j2;
        j2 = j1;
        j1 = next;
    }
	while (j2 < static_cast<int>(pend.size()))
	{
		j2 += depth;
		tab[j++] = tabIt[j2 - 1];
	}
	delete [] tabIt;
	return tab;
}

static std::list<int>::iterator *setRange(std::list<int> &list, std::list<int> &pend, std::list<int>::iterator *pos, int depth)
{
	int nb = pend.size() / depth;
	std::list<int>::iterator *range = new std::list<int>::iterator[nb];
	for (int i = 0; i < nb; i++)
	{
		range[i] = list.begin();
		int index = std::distance(pend.begin(), pos[i]) - depth;
		std::advance(range[i], 2 * depth + index);
	}
	return range;
}

static void binaryInsertion(std::list<int> &list, std::list<int> &pend, std::list<int>::iterator *pos, std::list<int>::iterator *range, int depth)
{
	int nb = pend.size() / depth;
	for (int i = 0; i < nb; i++)
	{
		std::list<int>::iterator it = list.begin();
		std::advance(it, depth - 1);
		it = lower_bound_step(it, range[i], *pos[i], depth);
		std::list<int>::iterator begin = pos[i];
		std::list<int>::iterator end = pos[i];
		std::advance(begin, -depth + 1);
		list.splice(it, pend, begin, ++end);
	}
}

void mergeInsert(std::list<int> &list, int depth)
{
	if (!depth)
		return ;
	std::list<int> trash, pend;	
	initiateSort(list, pend, trash, depth);
	if (pend.size())
	{
		std::list<int>::iterator *pos = insertionOrder(pend, depth);
		std::list<int>::iterator *range = setRange(list, pend, pos, depth);
		binaryInsertion(list, pend, pos, range, depth);
		delete [] pos;
		delete [] range;
	}
	list.splice(list.end(), trash, trash.begin(), trash.end());
	mergeInsert(list, depth / 2);
}


//SORT FOT VECTOR

static void replace(std::vector<int> &dst, std::vector<int> &src,
					std::vector<int>::iterator pos, std::vector<int>::iterator first,
					std::vector<int>::iterator last)
{
	std::vector<int> tmp(first, last); 
	src.erase(first, last);
	dst.insert(pos, tmp.begin(), tmp.end());
}
int sortPairs(std::vector<int> &list, int pair)
{
	if (pair > static_cast<int>(list.size()))
		return pair / 4;
	std::vector<int>::iterator at, bt;
	int i = 0, a, b;
	while (i < static_cast<int>(list.size()) || pair < static_cast<int>(list.size()))
	{
		b = i + pair / 2 - 1;
		int remaining = list.size() - i;
		a = i + ((remaining >= pair - 1) ? pair - 1 : remaining);
		if (a >= static_cast<int>(list.size()))
			return sortPairs(list, pair * 2);
		if (list[b] > list[a])
		{
			at = list.begin() + a + 1;
			bt = list.begin() + b + 1;
			replace(list, list, list.begin() + i, bt, at);
			i += pair - 1;
		}
		else
			i = a;
		i++;
	}
	return pair / 4;
}

static void initiateSort(std::vector<int> &list, std::vector<int> &pend, std::vector<int> &trash, int depth)
{
	int left = list.size() - 2 * depth;
	int i = 2 * depth, tmp;
	int j = 0, size = list.size();

	while (i < size)
	{
		tmp = i + depth;
		if (!(j % depth) && left - j < depth)
		{
			replace(trash, list, trash.end(), list.begin() + i, list.end());
			break ;
		}
		if (!((j / depth) % 2))
			replace(pend, list, pend.end(), list.begin() + i, list.begin() + tmp);
		j += depth;
		i += depth;
	}
}

static std::vector<int> &insertionOrder(std::vector<int> &pend, std::vector<int> &tab, int depth)
{
	int j1 = depth, j2 = depth, i = 0, j = 0;

	tab[j++] = depth - 1;
	while (j1 <= static_cast<int>(pend.size()))
    {
		i = j1;
		while (i > j2)
		{
			tab[j++] = i - 1;
			i -= depth;
		}
        int next = j1 + 2 * j2;
        j2 = j1;
        j1 = next;
    }
	while (j2 < static_cast<int>(pend.size()))
	{
		j2 += depth;
		tab[j++] = j2 - 1;
	}
	return tab;
}

static std::vector<int> &setRange(std::vector<int> &pend, std::vector<int> &pos, std::vector<int> &range, int depth)
{
	int nb = pend.size() / depth;
	for (int i = 0; i < nb; i++)
		range[i] = pos[i] + depth;
	return range;
}

static void binaryInsertion(std::vector<int> &list, std::vector<int> &pend, std::vector<int> &pos, std::vector<int> &range, int depth)
{
	int nb = pend.size() / depth;
	for (int i = 0; i < nb; i++)
	{
		std::vector<int>::iterator it = list.begin() + depth - 1;
		std::vector<int>::iterator end = list.begin() + range[i];
		it = lower_bound_step(it, end, pos[i], depth);
		std::vector<int>::iterator begin = pend.begin() + pos[i];
		replace(list, pend, it, begin + 1 - depth, pend.begin() + pos[i]);
		//list.splice(it, pend, begin, ++end);
	}
}

void mergeInsert(std::vector<int> &list, int depth)
{
	if (!depth)
		return ;
	std::vector<int> trash, pend;
	initiateSort(list, pend, trash, depth);
	std::cout << "depth: " << depth << std::endl;
	printList(list);
	printList(pend);
	printList(trash);
	if (pend.size())
	{
		int nb = pend.size() / depth;
		std::vector<int> pos(nb), range(nb);
		insertionOrder(pend, pos, depth);
		setRange(pend, pos, range, depth);
		printList(pos);
		printList(range);
		binaryInsertion(list, pend, pos, range, depth);
	}
	replace(list, trash, list.end(), trash.begin(), trash.end());
	mergeInsert(list, depth / 2);
}
