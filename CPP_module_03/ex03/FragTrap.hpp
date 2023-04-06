#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

	public:

		FragTrap();
		FragTrap(std::string const _name);
		FragTrap(FragTrap const& src);
		~FragTrap();

		void	highFivesGuys(void);

		std::string	getName();

		FragTrap &		operator=( FragTrap const & rhs );

	private:

};

#endif /* ******************************************************** FragTrap_H */