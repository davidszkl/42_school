#include "A.hpp"

A::A()
{
	std::cout << "Default A constructor" << std::endl;
}

A::~A()
{
	std::cout << "A destructor" << std::endl;
}

A::A(A const & cpy)
{
	*this = cpy;
}

A &	A::operator=( A const & rhs )
{
	(void)rhs;
	std::cout << "Assignement operator for A called" << std::endl;
	return *this;
}

std::ostream &	operator<<( std::ostream & ostr, A const & instance)
{
	(void)instance;
	ostr << "No value for A" << std::endl;
	return ostr;
}
