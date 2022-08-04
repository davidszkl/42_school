#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "AMateria type constructor" << std::endl;
}

std::string const & AMateria::getType() const
{
	return _type;
}
