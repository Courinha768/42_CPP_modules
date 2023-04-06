#ifndef HARL_HPP
# define HARL_HPP

# define HARL_FUNCTIONS	&Harl::debug, &Harl::info, &Harl::warning, &Harl::error

# define DEBUG		"DEBUG"
# define INFO		"INFO"
# define WARNING	"WARNING"
# define ERROR		"ERROR"

#include <iostream>

class Harl
{
	public	:
		Harl(void);
		~Harl(void);
		void complain(std::string level);
	private	:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif