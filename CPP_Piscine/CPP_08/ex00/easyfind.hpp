#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>

template<typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator	result = find(container.begin(), container.end(), value);
	return result;
}

#endif