#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{

	public:

		Dog(void);
		Dog(Dog const& src);
		~Dog(void);

		void	makeSound(void) const;

		Dog&	operator=(Dog const& rhs);

	private:

		Brain*	brain;

};

std::ostream&	operator<<(std::ostream& o, Dog const& i);

#endif