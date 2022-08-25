#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << _name << " created\n";
}

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << _name << " created\n";
}

Zombie::~Zombie()
{
	std::cout << _name << " died" << std::endl;
}

void	Zombie::announce()
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}