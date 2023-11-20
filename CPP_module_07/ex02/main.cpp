#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;//
// 	return 0;
// }

int	main(void)
{
	{
		Array<int> arr(5);
		Array<int> arr_copy(3);
		arr_copy = arr;

		std::cout << "arr: ";
		for (int i = 0; i < 5; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "arr_copy: ";
		for (int i = 0; i < 5; i++) {
			std::cout << arr_copy[i] << " ";
		}
		std::cout << std::endl;
		arr[1] = 1;
		std::cout << "arr: ";
		for (int i = 0; i < 5; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "arr_copy: ";
		for (int i = 0; i < 5; i++) {
			std::cout << arr_copy[i] << " ";
		}
		std::cout << std::endl << std::endl;

		try {
			std::cout << arr[1000];
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=====================" << std::endl;
	{
		Array<int> *arr1 = new Array<int>();
		Array<int> *arr2 = new Array<int>(-1);
		Array<int> *arr3 = new Array<int>(1000);

		(void)arr1;
		(void)arr2;
		(void)arr3;

		delete arr1;
		delete arr2;
		delete arr3;
	}
	std::cout << "=====================" << std::endl;
	{
		Array<std::string> arr(5);

		arr[0] = "Hello";
		arr[1] = "World";
		std::cout << "arr: [";
		for (int i = 0; i < 5; i++) {
			std::cout << " '" << arr[i] << "' ";
		}
		std::cout << "]" << std::endl;
	}
}