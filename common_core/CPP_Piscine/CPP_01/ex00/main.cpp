#include "Zombie.hpp"

int main()
{
	Zombie* Zombieptr = newZombie("newZombie");
	Zombie	StackZombie = Zombie("StackZombie");

	randomChump("randomChump");

	Zombieptr->announce();
	StackZombie.announce();

	delete Zombieptr;
	return (0);
}