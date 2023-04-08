#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		~MateriaSource();

		MateriaSource &		operator=( MateriaSource const & rhs );

		void 			learnMateria(AMateria *m);
		AMateria* 		createMateria(std::string const & type);
	
	private:

		AMateria	*inventory[4];

};

#endif /* *************************************************** MATERIASOURCE_H */