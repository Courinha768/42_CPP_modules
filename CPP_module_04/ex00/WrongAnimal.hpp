#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <iostream>
# include <string>

class WrongAnimal
{

	public:

		WrongAnimal(void);
		WrongAnimal(WrongAnimal const& src);
		virtual ~WrongAnimal(void);

		void	makeSound(void) const;
		std::string		getType(void) const;

		WrongAnimal&	operator=(WrongAnimal const& rhs);

	private:

	protected:
	
		std::string	type;

};

std::ostream&	operator<<(std::ostream& o, WrongAnimal const& i);

#endif