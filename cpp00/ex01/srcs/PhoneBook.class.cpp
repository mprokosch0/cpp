
#include "../includes/PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : _oldest(0)
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
	

	while (!this->_contacts[i].first_name.empty())
		i++;
	if (i == NB_CONTACTS)
	{
		i = this->_oldest;
		this->_oldest = (this->_oldest + 1) % NB_CONTACTS;
	}
	print_add("first name ", &this->_contacts[i].first_name);
	print_add("last name ", &this->_contacts[i].last_name);
	print_add("nickname ", &this->_contacts[i].nickname);
	print_add("phone number ", &this->_contacts[i].phone_number);
	print_add("darkest secret ", &this->_contacts[i].darkest_secret);
	return ;
}

void PhoneBook::_display_contact(int index) const
{
	print << endl;
	print << "\nFirst name : " << this->_contacts[index].first_name << endl;
	print << "Last name : " << this->_contacts[index].last_name << endl;
	print << "Nickname : " << this->_contacts[index].nickname << endl;
	print << "Phone number : " << this->_contacts[index].phone_number << endl;
	print << "Darkest secret : " << this->_contacts[index].darkest_secret << endl;
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

	if (this->_contacts[0].first_name.empty())
	{
		print << "The phone directory is empty !";
		return ;
	}
	print << "|     Index|First Name| Last Name|  Nickname|" << endl;
	print << "---------------------------------------------" << endl;
	for (i = 0; !this->_contacts[i].first_name.empty(); i++)
	{
		print << "|" << std::setw(10) << i + 1;
		print_col(this->_contacts[i].first_name.size(), this->_contacts[i].first_name);
		print_col(this->_contacts[i].last_name.size(), this->_contacts[i].last_name);
		print_col(this->_contacts[i].nickname.size(), this->_contacts[i].nickname);
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
			print << "\nEntrée invalide. Veuillez saisir un nombre.\n";
		}
		else if (index < 1 || index > i)
			print << "\nindex not in the range, try again please\n";
		else
			break ;
	}
	_display_contact(index - 1);
	return ;
}
