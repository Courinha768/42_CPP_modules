#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#define CRESET "\e[0m"

//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

#include "unistd.h"

void	my_tests()
{
	std::cout << std::endl;
	std::cout << BWHT "\tINTERFACE & RECAP" CRESET << std::endl;
	std::cout << std::endl;

	/*Default Contructers*/
	std::cout << BGRN "● Default Constructers:" CRESET << std::endl;
	std::cout << std::endl;

	IMateriaSource*	matSrc = new MateriaSource();
	AMateria*		matIce = new Ice();
	AMateria*		matCure = new Cure();
	ICharacter*		Leonidas = new Character("Leonidas");

	std::cout << std::endl;


	/*MateriaSource learnMateria()*/
	std::cout << BGRN "● MateriaSource learnMateria():" CRESET << std::endl;
	std::cout << std::endl;

	matSrc->learnMateria(matIce);
	matSrc->learnMateria(matCure);

	std::cout << std::endl;


	/*MateriaSource createMateria()*/
	std::cout << BGRN "● MateriaSource createMateria():" CRESET << std::endl;
	std::cout << std::endl;

	AMateria	*tmp1;
	AMateria	*tmp2;
	AMateria	*tmp3;
	AMateria	*tmp4;

	tmp1 = matSrc->createMateria("ice");
	tmp2 = matSrc->createMateria("cure");
	tmp3 = matSrc->createMateria("fire"); //doesn't exist
	tmp4 = matSrc->createMateria("ice");

	std::cout << std::endl;


	/*Character equip()*/
	std::cout << BGRN "● Character equip():" CRESET << std::endl;
	std::cout << std::endl;

	Leonidas->equip(tmp1);
	Leonidas->equip(tmp2);
	Leonidas->equip(tmp3);
	Leonidas->equip(tmp1);
	Leonidas->equip(tmp4);

	std::cout << std::endl;


	/* Use on a new character*/
	std::cout << BGRN "● Character use():" CRESET << std::endl;
	std::cout << std::endl;

	ICharacter* targetDummy = new Character("targetDummy");
	
	std::cout << std::endl;
	
	Leonidas->use(0, *targetDummy);
	Leonidas->use(1, *targetDummy);
	
	std::cout << std::endl;
	
	Leonidas->use(3, *targetDummy); // Use an empty / non existing slot in inventory
	Leonidas->use(-4, *targetDummy);
	Leonidas->use(18, *targetDummy);

	std::cout << std::endl;

	/*Destructers*/
	std::cout << BGRN "● Destructers:" CRESET << std::endl;
	std::cout << std::endl;

	delete matSrc;
	delete Leonidas;
	delete targetDummy;

	std::cout << std::endl;
}

int main()
{
	my_tests();
	return (0);
}
