#include "C.hpp"

C::C()
{
	std::cout << "Default C constructor" << std::endl;
}

C::~C()
{
	std::cout << "C destructor" << std::endl;
}

C::C(C const & cpy)
{
	*this = cpy;
}

C &	C::operator=( C const & rhs )
{
	(void)rhs;
	std::cout << "Cssignement operator for C called" << std::endl;
	return *this;
}

std::ostream &	operator<<( std::ostream & ostr, C const & instance)
{
	(void)instance;
	ostr << "No value for C" << std::endl;
	return ostr;
}