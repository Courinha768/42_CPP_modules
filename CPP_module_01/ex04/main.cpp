#include "File.hpp"

static char*	convert_string_char(std::string	str)
{
	char*	charPTR = new char[str.length()];

	for (size_t i = 0; i < str.length(); i++)
		charPTR[i] = str[i];
	return (charPTR);
}

static char*	newFileName(char* _filename)
{
	std::string	_newFileName(_filename);
	std::string temp_newFileName(_filename);
	size_t	pos = temp_newFileName.find(".");
	size_t	last_pos = std::string::npos;

	while (pos != std::string::npos)
	{
		last_pos = pos;
		temp_newFileName.erase(pos, 1);
		temp_newFileName.insert(pos, "+");
		pos = temp_newFileName.find(".");
	}
	if (last_pos != std::string::npos)
		_newFileName.insert(last_pos, ".replace");
	else
		_newFileName += ".replace";
	return (convert_string_char(_newFileName));
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "incorrect number of arguments" << std::endl;
		return (1);
	}

	File	_file(av[1], av[2], av[3]);

	if (!_file.exists())	
		return (2);
	_file.replace();
	_file.writeToFile(newFileName(av[1]));
}