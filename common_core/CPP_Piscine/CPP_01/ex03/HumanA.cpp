#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _Weapon(weapon)
{
	std::cout << _name << " is born" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << _name << " died" << std::endl;
}

void	HumanA::attack()
{
	std::string	type = _Weapon.getType();

	std::cout << _name << " attacks with this " << type << std::endl;
}

Weapon&	HumanA::getWeapon()
{
	return _Weapon;
}