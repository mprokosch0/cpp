#ifndef PMERGEME_HPP

# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <exception>
# include <algorithm>
# include <stdlib.h>
# include <list>
# include <ctime>
# include <vector>

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
		template<typename Container>
		static void	sortNbr(Container &list);
		template<typename Container>
		static void parsing(Container &list, char **input);

	class OverflowFound: public std::exception
	{
		const char *what() const throw();
	};

	class InvalidCharFound: public std::exception
	{
		const char *what() const throw();
	};

	class DoubleNumberFound: public std::exception
	{
		const char *what() const throw();
	};
};

int		sortPairs(std::list<int> &list, int pair);
void	mergeInsert(std::list<int> &list, int depth);

int		sortPairs(std::vector<int> &list, int pair);
void	mergeInsert(std::vector<int> &list, int depth);

# include "PmergeMe.tpp"

#endif