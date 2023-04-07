#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	public:

		ScavTrap();
		ScavTrap(std::string const _name);
		ScavTrap(ScavTrap const& src);
		~ScavTrap();

		void	guardGate();
		void	attack(const std::string& target);

		std::string	getName();

		ScavTrap &		operator=( ScavTrap const & rhs );

	private:

		bool	isGuardingGate;

};

#endif /* ******************************************************** SCAVTRAP_H */