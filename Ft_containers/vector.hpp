/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 09:49:07 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/29 09:49:11 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include <memory>
#include "utils/RandIter.hpp"
#include "utils/ReverseRandIter.hpp"
#include "utils/utils.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:

		typedef T							value_type;
		typedef Alloc						allocator_type;
		typedef T&							reference;
		typedef const T&					const_reference;
		typedef T*							pointer;
		typedef const T*					const_pointer;
		typedef RandIter<T>					iterator;
		typedef RandIter<const T>			const_iterator;
		typedef ReverseRandIter<T>			reverse_iterator;
		typedef ReverseRandIter<const T>	const_reverse_iterator;
		typedef std::ptrdiff_t				difference_type;
		typedef size_t						size_type;
	
	protected:

		pointer				_arr;
		allocator_type		_alloc;
		size_type			_size;
		size_type			_cap;

		void	realloc(size_type n) {
			size_type tmp_cap = _cap;
			while (tmp_cap < n)
				tmp_cap *= 2;
			pointer buff = _alloc.allocate(tmp_cap);
			pointer ptr1 = _arr;
			for (size_type j = 0; j < _size; j++, ptr1++, buff++)
			{
				_alloc.construct(buff, *ptr1);
				_alloc.destroy(ptr1);				
			}
			_alloc.deallocate(_arr, _cap);
			_cap = tmp_cap;
			_arr = (buff - _size);
		}

		// void	realloc_from(size_type n, size_type from) {
		// 	size_type tmp_cap = _cap;
		// 	while (tmp_cap < n)
		// 		tmp_cap *= 2;
		// 	pointer buff = _alloc.allocate(tmp_cap);
		// 	pointer ptr1 = &_arr[from];
		// 	pointer ptr2 = &buff[0];
		// 	for (size_type n = 0; n < _size; n++, ptr1++, ptr2++)
		// 	{
		// 		_alloc.construct(ptr2, *ptr1);
		// 		_alloc.destroy(ptr1);
		// 	}
		// 	_alloc.deallocate(_arr, _cap);
		// 	_cap = tmp_cap;
		// 	_arr = buff;
		// }
	
	public:

	//-----------------------------------------<< Constructors >>-----------------------------------------------

		explicit vector(const allocator_type &alloc = allocator_type()): _alloc(alloc), _size(0), _cap(256) {
			_arr = _alloc.allocate(256, 0);
		}

		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type()): _alloc(alloc), _size(n), _cap(1) {
			if (!n)
			{
				_arr = _alloc.allocate(1);
				_arr[0] = 0;
			}
			else
			{
				while (_cap < n)
					_cap *= 2;
				_arr = _alloc.allocate(_cap);
				pointer	tmp = &_arr[0];
				for (size_type j = 0; j < _size; j++, tmp++)
					_alloc.construct(tmp, val);
			}
		}

	template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type*  = nullptr):
			_alloc(alloc),
			_size(0),
			_cap(1)
		{
			if (first > last)
			{
				std::cout << "mismatched iterators" << std::endl;
				return ;
			}
			InputIterator tmp = first;
			while (tmp != last)
			{
				++tmp;
				++_size;
			}
			while (_cap < _size)
				_cap *= 2;
			_arr = _alloc.allocate(_cap);
			pointer ptr = &_arr[0];
			tmp = first;
			for (size_type n = 0; n < _size; n++, ptr++, tmp++)
				_alloc.construct(ptr, *tmp);
		}

		vector (const vector &x) {
			const_iterator	tmp = x.begin();
			_alloc = x._alloc;
			_arr = _alloc.allocate(x._cap);
			pointer	it = &_arr[0];
			for (size_type n = 0; n < x._size; n++, it++, tmp++)
				_alloc.construct(it, *tmp);
			_size = x._size;
			_cap = x._cap;
		}

		~vector() {
			pointer		ptr = &_arr[0];
			for (; _size > 0; _size--, ptr++)
				_alloc.destroy(ptr);
			_alloc.deallocate(_arr, _cap);
		}

		vector& operator=(const vector& x) {
			if (_size < x._size)
				realloc(x._size);
			pointer tmp = &_arr[0];
			const_pointer tmp3 = &x._arr[0];
			const_iterator tmp4 = x.end();
			for (size_type n = 0; n < _size; n++, tmp++)
				_alloc.destroy(tmp);
			tmp = &_arr[0];
			tmp3 = &_arr[0];
			for (size_type n = 0; n < x._size ; n++, tmp++, tmp3++)
				_alloc.construct(tmp, *tmp3);
			_size = x._size;
			_cap = x._cap;
			return *this;
		}		

	//-----------------------------------------<< Iterators >>-------------------------------------------------

		iterator 				begin()	 {return iterator(&_arr[0]);}
		iterator				end()	 {return iterator(&_arr[_size]);}
		reverse_iterator		rbegin() {return reverse_iterator(&_arr[_size - 1]);}
		reverse_iterator		rend()	 {return reverse_iterator(&_arr[-1]);}
		const_iterator 			begin()	 const {return const_iterator(&_arr[0]);}
		const_iterator 			end()	 const {return const_iterator(&_arr[_size]);}
		const_reverse_iterator	rbegin() const {return reverse_const_iterator(&_arr[_size - 1]);}
		const_reverse_iterator	rend()	 const {return reverse_const_iterator(&_arr[-1]);}

	//-----------------------------------------<< Capacity >>--------------------------------------------------

		size_type	size()		const {return _size;}
		size_type	max_size()	const {return _alloc.max_size();}
		size_type	capacity()	const {return _cap;}
		bool		empty()		const {return !_size;}

		void	resize(size_type n, value_type val = value_type()) {
			pointer		ptr = &_arr[_size - 1];
			if (n < _size)
				while (_size-- > n + 1)
					_alloc.destroy(ptr--);
			else
			{
				if (n > _cap)
					realloc(n);
				ptr = &_arr[_size];
				size_type j = 0;
				for (; j < (n - _size); j++)
					_alloc.construct(ptr++, val);
				_size += j;
			}
		}

		void	reserve(size_type n) {
			if (n > _cap)
				realloc(n);
		}

	//--------------------------------------<< Element access >>-----------------------------------------------

		reference		operator[](size_type n) {return _arr[n];}
		reference		front() {return _arr[0];}
		reference		back() {return _arr[_size - 1];}
		reference		at(size_type n) {
			if (n >= _size)
				throw std::out_of_range("vector");
			return _arr[n];
		}

		const_reference operator[](size_type n) const {return _arr[n];}
		const_reference	front() const {return _arr[0];}
		const_reference	back()  const {return _arr[_size - 1];}
		const_reference	at(size_type n) const {
			if (n >= _size)
				throw std::out_of_range("vector");
			return _arr[n];
		}

	//-----------------------------------------<< Modifiers >>-------------------------------------------------

	template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type*  = nullptr) {
			if (first >  last)
			{
				std::cout <<  "mismatched iterators\n";
				return ;
			}
			size_type n = last - first;
			if (n > _cap)
				realloc(n);
			pointer ptr = &_arr[0];
			size_type j = 0;

			if (_size < n)
			{
				while (j < n)
				{
					if (j++ < _size)
						_alloc.destroy(ptr);
					_alloc.construct(ptr++, *first++);
				}
				_size = n;
			}
			else
			{
				while (j < _size)
				{
					_alloc.destroy(ptr);
					if (j++ < n)
						_alloc.construct(ptr++, *first++);
				}
				_size = n;
			}
		}


		void assign (size_type n, const value_type& val) {
			if (n > _cap)
				realloc(n);
			pointer ptr = &_arr[0];
			size_type j = 0;

			if (_size < n)
			{
				while (j < n)
				{
					if (j++ < _size)
						_alloc.destroy(ptr);
					_alloc.construct(ptr++, val);
				}
				_size = n;
			}
			else
			{
				while (j < _size)
				{
					_alloc.destroy(ptr);
					if (j++ < n)
						_alloc.construct(ptr++, val);
				}
				_size = n;
			}
		}

		void	push_back(const value_type& val) {
			if (_size++ == _cap)
				realloc(_cap + 1);
			pointer ptr = &_arr[_size - 1];
			_alloc.construct(ptr, val);
		}

		void	pop_back() {
			pointer ptr = &_arr[--_size];
			_alloc.destroy(ptr);
		}

	iterator insert(iterator position, const value_type& val) {
			if (_size >= _cap)
				realloc(_cap + 1);
			pointer ptr = &_arr[_size];
			size_type count = end() - position;
			_size++;
			for (; count > 0; count--, ptr--)
				*ptr = *(ptr - 1);
			*ptr = val;
			return position;
		}

		void insert (iterator position, size_type n, const value_type& val) {
			if ((_size + n) >= _cap)
				realloc(_cap + n);
			pointer ptr = &_arr[_size + n - 1];
			size_type count = end() - position;
			_size += n;
			for (; count > 0; count--, ptr--)
				*ptr = *(ptr - n);
			while (n--)
				*(ptr--) = val;
		}

	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type*  = nullptr) {
			if (first >  last)
			{
				std::cout <<  "mis-matched iterators\n";
				return ;
			}
			size_type n = (last - first);
			if ((_size + n) >= _cap)
				realloc(_cap + n);
			pointer ptr = &_arr[_size + n - 1];
			size_type count = end() - position;
			_size += n;
			for (; count > 0; count--, ptr--)
				*ptr = *(ptr - n);
			while (n--)
				*(ptr--) = *(--last);
		}

		iterator erase(iterator position) {
			size_type	pos = position - begin();
			pointer		ptr = &_arr[pos];

			_alloc.destroy(ptr);
			_size--;
			while (pos++ < _size)
			{
				*ptr = *(ptr + 1);
				ptr++;
			}
			return position;
		}

		iterator erase(iterator first, iterator last) {
			size_type	n	 = first - begin();
			pointer 	ptr  = &_arr[n];
			size_type	diff = last - first;

			for (size_type j = 0; n + diff < _size ; j++, n++, ptr++)
			{
				if (j < diff)
					_alloc.destroy(ptr);
				if (n + diff < _size)
					*ptr = *(ptr + diff);
			}			
			_size -= diff;
			return first;
		}

		void	swap(vector &x) {
			pointer 		swap1 = _arr;
			allocator_type	swap2 = _alloc;
			size_type		swap3 = _size;
			size_type		swap4 = _cap;

			_arr	= x._arr;
			_alloc 	= x._alloc;
			_size	= x._size;
			_cap	= x._cap;

			x._arr	 = swap1;
			x._alloc = swap2;
			x._size	 = swap3;
			x._cap	 = swap4;
		}

		void clear() {
			pointer ptr = &_arr[0];
			for (size_type n = 0; n < _size; n++, ptr++)
				_alloc.destroy(ptr);
			_size = 0;
		}

		allocator_type	get_allocator() const {return Alloc(_alloc);}
	};
}
	template <class T, class Alloc>
		void	swap(ft::vector<T, Alloc> &x, ft::vector<T, Alloc> &y) {
			x.swap(y);
		}
	
	template <class T, class Alloc>
  		bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			typename ft::vector<T>::const_iterator lit = lhs.begin();
			typename ft::vector<T>::const_iterator lit2 = lhs.end();
			typename ft::vector<T>::const_iterator rit = rhs.begin();
			typename ft::vector<T>::const_iterator rit2 = rhs.end();
			for(; lit != lit2 && rit != rit2; lit++, rit++)
				if (*lit != *rit)
					break ;
			if (rit != rit2 || lit != lit2)
				return false;
			return true;
		}

	template <class T, class Alloc>
		bool operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			return (!(lhs == rhs));
		}

	template <class T, class Alloc>
		bool operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			if (lhs.size() < rhs.size())
				return (true);
			if (lhs.size() > rhs.size())
				return (false);
			typename ft::vector<T>::const_iterator lit = lhs.begin();
			typename ft::vector<T>::const_iterator lit2 = lhs.end();
			typename ft::vector<T>::const_iterator rit = rhs.begin();
			typename ft::vector<T>::const_iterator rit2 = rhs.end();
			for(; lit != lit2 && rit != rit2; lit++, rit++)
			{
				if (*lit < *rit)
					return true;
				if (*rit < *lit)
					return false;
			}
			return false;
		}

	template <class T, class Alloc>
		bool operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			if (lhs.size() < rhs.size())
				return (true);
			if (lhs.size() > rhs.size())
				return (false);
			typename ft::vector<T>::const_iterator lit = lhs.begin();
			typename ft::vector<T>::const_iterator lit2 = lhs.end();
			typename ft::vector<T>::const_iterator rit = rhs.begin();
			typename ft::vector<T>::const_iterator rit2 = rhs.end();
			for(; lit != lit2 && rit != rit2; lit++, rit++)
			{
				if (*lit <= *rit)
					return true;
				if (*rit <= *lit)
					return false;
			}
			return false;
		}

	template <class T, class Alloc>
		bool operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			if (lhs.size() > rhs.size())
				return (true);
			else if (lhs.size() < rhs.size())
				return false;
			typename ft::vector<T>::const_iterator lit = lhs.begin();
			typename ft::vector<T>::const_iterator lit2 = lhs.end();
			typename ft::vector<T>::const_iterator rit = rhs.begin();
			typename ft::vector<T>::const_iterator rit2 = rhs.end();
			for(; lit != lit2 && rit != rit2; lit++, rit++)
			{
				if (*lit > *rit)
					return true;
				if (*rit > *lit)
					return false;
			}
			return false;
		}

	template <class T, class Alloc>
		bool operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			if (lhs.size() > rhs.size())
				return (true);
			if (lhs.size() < rhs.size())
				return (false);
			typename ft::vector<T>::const_iterator lit = lhs.begin();
			typename ft::vector<T>::const_iterator lit2 = lhs.end();
			typename ft::vector<T>::const_iterator rit = rhs.begin();
			typename ft::vector<T>::const_iterator rit2 = rhs.end();
			for(; lit != lit2 && rit != rit2; lit++, rit++)
			{
				if (*lit >= *rit)
					return true;
				if (*rit >= *lit)
					return false;
			}
			return false;
		}
		