
#include "../includes/harl.hpp"

Harl::Harl(void)
{
	std::cout << GRAY "Harl constructor called" RESET << std::endl;
	return ;
}

Harl::~Harl(void)
{
	std::cout << GRAY "Harl destructor called" RESET << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string strs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (size_t i = 0; i < 4; i++)
	{
		if (strs[i] == level)
			(this->*func[i])();
	}
	return ;
}

void	Harl::debug(void)
{
	std::cout << GREEN "\n[DEBUG]\n";
	std::cout << PINK "I love having extra bacon for my 7XL-double"
			<< "-cheese-triple-pickle-special-ketchup burger. I really do!" RESET
			<< std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << BLUE "\n[INFO]\n";
	std::cout << PINK "I cannot believe adding extra bacon costs more money. "
			<< "You didn’t put enough bacon in my burger! If you did, I "
			<< "wouldn’t be asking for more!" RESET << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << YELLOW "\n[WARNING]\n";
	std::cout << PINK "I think I deserve to have some extra bacon for free. I’ve "
			<< "been coming for years, whereas you started working here just last month." RESET
			<< std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << RED "\n[ERROR]\n";
	std::cout << PINK "This is unacceptable! I want to speak to the manager now.\n" RESET
			<< std::endl;
	return ;
}
