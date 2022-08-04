#ifndef C_HPP
# define C_HPP
#include "Base.hpp"

class C : public Base
{
public:

	C();
	C(C const & cpy);
	~C();

	C& operator=(C const & rhs);

private:
};

std::ostream & operator<<(std::ostream &ostr, C const & instance);

#endif