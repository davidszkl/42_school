#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor" << std::endl;
	_type = "Cat";
}

Cat::Cat(Cat const & cpy)
{
	std::cout << "Copy Cat constructor" << std::endl;
	_type = cpy.getType();
}

Cat::~Cat()
{
	
	std::cout << "Cat destructor" << std::endl;
}

Cat&	Cat::operator=(Cat const & rhs)
{
	_type = rhs.getType();
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "miaouw miaouw I am a cat which is a type of animal, I can not go Woof Woof" << std::endl;
}