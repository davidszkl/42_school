#include "Animal.hpp"

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

Animal&	Animal::operator=(Animal const & rhs)
{
	_type = rhs.getType();
	return *this;
}

std::string	Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const
{
	std::cout << "What does an Animal sound like ?" << std::endl;
}