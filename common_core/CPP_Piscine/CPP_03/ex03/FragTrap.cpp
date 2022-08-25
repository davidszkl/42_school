#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default FragTrap Constructor" << std::endl;
	_HP		= 100;
	_EP		= 100;
	_ATT	= 30;
}

FragTrap::FragTrap(std::string name)
{
	_Name	= name;
	_HP		= 100;
	_EP		= 100;
	_ATT	= 30;
	std::cout << "Name FragTrap Constructor" << std::endl;
}

FragTrap::FragTrap(FragTrap const& cpy)
{
	*this = cpy;
	std::cout << "Copy FragTrap  constructor " << _Name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor " << _Name << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &rhs)
{
	_Name	= rhs.getName();
	_HP		= rhs.getHP();
	_EP		= rhs.getEP();
	_ATT	= rhs.getATT();
	return *this;
}

void FragTrap::highFivesGuys() const
{
	std::cout << "Give me a high five !" << std::endl;
}