#ifndef B_HPP
# define B_HPP
#include "Base.hpp"

class B : public Base
{
public:

	B();
	B(B const & cpy);
	~B();

	B& operator=(B const & rhs);

private:
};

std::ostream & operator<<(std::ostream &ostr, B const & instance);

#endif