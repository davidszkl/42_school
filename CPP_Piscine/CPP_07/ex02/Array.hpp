#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template< typename T>
class Array
{
public:

	Array<T>(): _size(0), _array(NULL) {
		std::cout << "Default Array constructor" << std::endl;
	}

	Array<T>(unsigned int n): _size(n) {
		std::cout << "Size Array constructor" << std::endl;
		if (!_size)
			throw std::underflow_error("empty array not initialized");
		_array = new T[_size];
		for (unsigned int j = 0; j < n; j++)
			_array[j] = T();
	}

	Array<T>(Array<T> const & cpy) {
		std::cout << "Copy Array constructor" << std::endl;
		*this = cpy;
	}

	~Array<T>()
	{
		std::cout << "Array destructor" << std::endl;
		if (_size > 0)
			delete [] _array;
	}
	
	Array<T>&	operator=(Array<T> const & rhs)
	{
		if (_size > 0)
			delete [] _array;
		_array = new T[rhs._size];
		_size = rhs._size;
		for (int n = 0; n < _size; n++)
			_array[n] = rhs._array[n];
		return *this;
	}

	T	&operator[](const int n)
	{
		if (n >= _size || n < 0)
			throw std::overflow_error("Index out of bounds");
		return _array[n];
	}

	int	size() const {return _size;}

private:

	int	_size;
	T	*_array;
};

#endif