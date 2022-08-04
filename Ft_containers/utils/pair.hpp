#pragma once
namespace  ft
{

template <class T1, class T2>
struct pair
{
public:

	typedef T1	first_type;
	typedef T2	second_type;

	first_type	first;
	second_type second;

//constructors

	pair(): first(), second() {};
template< class U, class V >
	pair (const pair<U, V>& pr): first(pr.first), second(pr.second) {}
	pair (const pair<T1, T2>& pr): first(pr.first), second(pr.second) {}
	pair (const first_type& a, const second_type& b): first(a), second(b) {};

//operator = 
	pair& operator= (const pair& pr) {
		second = pr.second;
		return *this;
	}

	~pair(){}
};
//relational operators

template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return lhs.first == rhs.first;}
template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return lhs.first != rhs.first;}
template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return lhs.first < rhs.first;}
template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return lhs.first <= rhs.first;}
template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return lhs.first > rhs.first;}
template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return lhs.first >= rhs.first;}

template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) {return pair<T1, T2>(x, y);}
}
