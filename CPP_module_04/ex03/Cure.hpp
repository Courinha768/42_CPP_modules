#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{

	public:

		Cure();
		Cure( Cure const & src );
		~Cure();

		Cure &		operator=( Cure const & rhs );

		std::string const & getType() const;
		Cure *clone() const;
		void use(ICharacter& target);

	private:

		std::string type;

};


#endif /* ************************************************************ CURE_H */