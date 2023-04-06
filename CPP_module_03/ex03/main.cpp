#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	warriorA("Leonidas");
	DiamondTrap	warriorB("Alexandre, o Grande");

	warriorA.attack("Alexandre, o Grande");
	warriorB.takeDamage(warriorA.getAd());
	warriorB.whoAmI();
	warriorB.guardGate();
}