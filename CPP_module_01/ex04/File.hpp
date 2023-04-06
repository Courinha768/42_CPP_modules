#ifndef TEMP_HPP
# define TEMP_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <sstream>
#include <fstream>

class File
{
	private	:
		std::string fileContent;
		std::string	s1;
		std::string	s2;
		bool		_exists;
	public	:
		File(char* _fileName, char* _s1, char* _s2);
		~File(void){}
		bool	exists(void);
		void	replace(void);
		void	writeToFile(char* _newFileName);
};

#endif