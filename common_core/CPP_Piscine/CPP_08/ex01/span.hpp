#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <cstdlib>


class span 
{
public:

	span();
	span(unsigned int N);
	span(span const & cpy);
	~span();

	span& operator=(span const & rhs);

	int					getSize() 		const;
	int					getNbr(int nbr)	const;
	const std::vector<int>&	getStored() 	const;
	int					getCount()		const;

	void	addNumber(int nbr);
	int		shortestSpan()	const;
	int		longestSpan()	const;

template <class iterator>
	void	addNumber(iterator begin, iterator end)
{
	if ((end - begin) <= _size)
	{
		std::copy(begin, end, std::back_inserter(_nbrs));
		_count += (end - begin);
	}
	else
	{
		throw std::out_of_range("cant contain that");
	}
}

private:

	const unsigned int	_size;
	unsigned int		_count;
	std::vector<int>	_nbrs;
};

std::ostream& operator<<(std::ostream & ostream, span const & rhs);

#endif