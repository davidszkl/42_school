#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _learned(0)
{
	std::cout << "default MateriaSource constructor" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & cpy): _learned(0)
{
	std::cout << "copy MateriaSource constructor" << std::endl;
	*this = cpy;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor" << std::endl;
	for (int n = 0; n < _learned; n++)
		if (_inventory[n])
			delete _inventory[n];
}

MateriaSource& MateriaSource::operator=(MateriaSource const & rhs)
{
	for (int n = 0; n < 4; n++)
	{
		if (rhs._inventory[n])
			_inventory[n] = rhs.getInventory(n);
		else
			_inventory[n] = nullptr;
	}
	return *this;
}

void 		MateriaSource::learnMateria(AMateria *source)
{
	if (_learned > 3)
	{
		std::cout << "MateriaSource inventory is full" << std::endl;
		return ;
	}
	_inventory[_learned] = source;
	_learned++;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int n = 0; n < 4; n++)
		if (_inventory[n]->getType() == type)
			return _inventory[n]->clone();
	return (nullptr);
}

AMateria*	MateriaSource::getInventory(int idx) const
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "wrong index" << std::endl;
		return nullptr;
	}
	return _inventory[idx];
}