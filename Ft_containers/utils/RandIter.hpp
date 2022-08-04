/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:14:28 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/29 10:14:33 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RANDITER_HPP
# define RANDITER_HPP
#include <iostream>

namespace ft
{

template <typename T>
class RandIter
{
public:

	typedef T 				value_type;
    typedef std::ptrdiff_t	difference_type;
    typedef T*				pointer;
    typedef T&				ref;

	pointer getPtr() const {return _ptr;}

private:

	pointer		_ptr;

public:
// CONSTRUCTORS, DESTRUCTORS ===================================================

	RandIter(){
		_ptr = nullptr;
	}

	RandIter(T *ptr1){
		_ptr = ptr1;
	}

	RandIter(const RandIter &src){
		*this = src;
	}

	virtual ~RandIter(){}

	RandIter<T> &operator=(const RandIter&rhs)
	{
		this->_ptr = rhs._ptr;
		return *this;
	}

//OPERATOR OVERLOADS ==========================================================

	ref 		operator*(void)		const	{return *_ptr;}
    pointer 	operator->(void)	const	{return _ptr;}

    RandIter<T> &operator++(){
		_ptr++;
		return *this;
	}

    RandIter<T> &operator--(){
		_ptr--;
		return *this;
	}

    RandIter<T> operator++(int dummy){
		(void)dummy;
		RandIter<T> tmp = *this;
		operator++();
		return tmp;
	}

    RandIter<T>	operator--(int dummy){
		(void)dummy;
		RandIter<T> tmp = *this;
		operator--();
		return tmp;
	}

    RandIter<T>	&operator+=(const difference_type &offset){
		_ptr += offset;
		return *this;
	}

    RandIter<T> &operator-=(const difference_type &offset){
		_ptr -= offset;
		return *this;
	}

    RandIter<T>	operator+(difference_type offset) 	const{
		RandIter<T> tmp(*this);
		tmp._ptr += offset;
		return tmp;
	}

    RandIter<T> operator-(difference_type offset)	const{
		RandIter<T> tmp(*this);
		tmp._ptr -= offset;
		return tmp;
	}

	difference_type	operator-(RandIter<T> const& rhs)	const {
		uintptr_t tmp1 = reinterpret_cast<uintptr_t>(this->_ptr);
		uintptr_t rhs1 = reinterpret_cast<uintptr_t>(rhs._ptr);
		difference_type diff = ((tmp1 - rhs1) / sizeof(T));
		return diff ;
	}

	T&	operator[](difference_type offset)	const{
		return _ptr[offset];
	}

	bool operator<(const RandIter<T> &rhs) 	const {return _ptr < rhs._ptr;}
	bool operator<=(const RandIter<T> &rhs)	const {return _ptr <= rhs._ptr;}
	bool operator>(const RandIter<T> &rhs)	const {return _ptr > rhs._ptr;}
	bool operator>=(const RandIter<T> &rhs)	const {return _ptr >= rhs._ptr;}
	bool operator==(const RandIter<T> &rhs)	const {return _ptr == rhs._ptr;}
	bool operator!=(const RandIter<T> &rhs)	const {return _ptr != rhs._ptr;}
};

}
#endif