
#include "../includes/PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : oldest(0)
{
	print << "Phonebook constructor called" << endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	print << "Phonebook destructor called" << endl;
	return ;
}

static void print_add(std::string print_str, std::string *phone_string)
{
	std::string str;

	print << "What is their " << print_str << "? ";
	ask >> str;
	while (str.empty())
		ask >> str;
	*phone_string = str;
}

void PhoneBook::add_contact(void)
{
	int i = 0;
	

	while (!this->contacts[i].first_name.empty())
		i++;
	if (i == 8)
	{
		i = this->oldest;
		this->oldest = (this->oldest + 1) % NB_CONTACTS;
	}
	print_add("first name ", &this->contacts[i].first_name);
	print_add("last name ", &this->contacts[i].last_name);
	print_add("nickname ", &this->contacts[i].nickname);
	print_add("phone number ", &this->contacts[i].phone_number);
	print_add("darkest secret ", &this->contacts[i].darkest_secret);
	return ;
}

void PhoneBook::display_contact(int index) const
{
	print << endl;
	print << "\nFirst name : " << this->contacts[index].first_name << endl;
	print << "Last name : " << this->contacts[index].last_name << endl;
	print << "Nickname : " << this->contacts[index].nickname << endl;
	print << "Phone number : " << this->contacts[index].phone_number << endl;
	print << "Darkest secret : " << this->contacts[index].darkest_secret << endl;
}

static void print_col(int size, std::string phone_string)
{
	std::string str;

	if (size > 10)
	{
		str = phone_string.substr(0, 10);
		str.replace(9, 1, ".");
		print << '|' << str;
	}
	else
		print << '|' << std::setw(10) << phone_string;
}

void PhoneBook::search_contact(void) const
{
	int index = -1;
	int i;

	if (this->contacts[0].first_name.empty())
	{
		print << "The phone directory is empty !";
		return ;
	}
	print << "|     Index|First Name| Last Name|  Nickname|" << endl;
	print << "---------------------------------------------" << endl;
	for (i = 0; !this->contacts[i].first_name.empty(); i++)
	{
		print << "|" << std::setw(10) << i + 1;
		print_col(this->contacts[i].first_name.size(), this->contacts[i].first_name);
		print_col(this->contacts[i].last_name.size(), this->contacts[i].last_name);
		print_col(this->contacts[i].nickname.size(), this->contacts[i].nickname);
		print << '|' << endl;
	}
	print << "---------------------------------------------" << endl;
	while (1)
	{
		print << endl << "Please enter the contact index you want to display : ";
		ask >> index;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			print << "\nEntrée invalide. Veuillez saisir un nombre\n.";
		}
		else if (index < 1 || index > i)
			print << "\nindex not in the range, try again please\n";
		else
			break ;
	}
	display_contact(index - 1);
	return ;
}
