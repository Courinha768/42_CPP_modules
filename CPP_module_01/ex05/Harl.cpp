#include "Harl.hpp"

Harl::Harl(void) {
	std::cout << "A wild Harl has appeared!" << std::endl;
}

Harl::~Harl(void) {
	std::cout << "Harl has left the chat." << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*ptr_complain[4])(void) = {HARL_FUNCTIONS};
	std::string	levels[4] = {DEBUG, INFO, WARNING, ERROR};

	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*ptr_complain[i])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple";
	std::cout << "-pickle-specialketchup burger. I really do!";
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn’t put enough bacon in my burger!";
	std::cout << " If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming for years whereas you started working";
	std::cout << " here since last month.";
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}
