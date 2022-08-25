#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(Ice const& cpy): AMateria("ice")
{
	std::cout << "Ice default constructor" << std::endl;
	*this = cpy;
}

Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

Ice& Ice::operator=(Ice const & rhs)
{
	std::cout << "it's the same type, nothing changed" << std::endl;
	(void)rhs;
	return *this;
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this)); 
}

void	Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}
