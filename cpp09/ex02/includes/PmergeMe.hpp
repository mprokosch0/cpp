#ifndef PMERGEME_HPP

# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <stdlib.h>
# include <list>
# include <deque>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define GRAY "\033[90m"
# define PINK "\033[35m"

class PmergeMe
{
	private:
		PmergeMe(void);
		PmergeMe(PmergeMe const &right);
		PmergeMe &operator=(PmergeMe const &right);
		~PmergeMe(void);

	public:
		static void	sortList(std::list<int> list);
		static void	sortDeque(std::deque<int> deque);
};

template<typename Iterator, typename T>
Iterator lower_bound_step(Iterator begin, Iterator end, const T& value, int step) {
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
    return result;
}

#endif