#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <sstream>
#include <ctime>

class Weapon
{
	private	:
		std::string	type;
	public	:
		Weapon(std::string _initType);
		Weapon(void){}
		~Weapon(void);
		void	setType(std::string _newType);
		const std::string&	getType(void);		
};

#endif