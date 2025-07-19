#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <cstring>
# include <iostream>

# define print std::cout
# define endl std::endl
# define ask std::cin

class Contact
{
	public :
		Contact();
		~Contact(void);
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif