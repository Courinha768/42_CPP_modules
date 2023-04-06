#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap(std::string const _name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap();

		ClapTrap&	operator=(ClapTrap const & rhs);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int		getHp(void);
		int		getEp(void);
		int		getAd(void);
		void	change_ad(unsigned int new_amount);

	private:

		std::string		name;
		unsigned int	hp;
		unsigned int	ep;
		unsigned int	ad;

};

#endif