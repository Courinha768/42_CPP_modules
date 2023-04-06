#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{

	public:

		Character(std::string name);
		Character(Character const & ref);
		~Character();

		std::string const&	getName() const;
		AMateria			*getMateriaFromInventory(int i);

		void equip(AMateria *m);
		void unequip(int i);
		void use(int i, ICharacter& target);

		Character & operator=(Character const & ref);

	private:

		AMateria			*inventory[4];
		std::string const	name;

};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */