#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{

	public:

		AAnimal(void);
		AAnimal(AAnimal const& src);
		virtual ~AAnimal(void);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;

		AAnimal&	operator=(AAnimal const& rhs);

	private:

	protected:
	
		std::string	type;

};

std::ostream&	operator<<(std::ostream& o, AAnimal const& i);

#endif