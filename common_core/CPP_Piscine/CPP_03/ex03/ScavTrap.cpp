#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap Constructor" << std::endl;
	_HP		= 100;
	_EP		= 50;
	_ATT	= 20;
}

ScavTrap::ScavTrap(std::string name)
{
	_Name	= name;
	_HP		= 100;
	_EP		= 50;
	_ATT	= 20;
	std::cout << "Name ScavTrap Constructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& cpy)
{
	*this = cpy;
	std::cout << "Copy ScavTrap  constructor " << _Name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor " << _Name << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &rhs)
{
	_Name	= rhs.getName();
	_HP		= rhs.getHP();
	_EP		= rhs.getEP();
	_ATT	= rhs.getATT();
	return *this;
}

void ScavTrap::guardGate() const
{
	std::cout << _Name << " has entered into gatekeeper mode" << std::endl;
}