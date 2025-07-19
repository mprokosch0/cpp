#include "../includes/main.hpp"

int main()
{
	PhoneBook directory;
	std::string prompt;

	print << "\n\nWelcome to your phone directory !\n";
	while (1)
	{
		print << "\n\nPlease enter one of the following commands :\n"
			<< "ADD to add a new contact,\n"
			<< "SEARCH to browse among all contats to display their informations,\n"
			<< "EXIT to exit this menu." << endl << "> ";
		ask >> prompt;
		print << endl;
		if (prompt == "ADD")
			directory.add_contact();
		else if (prompt == "SEARCH")
			directory.search_contact();
		else if (prompt == "EXIT")
			break ;
		else
			print << "Error : unrecognise command";
	}
	return (0);
}
