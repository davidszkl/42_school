#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog constructor" << std::endl;
	_type = "Dog";
}

Dog::Dog(Dog const & cpy)
{
	std::cout << "Copy Dog constructor" << std::endl;
	_type = cpy.getType();
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

Dog&	Dog::operator=(Dog const & rhs)
{
	_type = rhs.getType();
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof I am a Dog which is a type of animal, I can not go Miaouw Miaouw" << std::endl;
}