#include "serializer.hpp"

int main()
{
	Data		someData;
	Data		*initial = &someData;
	uintptr_t	intermediate = 0;
	Data		*final = 0;

	std::cout << "initial:      " 	<< initial		 << std::endl;
	std::cout << "intermediate: " 	<< intermediate  << std::endl
													 << std::endl;

	intermediate = serialize(initial);

	std::cout << "initial:      " 	<< initial		 << std::endl;
	std::cout << "intermediate: " 	<< intermediate	 << std::endl
													 << std::endl;

	final = deserialize(intermediate);

	std::cout << "initial:      " 	<< initial		 << std::endl;
	std::cout << "intermediate: " 	<< intermediate	 << std::endl;
	std::cout << "final:        " 	<< final		 << std::endl
													 << std::endl;

	return 0;
}