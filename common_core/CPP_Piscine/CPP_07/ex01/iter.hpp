#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template<typename T>
void	iter(T a[], int size, void (*fnct)(const T &))
{
	for (int i = 0; i < size; i++)
		fnct(a[i]);	
}

#endif