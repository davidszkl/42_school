#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog constructor" << std::endl;
	_type 	= "Dog";
	_Brain 	= new Brain();
	_Brain->setIdeas("Dog idea, like a bone");
}

Dog::Dog(Dog const & cpy)
{
	std::cout << "Copy Dog constructor" << std::endl;
	_type = cpy.getType();
}

Dog::~Dog()
{
	delete _Brain;
	std::cout << "Dog destructor" << std::endl;
}

Dog&	Dog::operator=(Dog const & rhs)
{
	_type	= rhs.getType();
	*_Brain	= *(rhs.getBrain());
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof I am a Dog which is a type of animal, I can not go Miaouw Miaouw" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return _Brain;
}