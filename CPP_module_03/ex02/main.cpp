#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	FragTrap	warriorA("Leonidas");
	FragTrap	warriorB("Alexandre, o Grande");

	warriorA.attack("Alexandre, o Grande");
	warriorB.takeDamage(warriorA.getAd());
	warriorB.highFivesGuys();
}