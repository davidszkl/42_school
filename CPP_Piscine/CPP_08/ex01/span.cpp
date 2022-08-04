#include "span.hpp"

span::span(): _size(0), _count(0) {
	std::cout << "Default Span constructor" << std::endl;
}

span::span(unsigned int N): _size(N), _count(0) {
	std::cout << "Parametrized Span constructor" << std::endl;
}

span::span(span const & cpy): _size(cpy.getSize()), _count(cpy.getCount()){
	std::cout << "copy Span constructor" << std::endl;
	*this = cpy;
}

span::~span() {
	std::cout << "Span destructor" << std::endl;
}

span& span::operator=(span const & rhs)
{
	for (unsigned int n = 0; n < _size && n < rhs._size; n++)
		_nbrs[n] = rhs.getNbr(n);
	return *this;
}

std::ostream& operator<<(std::ostream & ostream, span const & rhs)
{
	typedef std::vector<int>::const_iterator c_it;
	for (c_it it = rhs.getStored().begin(); it != rhs.getStored().end(); it++)
		ostream << *it << std::endl;
	return ostream;
}

int					span::getSize() 		const {return _size;}
int					span::getCount() 		const {return _count;}
const std::vector<int>&	span::getStored() 		const {return _nbrs;}
int					span::getNbr(int nbr)	const
{
	const unsigned int nbrr = static_cast<const unsigned int>(nbr);
	if (nbrr >= 0 && nbrr < _size)
		return _nbrs[nbrr];
	else
		throw std::domain_error("nbr out of range [0 - size]");
}

void	span::addNumber(int nbr)
{
	if (_count == _size)
		throw std::domain_error("span storage is filled");
	else
	{
		_nbrs.push_back(nbr);
		_count++;
	}
}

int	span::shortestSpan()	const
{
	if (_size < 2)
		throw std::out_of_range("less than 2 numbers stored, no span");
	const  int 	*it	 = &_nbrs[0];
	const  int 	*it2 = &_nbrs[1];
	size_t		n		= 0;
	int			rval	= std::abs(*it2 - *it);
	int			tmp		= 0;

	for (; n < _size; n++, it++)
	{
		it2 = &_nbrs[0];
		size_t	j = 0;
		for (; j < _size; j++)
		{
			tmp = std::abs(*it2 - *it); 
			if (tmp < rval && it != it2++)
				rval = tmp;
		}
	}
	return rval;
}

int	span::longestSpan()	const
{
	if (_size < 2)
		throw std::out_of_range("less than 2 numbers stored, no span");
	const  int 	*it		= &_nbrs[0];
	const  int 	*it2	= &_nbrs[1];
	size_t		n		= 0;
	int			rval	= std::abs(*it2 - *it);
	int			tmp		= 0;

	for (; n < _size; n++, it++)
	{
		it2 = &_nbrs[0];
		size_t	j = 0;
		for (; j < _size; j++)
		{
			tmp = std::abs(*it2 - *it); 
			if (tmp > rval && it != it2++)
				rval = tmp;
		}
	}
	return rval;
}