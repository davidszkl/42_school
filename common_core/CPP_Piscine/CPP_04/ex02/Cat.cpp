#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor" << std::endl;
	_type	= "Cat";
	_Brain 	= new Brain();
	_Brain->setIdeas("Cat idea, like being an asshole");
}

Cat::Cat(Cat const & cpy)
{
	std::cout << "Copy Cat constructor" << std::endl;
	_type = cpy.getType();
}

Cat::~Cat()
{
	delete _Brain;
	std::cout << "Cat destructor" << std::endl;
}

Cat&	Cat::operator=(Cat const & rhs)
{
	_type	= rhs.getType();
	*_Brain	= *(rhs.getBrain());
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "miaouw miaouw I am a cat which is a type of animal, I can not go Woof Woof" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return _Brain;
}