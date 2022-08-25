#include "Fixed.hpp"

	Fixed::Fixed()
	{
		std::cout << "Default constructor called" << std::endl;
		_RawBits = 0;
	}

	Fixed::Fixed(Fixed const & src)
	{
		std::cout << "Copy constructor called" << std::endl;
		*this = src;
	}

	Fixed::~Fixed()
	{
		std::cout << "Destructor called" << std::endl;
	}

	Fixed&	Fixed::operator=(Fixed const & rhs)
	{
		std::cout << "Assignation operator called" << std::endl;
		if (this != &rhs)
			this->_RawBits = rhs.getRawBits();
		return *this;
	}

	int Fixed::getRawBits() const
	{
		std::cout << "getRawBits member function called" << std::endl;
		return _RawBits;
	}

	void Fixed::setRawBits(int const raw)
	{
		std::cout << "setRawBits member function called" << std::endl;
		_RawBits = raw;
	}