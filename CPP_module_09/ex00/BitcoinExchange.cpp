#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string filename)
{
	_size = 0;
	loadInput(filename);
	loadData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}


BitcoinExchange::~BitcoinExchange()
{
}


BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	if (this != &assign)
		*this = assign;
	return *this;
}


void	BitcoinExchange::loadInput(const std::string filename)
{
	std::ifstream	myFile(filename.c_str());
	std::string		s;
	std::string		secundary_s;
	data_t			data;
	bool			getLineEnded = false;

	if (!myFile)
		throw (std::exception());
	std::getline(myFile, s);
	if (s.compare("date | value"))
		throw (std::exception());
	std::getline(myFile, s);
	if (!s.compare("date | value") || s.empty())
		throw (std::exception());
	while (!s.empty() && !getLineEnded)
	{
		try
		{
			secundary_s = s.substr(0, 4);
			data.date.year = std::atoi(secundary_s.c_str());
			secundary_s = s.substr(5, 2);
			data.date.month = std::atoi(secundary_s.c_str());
			if (data.date.month < 0 || data.date.month > 11)
				throw (std::exception());
			secundary_s = s.substr(8, 2);
			data.date.day = std::atoi(secundary_s.c_str());
			if (data.date.day < 0 || data.date.day > 31)
				throw (std::exception());

			secundary_s = s.substr(13, -1);
			data.value = std::atof(secundary_s.c_str());

			data.newValue = 0;
		}
		catch(const std::exception& e)
		{
			data.newValue = -1;
		}
		data.originalString = s;
		_input.push(data);
		_size++;
		if(!std::getline(myFile, s))
			getLineEnded = true;
	}
	myFile.close();
}

void	BitcoinExchange::loadData()
{
	std::ifstream	myFile("data.csv");
	std::string		s;
	std::string		secundary_s;
	data_t			data;

	std::getline(myFile, s);
	std::getline(myFile, s);
	while (!s.empty())
	{
		secundary_s = s.substr(0, 4);
		data.date.year = std::atoi(secundary_s.c_str());
		secundary_s = s.substr(5, 2);
		data.date.month = std::atoi(secundary_s.c_str());
		secundary_s = s.substr(8, 2);
		data.date.day = std::atoi(secundary_s.c_str());

		secundary_s = s.substr(11, 100000);
		data.value = std::atof(secundary_s.c_str());

		data.newValue = 1;
		data.originalString = "";

		_data.push(data);
		std::getline(myFile, s);
	}
	myFile.close();
}

void	BitcoinExchange::findNewValue(data_t* inputData)
{
	std::queue<data_t>	tempData(_data);
	data_t				lastData;
	int		date;
	int		wantedDate;

	if (inputData->newValue == -1)
		return ;
	if (inputData->value < 0)
	{
		inputData->newValue = -2;
		return ;
	}
	else if (inputData->value > 1000)
	{
		inputData->newValue = -3;
		return ;
	}
	wantedDate = inputData->date.year * 10000 + inputData->date.month * 100 + inputData->date.day;
	lastData = tempData.front();
	while (!tempData.empty())
	{
		date = tempData.front().date.year * 10000;
		date += tempData.front().date.month * 100;
		date += tempData.front().date.day;
		if (date > wantedDate)
		{
			inputData->newValue = inputData->value * lastData.value;
			return ;
		}
		lastData = tempData.front();
		tempData.pop();
	}
	inputData->newValue = inputData->value * lastData.value;
}

data_t*	BitcoinExchange::getInput()
{
	return (&(_input.front()));
}

int	BitcoinExchange::getSize()
{
	return (_size);
}

void	BitcoinExchange::popInput()
{
	_input.pop();
}

void	BitcoinExchange::printData(const data_t data)
{
	if (data.newValue == -1)
		std::cout << "Error: bad input => " << data.originalString << std::endl;
	else if (data.newValue == -2)
		std::cout << "Error: not a positive number" << std::endl;
	else if (data.newValue == -3)
		std::cout << "Error: too large a number" << std::endl;
	else
	{
		std::cout << data.date.year << '-';
		if (data.date.month < 10)
			std::cout << '0';
		std::cout << data.date.month << '-';
		if (data.date.day < 10)
			std::cout << '0';
		std::cout << data.date.day;

		std::cout << " => " << data.value;
		std::cout << " = " << data.newValue;
		std::cout << std::endl;
	}
}