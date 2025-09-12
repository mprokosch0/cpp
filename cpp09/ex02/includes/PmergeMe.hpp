#ifndef PMERGEME_HPP

# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <algorithm>
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

#endif