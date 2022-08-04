#include "ClapTrap.hpp"

/* CONSTRUCTORS */

ClapTrap::ClapTrap()
{
	std::cout << "Default Clap constructor " << _Name << std::endl;
	_HP		= 10;
	_EP		= 10;
	_ATT	= 0;
}

ClapTrap::ClapTrap(std::string Name)
{
	_Name	= Name;
	_HP		= 10;
	_EP		= 10;
	_ATT	= 0;
	std::cout << "Name Clap constructor " << _Name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &cpy)
{
	*this = cpy;
	std::cout << "Copy Clap constructor " << _Name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Clap destructor " << _Name << std::endl;
}

/* OVERLOADS */

ClapTrap& ClapTrap::operator=(ClapTrap const &rhs)
{
	_Name	= rhs.getName();
	_HP		= rhs.getHP();
	_EP		= rhs.getEP();
	_ATT	= rhs.getATT();
	return *this;
}

/* FUNCTIONS */

void	ClapTrap::attack(std::string const &target)
{
	std::cout << _Name << " attacks " << target << " , causing " << _ATT << " points of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << _Name << " takes " << amount << " points of damage !" << std::endl;
	_HP -= amount;
	if (_HP < 0)
	{
		std::cout << _Name << " is at Deaths's Door" << std::endl;
		_HP = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << _Name << " is being repaired for " << amount << std::endl;
	if (!_HP)
		std::cout << _Name << " is on his feet again !" << std::endl;
	_HP += amount;
}

std::string	ClapTrap::getName() const
{
	return _Name;
}

int		ClapTrap::getHP() const
{
	return _HP;
}

int		ClapTrap::getEP() const
{
	return _EP;
}

int		ClapTrap::getATT() const
{
	return _ATT;
}