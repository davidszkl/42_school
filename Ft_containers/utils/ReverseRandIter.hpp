/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseReverseRandIter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:15:33 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/29 12:15:37 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef REVERSERANDOMITER_HPP
# define REVERSERANDOMITER_HPP
#include <iostream>

template <typename T>
class ReverseRandIter
{
public:

	typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T *pointer;
    typedef T &ref;

// CONSTRUCTORS, DESTRUCTORS ===================================================

	ReverseRandIter(){
		ptr = nullptr;
	}

	ReverseRandIter(T *ptr1){
		ptr = ptr1;
	}

	ReverseRandIter(const ReverseRandIter &src){
		*this = src;
	}

	virtual ~ReverseRandIter(){}

	ReverseRandIter<T> &operator=(const ReverseRandIter&rhs)
	{
		this->ptr = rhs.ptr;
		return *this;
	}

//OPERATOR OVERLOADS ==========================================================

	ref 		operator*(void)		const	{return *ptr;}
    pointer 	operator->(void)	const	{return ptr;}

    ReverseRandIter<T> &operator++(){
		ptr--;
		return *this;
	}

    ReverseRandIter<T> &operator--(){
		ptr++;
		return *this;
	}

    ReverseRandIter<T> operator++(int dummy){
		(void)dummy;
		ReverseRandIter<T> tmp = *this;
		operator--();
		return tmp;
	}

    ReverseRandIter<T>	operator--(int dummy){
		(void)dummy;
		ReverseRandIter<T> tmp = *this;
		operator++();
		return tmp;
	}

    ReverseRandIter<T>	&operator+=(const difference_type &offset){
		ptr -= offset;
		return *this;
	}

    ReverseRandIter<T> &operator-=(const difference_type &offset){
		ptr += offset;
		return *this;
	}

    ReverseRandIter<T>	operator+(difference_type offset) 	const{
		ReverseRandIter<T> tmp(*this);
		tmp.ptr -= offset;
		return tmp;
	}

    ReverseRandIter<T> operator-(difference_type offset)	const{
		ReverseRandIter<T> tmp(*this);
		tmp.ptr += offset;
		return tmp;
	}

	T&	operator[](difference_type offset)	const{
		return ptr[offset];
	}

	bool operator<(const ReverseRandIter<T> &rhs) 	{return ptr < rhs.ptr;}
	bool operator<=(const ReverseRandIter<T> &rhs)	{return ptr <= rhs.ptr;}
	bool operator>(const ReverseRandIter<T> &rhs)	{return ptr > rhs.ptr;}
	bool operator>=(const ReverseRandIter<T> &rhs)	{return ptr >= rhs.ptr;}
	bool operator==(const ReverseRandIter<T> &rhs)	{return ptr == rhs.ptr;}
	bool operator!=(const ReverseRandIter<T> &rhs)	{return ptr != rhs.ptr;}
	pointer ptr;
};

#endif
