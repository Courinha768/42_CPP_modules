#include "File.hpp"

File::File(char* _fileName, char* _s1, char * _s2)
{
	std::ifstream	fileStream(_fileName);
	std::string		line;

	std::string	temps1(_s1); s1 = temps1;
	std::string	temps2(_s2); s2 = temps2;
	if (fileStream.is_open())
	{
		while (std::getline(fileStream, line))
			fileContent += line + '\n';
		_exists = true;
	}
	else
	{
		std::cout << "Error reading file" << std::endl;
		_exists = false;
	}
	fileStream.close();
}

bool	File::exists(void)
{
	return (_exists);
}

void	File::replace(void)
{
	size_t	pos = fileContent.find(s1);

	while (pos != std::string::npos)
	{
		fileContent.erase(pos, s1.length());
		fileContent.insert(pos, s2);
		pos = fileContent.find(s1);
	}
}

void	File::writeToFile(char* _newFileName)
{
	std::ofstream	fileStream(_newFileName);

	fileStream << fileContent;
	fileStream.close();
}