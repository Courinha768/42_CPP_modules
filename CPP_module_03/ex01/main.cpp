#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	warriorA("Leonidas");
	ScavTrap	warriorB("Alexandre, o Grande");

	warriorA.attack("Alexandre, o Grande");
	warriorB.takeDamage(warriorA.getAd());
	warriorB.takeDamage(warriorA.getAd());
	warriorB.takeDamage(warriorA.getAd());
	warriorB.takeDamage(warriorA.getAd());
	warriorB.takeDamage(warriorA.getAd());
	warriorB.takeDamage(warriorA.getAd());
	warriorB.guardGate();
}