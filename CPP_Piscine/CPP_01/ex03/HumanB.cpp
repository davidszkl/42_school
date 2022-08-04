#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;

	std::cout << _name << " is born" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << _name << " died" << std::endl;
}

void	HumanB::attack()
{
	std::string	type = _Weapon->getType();

	std::cout << _name << " attacks with this " << type << std::endl;
}

Weapon*	HumanB::getWeapon()
{
	return _Weapon;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_Weapon = &weapon;
}