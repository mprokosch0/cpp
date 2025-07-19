
#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "main.hpp"
# include "Contact.class.hpp"

class PhoneBook
{
	private :
		Contact	contacts[NB_CONTACTS + 1];
		short oldest;
		void	display_contact(int index) const;
	public :
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact(void);
		void	search_contact(void) const;
};

#endif