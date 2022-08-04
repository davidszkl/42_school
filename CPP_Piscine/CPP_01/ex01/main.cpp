#include "Zombie.hpp"

int main()
{
	Zombie*	Horde;
	int 	j = 5;
	 
	Horde = zombieHorde(j, "Zombie");
	if (!Horde)
		return 1;
	delete [] Horde;
	return 0;
}