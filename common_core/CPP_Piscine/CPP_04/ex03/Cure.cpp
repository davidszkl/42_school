#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(Cure const& cpy): AMateria("cure")
{
	std::cout << "Cure default constructor" << std::endl;
	*this = cpy;
}

Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

Cure& Cure::operator=(Cure const & rhs)
{
	std::cout << "it's the same type, nothing changed" << std::endl;
	(void)rhs;
	return *this;
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this)); 
}

void	Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
