#include "Serializer.hpp"

int	main(void)
{
	Data	data;

	data.number1 = 42;
	data.number2 = 21;

	uintptr_t data_ptr = Serializer::serialize(&data);

	std::cout << data_ptr << std::endl;

	Data*	new_data = Serializer::deserialize(data_ptr);

	std::cout << "number1 = " << new_data->number1 << std::endl;
	std::cout << "number2 = " << new_data->number2 << std::endl;
}