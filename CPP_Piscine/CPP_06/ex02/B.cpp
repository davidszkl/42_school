#include "B.hpp"

B::B()
{
	std::cout << "Default B constructor" << std::endl;
}

B::~B()
{
	std::cout << "B destructor" << std::endl;
}

B::B(B const & cpy)
{
	*this = cpy;
}

B &	B::operator=( B const & rhs )
{
	(void)rhs;
	std::cout << "Bssignement operator for B called" << std::endl;
	return *this;
}

std::ostream &	operator<<( std::ostream & ostr, B const & instance)
{
	(void)instance;
	ostr << "No value for B" << std::endl;
	return ostr;
}