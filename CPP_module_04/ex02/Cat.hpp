#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{

	public:

		Cat();
		Cat(Cat const& src);
		virtual ~Cat();

		void	makeSound(void) const;

		Cat&	operator=(Cat const& rhs);

	private:

		Brain*	brain;

};

std::ostream&	operator<<(std::ostream& o, Cat const& i);

#endif