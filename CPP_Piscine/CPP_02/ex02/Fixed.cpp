#include "Fixed.hpp"

/* CONSTRUCTORS */

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	_RawBits = 0;
}

Fixed::Fixed(Fixed const & src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int nbr_int)
{
	//std::cout << "Int constructor called" << std::endl;
	_RawBits = nbr_int << _FractionalBits;
}

Fixed::Fixed(const float nbr_float)
{
	_RawBits = (int)roundf(nbr_float * (1 << _FractionalBits));
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

/* OPERATOR OVERLOADS */

Fixed&	Fixed::operator=(Fixed const & rhs)
{
	//std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_RawBits = rhs.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream &stream, Fixed const & fixed)
{
	stream << fixed.toFloat();
	return stream;
}

/* COMPARISONS */

bool	Fixed::operator<(Fixed const & rhs)
{
	return _RawBits < rhs.getRawBits();
}

bool	Fixed::operator>(Fixed const & rhs)
{
	return _RawBits > rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const & rhs)
{
	return _RawBits <= rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const & rhs)
{
	return _RawBits >= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const & rhs)
{
	return _RawBits == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const & rhs)
{
	return _RawBits != rhs.getRawBits();
}

/* ARITHMETIC */

Fixed	Fixed::operator+(Fixed const & rhs)
{
	return Fixed(_RawBits + rhs.getRawBits());
}

Fixed	Fixed::operator-(Fixed const & rhs)
{
	return Fixed(_RawBits - rhs.getRawBits());
}

Fixed	Fixed::operator*(Fixed const & rhs)
{
	return Fixed(toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const & rhs)
{
	return Fixed(toFloat() / rhs.toFloat());
}

/* INCREMENT */

	Fixed&	Fixed::operator++()
	{
		_RawBits += 1;
		return *this;
	}

	Fixed&	Fixed::operator--()
	{
		_RawBits -= 1;
		return *this;
	}

	Fixed	Fixed::operator++(int)
	{
		Fixed tmp(*this);
		operator ++();
		return tmp;
	}

	Fixed	Fixed::operator--(int)
	{
		Fixed tmp(*this);
		operator --();
		return tmp;
	}

/* MIN MAX */

Fixed&	Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1.getRawBits() < fixed2.getRawBits() ? fixed1 : fixed2);
}

Fixed&	Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1.getRawBits() > fixed2.getRawBits() ? fixed1 : fixed2);
}

const Fixed&	Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
	return (fixed1.getRawBits() < fixed2.getRawBits() ? fixed1 : fixed2);
}

const Fixed&	Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
	return (fixed1.getRawBits() > fixed2.getRawBits() ? fixed1 : fixed2);
}

/* FUNCTIONS */

int	Fixed::toInt() const
{
	return _RawBits >> _FractionalBits;
}

float	Fixed::toFloat() const
{
	return ((float)_RawBits / (float)(1 << _FractionalBits));
}

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return _RawBits;
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	_RawBits = raw;
}