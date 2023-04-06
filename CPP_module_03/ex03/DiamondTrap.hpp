#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{

	public:

		DiamondTrap();
		DiamondTrap(std::string const _name);
		DiamondTrap(DiamondTrap const& src);
		~DiamondTrap();

		std::string	getName();

		void	attack(const std::string& target);
		void	whoAmI();

		DiamondTrap &		operator=( DiamondTrap const & rhs );

	private:

};

#endif /* ******************************************************** DiamondTrap_H */