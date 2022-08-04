#include "Zombie.hpp"

Zombie* zombieHorde(int nbr, std::string name)
{
	if (nbr < 1)
	{
		std::cout << "number must be greater than 0" << std::endl;
		return NULL;
	}

	Zombie*		zombieHorde = new Zombie[nbr];
	std::string	number;

	for (int n = 0; n < nbr; n++)
	{
		number = std::to_string(n);
		zombieHorde[n].setName(name + number);
		zombieHorde[n].announce();
	}
	return (zombieHorde);
}