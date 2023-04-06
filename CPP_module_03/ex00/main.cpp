#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	warriorA("Leonidas");
	ClapTrap	warriorB("Alexandre, o Grande");

	warriorA.attack("Alexandre, o Grande");
	warriorB.takeDamage(warriorA.getAd());
	warriorA.change_ad(6);
	warriorA.attack("Alexandre, o Grande");
	warriorB.takeDamage(warriorA.getAd());
	warriorA.attack("Alexandre, o Grande");
	warriorB.takeDamage(warriorA.getAd());
}