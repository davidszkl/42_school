#ifndef SWAP_HPP
# define SWAP_HPP
# include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

#endif