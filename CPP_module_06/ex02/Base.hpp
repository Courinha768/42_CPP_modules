#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>

class Base
{
	private:


	public:
		virtual ~Base()	{
			std::cout << "Base destructor called" << std::endl;
		}
};


#endif