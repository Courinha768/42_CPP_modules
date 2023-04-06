#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* animals[100];

	for (int i = 0; i < 50; i++) {
		animals[i] = new Cat();
		animals[i + 50] = new Dog();
	}

	for (int i = 0; i < 100; i++) {
		animals[i]->makeSound();
	}

	for (int i = 0; i < 100; i++) {
		delete	animals[i];
	}

	return 0;
}