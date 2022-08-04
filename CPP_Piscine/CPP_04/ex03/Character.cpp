#include "Character.hpp"

Character::Character(): _name("unnamed"), _equipped(0)
{
	std::cout << "Default character constructor" << std::endl;
	for (int n = 0; n < 4; n++)
		_inventory[n] = nullptr;
}

Character::Character(std::string name): _name(name), _equipped(0)
{
	std::cout << "name character constructor" << std::endl;
	for (int n = 0; n < 4; n++)
		_inventory[n] = nullptr;
}

Character::Character(Character const & cpy)
{
	std::cout << "copy character constructor" << std::endl;
	*this = cpy;
}

Character& Character::operator=(Character const & rhs)
{
	std::cout << "character assignement operator" << std::endl;
	_name		= rhs.getName();
	_equipped	= 0;
	for (int n = 0; n < 4; n++)
	{
		if (_inventory[n])
			delete _inventory[n];
		_inventory[n] = rhs._inventory[n];
		if (rhs._inventory[n])
			_equipped++;
	}
	return *this;
}

Character::~Character()
{
	std::cout << "character destructor" << std::endl;
	for (int n = 0; n < _equipped; n++)
		if (_inventory[n])
			delete _inventory[n];
}

std::string const & Character::getName() const
{
	return _name;
}

int	Character::getEquip()
{
	return _equipped;
}

void	Character::equip(AMateria *materia)
{
	if (_equipped < 0 && _equipped > 3)
	{
		std::cout << _name << "'s inventory is full" << std::endl;
		return ;
	}
	_inventory[_equipped] = materia;
	_equipped++;
}

void	Character::unequip(int idx)
{
	if (idx < 0 && idx > 3)
	{
		std::cout << _name << "'s inventory slots range is [0 - 3]" << std::endl;
		return ;
	}
	else if (!_inventory[idx])
	{
		std::cout << _name << ": no materia equipped in slot " << idx << std::endl;
		return ;
	}
	int n = idx + 1;
	while (n < 4 && _inventory[n])
	{
		_inventory[n - 1] = _inventory[n];
		n++;
	}
	_inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << _name << "'s inventory slots range is [0 - 3]" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
	unequip(idx);
}