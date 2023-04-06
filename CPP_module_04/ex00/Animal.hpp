#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:

		Animal(void);
		Animal(Animal const& src);
		virtual ~Animal(void);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;

		Animal&	operator=(Animal const& rhs);

	private:

	protected:
	
		std::string	type;

};

std::ostream&	operator<<(std::ostream& o, Animal const& i);

#endif