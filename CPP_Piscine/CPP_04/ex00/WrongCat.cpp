#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default WrongCat constructor" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & cpy)
{
	std::cout << "Copy WrongCat constructor" << std::endl;
	_type = cpy.getType();
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const & rhs)
{
	_type = rhs.getType();
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Meuuuuuuuuuuuu" << std::endl;
}