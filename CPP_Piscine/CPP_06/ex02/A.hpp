#ifndef A_HPP
# define A_HPP
# include "Base.hpp"

class A : public Base
{
public:

	A();
	A(A const & cpy);
	~A();

	A& operator=(A const & rhs);
};

std::ostream & operator<<(std::ostream &ostr, A const & instance);

#endif