#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <cstdlib> 
# include <fstream>
# include <queue>

typedef	struct	date_s
{
	int	year;
	int	month;
	int	day;
}	date_t;

typedef struct	data_s
{
	date_t		date;
	float		value;
	float		newValue;
	std::string	originalString;
}	data_t;

class	BitcoinExchange
{
	public:
		BitcoinExchange(const std::string filename);
		~BitcoinExchange();

		void	printData(const data_t data);
		void	findNewValue(data_t* data);

		data_t*	getInput();
		int		getSize();
		void	popInput();
	
	private:
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange();
		BitcoinExchange & operator=(const BitcoinExchange &assign);

		void	loadInput(const std::string);
		void	loadData();

		
		std::queue<data_t>	_input;
		std::queue<data_t>	_data;
		int					_size;
};

#endif