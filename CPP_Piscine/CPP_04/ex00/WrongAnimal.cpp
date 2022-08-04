#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default WrongAnimal constructor" << std::endl;
	_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const & cpy)
{
	std::cout << "Copy WrongAnimal constructor" << std::endl;
	_type = cpy.getType();
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const & rhs)
{
	_type = rhs.getType();
	return *this;
}

std::string	WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "What does a WrongWrongAnimal sound like ?" << std::endl;
}