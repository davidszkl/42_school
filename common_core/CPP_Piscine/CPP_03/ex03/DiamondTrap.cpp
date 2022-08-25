#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "Default Diamond constructor " << _Name << std::endl;
	_Name			= "Default";
	ClapTrap::_Name = _Name + "clap_name";
	_HP 			= 100;
	_EP				= 50;
	_ATT			= 30;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "Name Diamond constructor " << _Name << std::endl;
	ClapTrap::_Name = name + "_clap_name";
	_Name			= name;
	_HP 			= 100;
	_EP				= 50;
	_ATT			= 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const &cpy)
{
	std::cout << "Copy Diamond constructor " << _Name << std::endl;
	*this = cpy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond destructor " << _Name << std::endl;
}
	
DiamondTrap& DiamondTrap::operator=(DiamondTrap const &rhs)
{
	ClapTrap::_Name	= rhs.getName();
	_HP		= rhs.getHP();
	_EP		= rhs.getEP();
	_ATT	= rhs.getATT();
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "my name is " << _Name << std::endl;
	std::cout << "my ClapTrap name is " << ClapTrap::_Name << std::endl;
}
