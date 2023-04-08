#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"

class Ice : public AMateria
{

	public:

		Ice();
		Ice( Ice const & src );
		~Ice();

		Ice &		operator=( Ice const & rhs );

		std::string const & getType() const;
		Ice *clone() const;
		void use(ICharacter& target);

	private:

		std::string	type;

};


#endif /* ************************************************************* ICE_H */