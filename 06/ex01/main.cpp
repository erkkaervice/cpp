#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data		data;
	uintptr_t	raw;
	Data*		ptr;

	data.id = 42;

	std::cout << "Original: " << &data << std::endl;

	raw = Serializer::serialize(&data);
	ptr = Serializer::deserialize(raw);

	std::cout << "Return:   " << ptr << std::endl;

	if (ptr == &data && ptr->id == 42)
		std::cout << "Success: Pointers match and data is intact." << std::endl;
	else
		std::cout << "Error: Pointers differ." << std::endl;

	return 0;
}