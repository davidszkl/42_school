#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template<typename T>
class mutantStack : public std::stack<T>
{
public:

	mutantStack<T>() {return ;}
	mutantStack<T>(const mutantStack<T> &src) {*this = src;}
	~mutantStack<T>() {return ;}

	mutantStack<T> &operator=(const mutantStack<T> &rhs) {
		(void)rhs;
		return *this;
	}

	typedef  typename std::stack<T>::container_type::iterator iterator;
	typedef  typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator		begin()				{return this->c.begin();}
	iterator		end()				{return this->c.end();}  
	const_iterator	cbegin()	const	{return this->c.begin();}
	const_iterator	cend()		const	{return this->c.end();}                                                                                       

};

#endif
