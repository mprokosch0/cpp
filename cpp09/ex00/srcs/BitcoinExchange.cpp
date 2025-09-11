#include "../includes/BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::_database;

//Operators-----------------------------------------------------------

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &right)
{
	(void)right;
	return *this;
}

//Constructors/destructors--------------------------------------------

BitcoinExchange::BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &right)
{
	(void)right;
	return ;
}

BitcoinExchange::~BitcoinExchange(void){}

//Member functions----------------------------------------------------

static void trim(std::string &str)
{
	str.erase(str.find_last_not_of(" \n\r\t") + 1);
	str.erase(0, str.find_first_not_of(" \n\r\t"));
}

void BitcoinExchange::loadDatabase(void)
{
	if (!_database.empty())
	{
		std::cerr << RED "Error: The database is already loaded" RESET << std::endl;
		return ;
	}
	std::ifstream fd("data.csv");
	if (!fd.is_open())
	{
		std::cerr << RED "Error: Couldn't open data.csv" RESET << std::endl;
		return ;
	}
	int i = 0;
	std::string str;
	while (std::getline(fd, str))
	{
		size_t pos = str.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << RED "Error: Line: " << i << "is wrongly formated" RESET << std::endl;
			continue ;
		}
		else if (i == 0)
			;
		else
		{
			std::string key = str.substr(0, pos - 1);
			trim(key);
			float value = std::atof(str.substr(pos + 1).c_str());
			_database.insert(std::pair<std::string, float>(key, value));
		}
		i++;
	}
	fd.close();
}

static int isDateValid(std::string str, size_t j)
{
	size_t	pos = 0;
	size_t	i = 0;

	trim(str);
	pos = str.find('-');
	if (pos == std::string::npos || pos != 4)
	{
		std::cerr << RED "Error: Line: " << j << ", Date (Year) is wrongly formated (" << str << ")" RESET << std::endl;
		return 0;
	}
	i = pos;
	pos = str.find('-', pos + 1);
	int value = atoi(str.substr(i + 1, pos - 1).c_str());
	if (value < 1 || value > 12)
	{
		std::cerr << RED "Error: Line: " << j << ", Date (Month) is wrongly formated (" << str << ")" RESET << std::endl;
		return 0;
	}
	value = atoi(str.substr(pos + 1).c_str());
	if (value < 1 || value > 31)
	{
		std::cerr << RED "Error: Line: " << j << ", Date (day) is wrongly formated (" << str << ")" RESET << std::endl;
		return 0;
	}
	return 1;
}


void BitcoinExchange::convertFile(std::string file)
{
	if (_database.empty())
	{
		std::cerr << RED "Error: The database is empty" RESET << std::endl;
		return ;
	}
	std::ifstream fd(file.c_str());
	if (!fd.is_open())
	{
		std::cerr << RED "Error: Couldn't open data.csv" RESET << std::endl;
		return ;
	}
	std::cout << std::setprecision(3);
	int i = 0;
	std::string str;
	while (std::getline(fd, str))
	{
		size_t pos = str.find('|');
		if (pos == std::string::npos)
			std::cerr << RED "Error: Line: " << i << ", is wrongly formated" RESET << std::endl;
		else if (i == 0)
			;
		else
		{
			std::string key = str.substr(0, pos);
			trim(key);
			float value = std::atof(str.substr(pos + 1).c_str());
			if (value < 0 )
				std::cerr << RED "Error: line: " << i << ", Not a positive number (" << value << ')' << RESET << std::endl;
			else if (value > 1000)
				std::cerr << RED "Error: line: " << i << ", Too large number (" << value << ')' << RESET << std::endl;
			else if (isDateValid(key, i))
			{
				std::cout << BLUE << key << GRAY " => " YELLOW << value << GRAY " = " PINK;
				std::map<std::string, float>::const_iterator it;
				it = _database.find(key);
				if (it != _database.end()) // if the key is in the database
					std::cout << it->second * value << std::endl;
				else // else we find the closest anterior date
				{
					it = _database.begin();
					while (it != _database.end())
					{
						if (key < it->first && it == _database.begin())
						{
							std::cout << it->second * value << RESET << std::endl;
							break ;
						}
						else if (key < it->first)
						{
							it--;
							std::cout << it->second * value << RESET << std::endl;
							break ;
						}
						it++;
					}
					if (it-- == _database.end()) // if our date is newer than the ones in the database, we take the last known date
						std::cout << it->second * value << RESET << std::endl;
				}
			}
		}
		i++;
	}
	fd.close();
	return ;
}