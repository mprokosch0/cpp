
#include "../includes/harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl constructor called" << std::endl;
	return ;
}

Harl::~Harl(void)
{
	std::cout << "Harl destructor called" << std::endl;
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
	std::cout << "I love having extra bacon for my 7XL-double"
			<< "-cheese-triple-pickle-special-ketchup burger. I really do!"
			<< std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
			<< "You didn’t put enough bacon in my burger! If you did, I"
			<< "wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve "
			<< "been coming for years, whereas you started working here just last month."
			<< std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
			<< std::endl;
	return ;
}
