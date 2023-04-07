#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* w = new WrongCat();

	std::cout << std::endl;

	std::cout << "\e[1;37mAnimal Type : \e[0m" << meta->getType() << " " << std::endl;
	std::cout << "\e[1;37mDog Type    : \e[0m" << j->getType() << " " << std::endl;
	std::cout << "\e[1;37mCat Type    : \e[0m" << i->getType() << " " << std::endl;

	std::cout << std::endl;

	std::cout << "\e[1;37mAnimal Sound : \e[0m"; meta->makeSound();
	std::cout << "\e[1;37mDog Sound    : \e[0m";j->makeSound();
	std::cout << "\e[1;37mCat Sound    : \e[0m";i->makeSound();

	std::cout << std::endl;

	std::cout << "\e[1;37mWrongCat Type  : \e[0m" << w->getType() << " " << std::endl;
	std::cout << "\e[1;37mWrongCat Sound : \e[0m"; w->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	return 0;
}