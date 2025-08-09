
#include <iostream>
#include <string>
#include <fstream>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define GRAY "\033[90m"
# define PINK "\033[35m"

void	replaceLine(std::ifstream& fIn, std::ofstream& fOut, std::string str1, std::string str2)
{
	std::string line;

	while (std::getline(fIn, line))
	{
		int	i = 0;
		while (line[i])
		{
			int pos = line.find(str1, i);
			if (pos >= 0)
			{
				line.erase(pos, str1.size());
				line.insert(pos, str2);
				i = pos + str2.size();
			}
			else
				break ;
		}
		fOut << line << std::endl;
	}
}

int	main(int ac, char **av)
{
	if (ac - 1 != 3)
	{
		std::cout << RED "Invalid number of arguments : expected 3 got " << ac - 1 << std::endl;
		std::cout << GRAY "Usage : ./sifl FileName str1 str2" RESET << std::endl;
		return (1);
	}
	std::ifstream fichierIn(av[1]);
	if (!fichierIn.is_open())
	{
		std::cout << RED "Fichier inexistant ou erreur d'ouverture" RESET << std::endl;
		return (1);
	}
	std::string fOut = std::string(av[1]) + ".replace";
	std::ofstream fichierOut(fOut.c_str());
	if (!fichierOut.is_open())
	{
		std::cout << RED "Erreur d'ouverture" RESET << std::endl;
		fichierIn.close();
		return (1);
	}
	std::string	str1 = av[2], str2 = av[3];
	replaceLine(fichierIn, fichierOut, str1, str2);
	fichierIn.close();
	fichierOut.close();
	return (0);
}
