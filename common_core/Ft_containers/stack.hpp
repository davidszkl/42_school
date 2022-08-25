#pragma once
#include "vector.hpp"
namespace ft
{

template <class T, class Container = ft::vector<T> >
class stack
{
public:

    typedef T           value_type;
    typedef Container   container_type;
    typedef size_t      size_type;

    explicit stack(const container_type& cntr = container_type()): c(cntr) {}

    stack &operator=(const stack &other) {
        if (this != &other)
            c = other.c;
        return (*this);
    }

protected:

    container_type  c;

public:

    bool				empty()	const	{return c.empty();}
    size_type			size()	const	{return c.size();}
    value_type&			top()			{return c.back();}
    const value_type&	top()	const	{return c.back();}
    void				push(const value_type& val) {c.push_back(val);}
    void				pop()						{c.pop_back();}

};

template <class T, class Container>
  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
      return lhs == rhs;
  }

template <class T, class Container>
  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
      return lhs != rhs;
  }

template <class T, class Container>
  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
      return lhs < rhs;
  }

template <class T, class Container>
  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
      return lhs <= rhs;
  }

template <class T, class Container>
  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
      return lhs > rhs;
  }

template <class T, class Container>
  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
      return lhs >= rhs;
  }
}