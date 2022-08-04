#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal	*Zoo[10];

	std::cout << "CONSTRUCTION---------------------" << std::endl;
	for (int n = 0; n < 10; n++)
	{
		if (n % 2)
			Zoo[n] = new Cat();
		else
			Zoo[n] = new Dog();
		Zoo[n]->makeSound();
	}
	std::cout << std::endl;
	std::cout << "DESTRUCTION----------------------" << std::endl;
	for (int n = 0; n < 10; n++)
		delete Zoo[n];
	std::cout << std::endl;

	std::cout << "DEEP COPY------------------------" << std::endl;
	Dog GoodBoy = Dog();
	Dog AnotherGoodBoy = Dog();

	std::cout << std::endl;

	GoodBoy.getBrain()->setIdea(0, "Original idea");
	AnotherGoodBoy.getBrain()->setIdea(0, "Cats are bad");

	std::cout << "GoodBoy: "		<< GoodBoy.getBrain()->getIdea(0)		<< std::endl;
	std::cout << "AnotherGoodBoy: "	<< AnotherGoodBoy.getBrain()->getIdea(0)<< std::endl;

	AnotherGoodBoy = GoodBoy;
	GoodBoy.getBrain()->setIdea(0, "new idea");

	std::cout << "GoodBoy: "		<< GoodBoy.getBrain()->getIdea(0)			<< std::endl;
	std::cout << "AnotherGoodBoy: "	<< AnotherGoodBoy.getBrain()->getIdea(0)	<< std::endl;

	std::cout << std::endl;
	return 0;
}
