#ifndef WrongCat_HPP
# define WrongCat_HPP

# include <iostream>
# include <string>

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public:

		WrongCat();
		WrongCat(WrongCat const& src);
		virtual ~WrongCat();

		void	makeSound(void) const;

		WrongCat&	operator=(WrongCat const& rhs);

	private:

};

std::ostream&	operator<<(std::ostream& o, WrongCat const& i);

#endif