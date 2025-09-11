#ifndef BITCOINEXCHANGE_HPP

# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <fstream>
# include <stdlib.h>
# include <map>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define GRAY "\033[90m"
# define PINK "\033[35m"

class BitcoinExchange
{
	private:
		static std::map<std::string, float> _database;
	
	private:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &right);
		BitcoinExchange &operator=(BitcoinExchange const &right);
		~BitcoinExchange(void);

	public:
		static void convertFile(std::string file);
		static void loadDatabase(void);
};



# endif