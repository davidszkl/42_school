#include <vector>
#include <stack>
#include <map>
#include "stack.hpp"
#include "vector.hpp"
#include "map.hpp"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <stdlib.h>
#include <unistd.h>

typedef ft::vector<int, std::allocator<int> > ft_vec;
typedef const ft::vector< int, std::allocator< int> > ft_const_vec;
typedef std::vector<int, std::allocator<int> > st_vec;
typedef const std::vector<int, std::allocator< int> > st_const_vec;
typedef ft::map<const int, const std::string>::const_iterator			Citer;
typedef ft::map<const int, const std::string>::const_reverse_iterator	CRiter;
typedef std::map<const int, const std::string>::const_iterator			SCiter;
typedef std::map<const int, const std::string>::const_reverse_iterator	SCRiter;


template <typename U, typename V >
void show_map(ft::map<U, V> & map ) {
	if (map.empty())
	{
		std::cout << "empty\n";
		return ;
	}
	//typename ft::RBT<ft::map<U, V> >::Node_ptr node =  map._rbt.min(map._rbt.root());
	typename ft::map<U, V>::iterator it = map.begin();
	typename ft::map<U, V>::iterator it2 = map.end();
	size_t n = 0;
	while (it != it2)
	{
		std::cout << "map[" << n++ << "][key " << it->first << "] = " << it->second << std::endl;
		it++;
	}
	//for (size_t n = 0; n < map.size(); n++, node = map._rbt.successor(node))
	//	std::cout << "map[" << n << "][key " << node->data.first << "] = " << map[node->data.first] << std::endl;
	std::cout << std::endl;
}

void show_map(ft::map<const int, const std::string> & map ) {
	if (map.empty())
	{
		std::cout << "empty\n";
		return ;
	}
	ft::map<const int, const std::string>::iterator it = map.begin();
	ft::map<const int, const std::string>::iterator it2 = map.end();
	size_t n = 0;
	while (it != it2)
	{
		std::cout << "map[" << n++ << "][key " << it->first << "] = " << it->second << std::endl;
		it++;
	}
	//ft::RBT<ft::map<const int, const std::string> >::Node_ptr node =  map._rbt.min(map._rbt.root());
	//for (size_t n = 0; n < map.size(); n++, node = map._rbt.successor(node))
	//	std::cout << "map[" << n << "][key " << node->data.first << "] = " << map[node->data.first] << std::endl;
	std::cout << std::endl;
}

void show(ft_vec mine, st_vec stl) {
	ft::vector<int>::iterator it1 = mine.begin();
	ft::vector<int>::iterator it2 = mine.end();
	std::vector<int>::iterator it3 = stl.begin();
	std::vector<int>::iterator it4 = stl.end();
	
	it2--;
	it4--;
	std::cout << "mine(" << mine.size() << " / " << mine.capacity() << "): {";
	if (!mine.size())
		std::cout << "}\n";
	else
	{
		for (; it1 != it2; it1++)
			std::cout << *it1 << ", ";
		std::cout << *it1 << "}" << std::endl;
	}
	std::cout << "stl(" << stl.size() << " / " << stl.capacity() << "):  {";
	if (!stl.size())
		std::cout << "}\n";
	else
	{
		for (; it3 != it4; it3++)
			std::cout << *it3 << ", ";
		std::cout << *it3 << "}" << std::endl << std::endl;
	}
}

void show1(ft_vec mine, st_vec stl) {
	ft::vector<int>::iterator it1 = mine.begin();
	ft::vector<int>::iterator it2 = mine.end();
	std::vector<int>::iterator it3 = stl.begin();
	std::vector<int>::iterator it4 = stl.end();
	
	it2--;
	it4--;
	std::cout << "mine2(" << mine.size() << " / " << mine.capacity() << "): {";
	if (!mine.size())
		std::cout << "}\n";
	else
	{
		for (; it1 != it2; it1++)
			std::cout << *it1 << ", ";
		std::cout << *it1 << "}" << std::endl;
	}
	std::cout << "stl(" << stl.size() << " / " << stl.capacity() << "):  {";
	if (!stl.size())
		std::cout << "}\n";
	else
	{
		for (; it3 != it4; it3++)
			std::cout << *it3 << ", ";
		std::cout << *it3 << "}" << std::endl << std::endl;
	}
}

void show2(ft_vec vec1, ft_vec vec2)
{
	ft::vector<int>::iterator it1 = vec1.begin();
	ft::vector<int>::iterator it2 = vec1.end();
	ft::vector<int>::iterator it3 = vec2.begin();
	ft::vector<int>::iterator it4 = vec2.end();

	it2--;
	it4--;
	std::cout << "mine_2(" << vec1.size() << " / " << vec1.capacity() << "): {";
	for (; it1 != it2; it1++)
		std::cout << *it1 << ", ";
	std::cout << *it1 << "}" << std::endl;
	std::cout << "stl2(" << vec2.size() << " / " << vec2.capacity() << "):  {";
	for (; it3 != it4; it3++)
		std::cout << *it3 << ", ";
	std::cout << *it3 << "}" << std::endl;
}

int main()
{
{
	using namespace std::chrono;
	std::allocator<int> alloc;
	ft_vec   mine(5, 10);
	ft_vec   mine2(5, 42);
	ft_vec   empty(0);

	st_vec  stl(5, 10);
	st_vec  stl2(5, 6);
	st_vec	stl_empty(0);

	ft::vector<int>::iterator				mine_it1 = mine.begin();
	ft::vector<int>::reverse_iterator		mine_Rit1 = mine.rbegin();
	//ft::vector<int>::iterator				mine_it2 = mine.end();
	//ft::vector<int>::reverse_iterator		mine_Rit2 = mine.rend();

	std::vector<int>::iterator				stl_it1 = stl.begin();
	std::vector<int>::reverse_iterator		stl_Rit1 = stl.rbegin();	
	//std::vector<int>::iterator			stl_it2 = stl.end();
	//std::vector<int>::reverse_iterator	stl_Rit2 = stl.rend();

	std::cout << "\n==========ITERATORS===========" << std::endl;

	show(mine, stl);
	show1(mine2, stl2);

	std::cout << "mine_it1:  " << *mine_it1 << std::endl;
	std::cout << "mine_rit1: " << *mine_Rit1 << std::endl;
	std::cout << "stl_it1:   " << *stl_it1 << std::endl;
	std::cout << "stl_rit1:  " << *stl_Rit1 << std::endl;
	std::cout << "empty begin: " << *(empty.begin()) << std::endl;
	std::cout << "empty end:   " << *(empty.end()) << std::endl;
	//std::cout << "mine_it2:  " << *mine_it2 << std::endl;
	//std::cout << "mine_rit2: " << *mine_Rit2 << std::endl;
	//std::cout << "stl_it2:   " << *stl_it2 << std::endl;
	//std::cout << "stl_rit2:  " << *stl_Rit2 << std::endl;


	show(mine, stl);
	std::cout << "==========CAPACITY===========" << std::endl;
	std::cout << "mine_max_size: " << mine.max_size() << std::endl;
	std::cout << "stl_max_size: " << stl.max_size() << std::endl;
	show(mine, stl);

	std::cout << "--------RESIZE_UP :" << std::endl;

	mine.resize(10, 5);
	stl.resize(10, 5);
	std::cout << "mine_max_size: " << mine.max_size() << std::endl;
	std::cout << "stl_max_size: " << stl.max_size() << std::endl;
	show(mine, stl);

	std::cout << "--------RESIZE_DOWN :" << std::endl;
	mine.resize(5, 42);
	stl.resize(5, 42);
	show(mine, stl);

	std::cout << "--------RESIZE_SAME :" << std::endl;
	mine.resize(5, 21);
	stl.resize(5, 21);
	show(mine, stl);

	std::cout << "--------EMPTY :" << std::endl;
	std::cout << mine.empty() << std::endl;
	std::cout << empty.empty() << std::endl;
	std::cout << stl.empty() << std::endl;
	show(mine, stl);

	std::cout << "--------RESERVE_MORE :" << std::endl;
	mine.reserve(50);
	stl.reserve(50);
	show(mine, stl);

	std::cout << "--------RESERVE_LESS :" << std::endl;
	mine.reserve(25);
	stl.reserve(25);
	show(mine, stl);

	std::cout << "--------RESERVE_SAME :" << std::endl;
	mine.reserve(25);
	stl.reserve(25);
	show(mine, stl);

	std::cout << "==========ELEMENT_ACCESS===========" << std::endl;
	mine[0] = 1;
	mine[1] = 3;
	stl[0] = 1;
	stl[1] = 3;
	show(mine, stl);

	std::cout << "--------OPERATOR[] :" << std::endl;
	std::cout << "mine[0]: " << mine[0] << std::endl;
	std::cout << "mine[1]: " << mine[1] << std::endl;

	std::cout << "stl[0]:  " << stl[0] << std::endl;
	std::cout << "stl[1]:  " << stl[1] << std::endl << std::endl;

	std::cout << "--------NORMAL_AT(3) :" << std::endl;
	std::cout << "mine: " << mine.at(3) << std::endl;
	std::cout << "stl:  " << stl.at(3) << std::endl << std::endl;

	std::cout << "--------OUT_OF_BOUNDS_AT(15) :" << std::endl;
	try {
		std::cout << "mine: " << mine.at(15) << std::endl;}
	catch  (std::exception &e){std::cout << e.what() << std::endl;}
	try {
		std::cout << "stl:  " << stl.at(15) << std::endl;}
	catch  (std::exception &e){std::cout << e.what() << std::endl << std::endl;}

	std::cout << "--------FRONT :" << std::endl;
	std::cout << "mine: " << mine.front() << std::endl;
	std::cout << "stl:  " << stl.front() << std::endl << std::endl;

	std::cout << "--------BACK :" << std::endl;
	std::cout << "mine: " << mine.back() << std::endl;
	std::cout << "stl:  " << stl.back() << std::endl << std::endl;

	std::cout << "==========MODIFIERS===========" << std::endl;
	show1(mine2, stl2);
	show(mine, stl);

	std::cout << "-------RANGE_ASSIGN(mine assigned with mine_2, stl assigned with stl_2) :" << std::endl;
	mine.assign(mine2.begin(), mine2.end());
	stl.assign(stl2.begin(), stl2.end());
	show1(mine2, stl2);
	show(mine, stl);

	std::cout << "-------VALUE_ASSIGN(mine2 assigned with 10,15 ; stl assigned with 10,15) :" << std::endl;
	mine2.assign(10, 15);
	stl2.assign(10, 15);
	std::cout << "size now = " << mine2.size() << std::endl;
	show1(mine2, stl2);
	show(mine, stl);

	std::cout << "--------PUSH_BACK/POP_BACK :" << std::endl;
	std::cout << "push 5 numbers, pop 5 numbers" << std::endl;
	for (int j = 0; j < 5; j++)
	{
		mine.push_back(j + 1);
		stl.push_back(j + 1);
		show(mine, stl);
	}

	for (int j = 0; j < 5; j++)
	{
		mine.pop_back();
		stl.pop_back();
		show(mine, stl);
	}

	std::cout << "---------INSERT 1 at 0, 1, end" << std::endl;
	mine.assign(10, 0);
	stl.assign(10, 0);
	show(mine, stl);

	mine_it1 = mine.insert(mine.begin(), 1);
	stl_it1 = stl.insert(stl.begin(), 1);
	std::cout << "mine_it1 = " << *mine_it1 << std::endl;
	std::cout << "stl_it1  = " << *stl_it1 << std::endl;
	show(mine, stl);

	mine_it1 = mine.insert(mine.begin() + 1, 2);
	stl_it1 = stl.insert(stl.begin() + 1, 2);
	std::cout << "mine_it1 = " << *mine_it1 << std::endl;
	std::cout << "stl_it1  = " << *stl_it1 << std::endl;
	show(mine, stl);

	mine.insert(mine.begin() + mine.size(), 1);
	stl.insert(stl.begin() + stl.size(), 1);
	show(mine, stl);

	std::cout << "---------INSERT 5 numbers at 0, 1, end" << std::endl;
	mine.assign(10, 0);
	stl.assign(10, 0);
	for (int j = 0; j < 10; j++)
	{
		mine[j] = j + 1;
		stl[j] = j + 1;
	}
	show(mine, stl);

	mine.insert(mine.begin(), 5, 0);
	stl.insert(stl.begin(), 5, 0);
	show(mine, stl);

	mine.insert(mine.begin() + 1, 5, 0);
	stl.insert(stl.begin() + 1, 5, 0);
	show(mine, stl);

	mine.insert(mine.begin() + mine.size(), 5, 0);
	stl.insert(stl.begin() + stl.size(), 5, 0);
	show(mine, stl);

	std::cout << "---------INSERT range of 5 numbers at 0, 1, end" << std::endl;
	mine.assign(10, 0);
	stl.assign(10, 0);
	mine2.assign(10, 0);
	stl2.assign(10, 0);
	for (int j = 0; j < 10; j++)
	{
		mine2[j] = j + 1;
		stl2[j] = j + 1;
	}
	show1(mine2, stl2);
	show(mine, stl);

	mine.insert(mine.begin(), mine2.begin(), mine2.end());
	stl.insert(stl.begin(), stl2.begin(), stl2.end());
	show(mine, stl);

	mine.insert(mine.begin() + 1, mine2.begin(), mine2.begin() + 5);
	stl.insert(stl.begin() + 1, stl2.begin(), stl2.begin() + 5);
	show(mine, stl);

	mine.insert(mine.begin() + mine.size(), mine2.begin(), mine2.begin() + 5);
	stl.insert(stl.begin() + stl.size(), stl2.begin(), stl2.begin() + 5);
	show(mine, stl);

	std::cout << "--------ERASE :" << std::endl;
	std::cout << "erase the insert changes" << std::endl;
	show(mine, stl);

	for (int n = 0; n < 5; n++)
	{
		mine_it1 = mine.erase(mine.begin());
		stl_it1 = stl.erase(stl.begin());
	}
	show(mine, stl);
	std::cout << "Return iterator = " << *mine_it1 << std::endl;
	std::cout << "Return iterator = " << *stl_it1 << std::endl;

	mine_it1 = mine.erase(mine.begin(), mine.begin() + 10);
	stl_it1 = stl.erase(stl.begin(), stl.begin() + 10);
	show(mine, stl);
	std::cout << "Return iterator = " << *mine_it1 << std::endl;
	std::cout << "Return iterator = " << *stl_it1 << std::endl;

	mine_it1 = mine.erase(mine.begin() + 10, mine.begin() + 15);
	stl_it1 = stl.erase(stl.begin() + 10, stl.begin() + 15);
	show(mine, stl);
	std::cout << "Return iterator = " << *(mine_it1 - 1) << std::endl;
	std::cout << "Return iterator = " << *(stl_it1 - 1) << std::endl;

	// std::cout << "erase empty" << std::endl;
	// std::cout << "size = " << empty.size() << std::endl;
	// stl_empty.erase(stl_empty.begin());
	// stl_empty.erase(stl_empty.end());
	// empty.erase(empty.begin());
	// empty.erase(empty.end());

	std::cout << "--------SWAP_EMPTY :" << std::endl;
	show(empty, stl_empty);
	show(mine, stl);

	mine.swap(empty);
	stl.swap(stl_empty);
	show(empty, stl_empty);
	show(mine, stl);

	std::cout << "--------SWAP_NOT_EMPTY :" << std::endl;
	show(mine, stl);
	show(mine2, stl2);
	std::cout << std::endl;

	mine.swap(mine2);
	stl.swap(stl2);
	show(mine, stl);
	show(mine2, stl2);

	std::cout << "--------CLEAR :" << std::endl;
	std::cout << "clear twice" << std::endl;
	show(mine, stl);

	mine.clear();
	stl.clear();
	show(mine, stl);

	mine.clear();
	stl.clear();
	show(mine, stl);

	std::cout << "\n==========RELATIONAL OPERATORS===========" << std::endl;
	mine.assign(10, 0);
	mine2.assign(10, 1);
	show2(mine, mine2);

	std::cout << "mine == mine2 --> ";
	if (mine == mine2)
 		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "mine != mine2 --> ";
	if (mine != mine2)
 		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "mine < mine2 --> ";
	if (mine < mine2)
 		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "mine > mine2 --> ";
	if (mine > mine2)
 		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "mine <= mine2 --> ";
	if (mine <= mine2)
 		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "mine >= mine2 --> ";
	if (mine >= mine2)
 		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << std::endl;

	std::cout << "==========TIMERS===" << std::endl;
	std::cout << "check out a few operation heavy functions for times" << std::endl;

	high_resolution_clock				clock;
	high_resolution_clock::time_point	t1;
	high_resolution_clock::time_point	t2;
	microseconds::rep					time_span1;
	microseconds::rep					time_span2;

	ft_vec	my_big(10000, 5);
	st_vec	stl_big(10000, 5);
	std::cout << "my_size: " << my_big.size() << std::endl;
	std::cout << "my_size: " << stl_big.capacity() << std::endl << std::endl;

	std::cout << "assign 10000 50s" << std::endl;
	t1 = clock.now();
	my_big.assign(10000, 50);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.assign(10000, 50);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time:" << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n" << std::endl;

	std::cout << "range_assign 5000" << std::endl;
	ft_vec clone1(5000, 0);
	st_vec clone2(5000, 0);

	t1 = clock.now();
	my_big.assign(clone1.begin(), clone1.end());
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.assign(clone2.begin(), clone2.end());
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time:" << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n" << std::endl;

	std::cout << "insert at 5000" << std::endl;
	t1 = clock.now();
	my_big.insert(my_big.begin() + 5000, 10);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.insert(stl_big.begin() + 5000, 10);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time:" << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n" << std::endl;

	std::cout << "insert 5000 at 5000" << std::endl;
	t1 = clock.now();
	my_big.insert(my_big.begin() + 5000, 5000, 10);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.insert(stl_big.begin() + 5000, 5000, 10);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time:" << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n" << std::endl;

	std::cout << "erase 1 at: 1, 5000, end" << std::endl;
	t1 = clock.now();
	my_big.erase(my_big.begin());
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.erase(stl_big.begin());
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time: " << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n";

	t1 = clock.now();
	my_big.erase(my_big.begin() + 4998);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.erase(stl_big.begin() + 4998);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time: " << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n";

	t1 = clock.now();
	my_big.erase(my_big.begin() + 9995);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.erase(stl_big.begin() + 9995);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time: " << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n";

	std::cout << "\nerase 10 ,100, 1000 at: 5000" << std::endl;
	t1 = clock.now();
	my_big.erase(my_big.begin() + 5000, my_big.begin() + 5010);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.erase(stl_big.begin() + 5000, stl_big.begin() + 5010);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time: " << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n";

	t1 = clock.now();
	my_big.erase(my_big.begin() + 5000, my_big.begin() + 5100);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.erase(stl_big.begin() + 5000, stl_big.begin() + 5100);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time: " << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n";

	t1 = clock.now();
	my_big.erase(my_big.begin() + 5000, my_big.begin() + 6000);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.erase(stl_big.begin() + 5000, stl_big.begin() + 6000);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time: " << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n";

	std::cout << "\nconstant versions" << std::endl;
	ft_const_vec cVec(10, 10);
	st_const_vec cSvec(10, 10);
	ft::vector<int>::const_iterator cit1 = cVec.begin();
	//ft::vector<int>::const_iterator cit2 = cVec.end();
	std::vector<int>::const_iterator cit3 = cSvec.begin();
	//std::vector<int>::const_iterator cit4 = cSvec.end();

	std::cout << *cit1 << std::endl;
	//std::cout << *cit2 << std::endl;
	std::cout << *cit3 << std::endl;
	//std::cout << *cit4 << std::endl;

	cit1++;
	cit3++;

	std::cout << *cit1 << std::endl;
	std::cout << *cit3 << std::endl;

	std::cout << cVec.size() << std::endl;
	std::cout << cVec.max_size() << std::endl;
	//std::cout << cVec.resize(5) << std::endl;
	std::cout << cVec.capacity() << std::endl;
	std::cout << cVec.empty() << std::endl;
	//std::cout << cVec.reserve(42) << std::endl;

	std::cout << cSvec.size() << std::endl;
	std::cout << cSvec.max_size() << std::endl;
	//std::cout << cSvec.resize(5) << std::endl;
	std::cout << cSvec.capacity() << std::endl;
	std::cout << cSvec.empty() << std::endl;
	//std::cout << cSvec.reserve(42) << std::endl;

	std::cout << cVec[0] << std::endl;
	std::cout << cVec.at(5) << std::endl;
	std::cout << cVec.front() << std::endl;
	std::cout << cVec.back() << std::endl;

	std::cout << cSvec[0] << std::endl;
	std::cout << cSvec.at(5) << std::endl;
	std::cout << cSvec.front() << std::endl;
	std::cout << cSvec.back() << std::endl;

	//*cit1 = 5;
	//*cit3 = 5;

	//constVec.insert(constVec.begin(), 1);
	//constVec.insert(constVec.begin() + 1, 10, 1);
	//constVec.insert(constVec.begin() + 11, constVec.begin(), constVec.end());
	//ft_const_vec constVec2 = constVec;
	std::cout << "If it compiled then it's ok, decommenting any of the lines would make it not compile" << std::endl;
}

std::cout << "\n\n__________STACK____________\n\n" << std::endl;
//===============================================================================================================
//===============================================================================================================
//===============================================================================================================
//===============================================================================================================
{
    ft::stack<int>  My;
    std::stack<int> Stl;

	if (My.empty())
    	std::cout << "empty" << std::endl;
	else
		std::cout << "not empty" << std::endl;
	if (Stl.empty())
    	std::cout << "empty" << std::endl;
	else
		std::cout << "not empty" << std::endl;
	
	std::cout << "push 3" << std::endl;
	My.push(1);
	std::cout << My.top() << std::endl;
	My.push(2);
	std::cout << My.top() << std::endl;
	My.push(3);
	std::cout << My.top() << std::endl;
	Stl.push(1);
	std::cout << Stl.top() << std::endl;
	Stl.push(2);
	std::cout << Stl.top() << std::endl;
	Stl.push(3);
	std::cout << Stl.top() << std::endl;

	std::cout << "size" << std::endl;
	std::cout << My.size() << std::endl;
	std::cout << Stl.size() << std::endl;

	std::cout << "pop 3" << std::endl;
	std::cout << My.top() << std::endl;
	My.pop();
	std::cout << My.top() << std::endl;
	My.pop();
	std::cout << My.top() << std::endl;
	My.pop();

	std::cout << "pop 3" << std::endl;
	std::cout << Stl.top() << std::endl;
	Stl.pop();
	std::cout << Stl.top() << std::endl;
	Stl.pop();
	std::cout << Stl.top() << std::endl;
	Stl.pop();

	std::cout << "empty ?" << std::endl;
	if (My.empty())
    	std::cout << "empty" << std::endl;
	else
		std::cout << "not empty" << std::endl;
	if (Stl.empty())
    	std::cout << "empty" << std::endl;
	else
		std::cout << "not empty" << std::endl;

}
//===============================================================================================================
//===============================================================================================================
//===============================================================================================================
//===============================================================================================================

std::cout << "\n\n__________MAP____________\n\n" << std::endl;

	std::pair<int, int> pair;
	ft::map<int, std::string>	My;
	ft::map<int, std::string>	copy(My);
	std::map<int, std::string>	Stl;
	typedef ft::map<int, std::string>::iterator			iter;
	typedef ft::map<int, std::string>::reverse_iterator Riter;
	//typedef std::map<int, std::string>::reverse_iterator Stl_Riter;

	My.insert(ft::make_pair<int, std::string>(1, "a"));
	My.insert(ft::make_pair<int, std::string>(2, "b"));
	My.insert(ft::make_pair<int, std::string>(3, "c"));
	My.insert(ft::make_pair<int, std::string>(4, "d"));
	My.insert(ft::make_pair<int, std::string>(-1, "c"));
	My.insert(ft::make_pair<int, std::string>(5, "c"));
	My.insert(ft::make_pair<int, std::string>(6, "c"));

	ft::map<int, std::string>	rangeConstruct(My.begin(), My.end());
	show_map(My);
	show_map(copy);
//	show_map(Stl);
	show_map(rangeConstruct);

	std::cout	<< "==========|MAP_ITERATOR|============\n";
	std::cout	<< "\n-----------CONSTRUCTORS-------------\n";
	iter it1;
	it1 = My.begin();
	std::cout << "default:                          \033[1;32;mok\033[0m\n";
	//iter it2(My._rbt.root(), &My._rbt);
	//std::cout << "parameterized:                    \033[1;32;mok\033[0m\n";
	iter it2(it1);
	std::cout << "copy:                             \033[1;32;mok\033[0m\n";
	it1 = it2; 
	std::cout << "assignement:                      \033[1;32;mok\033[0m\n";
	Riter Rit1;
	Riter Rit2;

	std::cout << "-----------DEREFERENCING------------\n";
	std::cout << "it1 = " << (*it1).first << std::endl;
	std::cout << "it2 = " << it2->first << std::endl;
	if ((*it1).first != (*it2).first)
	{
		std::cout << "'*'  operator:                    \033[1;31mko\033[0m\n";
		std::cout << "'->' operator:                    \033[1;31mko\033[0m\n";
	}
	else
	{
		std::cout << "'*' operator:                     \033[1;32mok\033[0m\n";
		std::cout << "'->' operator:                    \033[1;32mok\033[0m\n";
	}
	*it2 = *it1;
	std::cout << "it2 = it1 = " << (*it2).first << std::endl;
	std::cout << "lvalue:                           \033[1;32mok\033[0m\n";

	std::cout << "-----------INCREMENTATION-----------\n";
	std::cout << "pre-increment:  " <<  (*(++it1)).first << std::endl;
	std::cout << "post-increment: " << (*(it2++)).first << std::endl;
	
	std::cout << "compare:                          ";
	if ((*it2).first != (*(it1)).first)
		std::cout << "s\033[1;31mko\033[0m\n";
	else
		std::cout << "\033[1;32mok\033[0m\n";
	std::cout << "pre-decrement:  " <<  (*(--it1)).first << std::endl;
	std::cout << "post-decrement: " << (*(it2--)).first << std::endl;
	std::cout << "compare:                          ";
	if ((*it2).first != (*(it1)).first)
		std::cout << "s\033[1;31mko\033[0m\n";
	else
		std::cout << "\033[1;32mok\033[0m\n";

	std::cout << "-------------BEGIN/END--------------\n";
	it1 = My.begin();
	it2 = My.end();
	
	show_map(My);

	std::cout << (*it1).first << std::endl;
	std::cout << (*it2).first << std::endl;
	std::cout << "begin:                            \033[1;32mok\033[0m\n";
	std::cout << "end:                              \033[1;32mok\033[0m\n";
	Rit1 = My.rbegin();
	Rit2 = My.rend();
	std::cout << (*Rit1).first << std::endl;
	//std::cout << (*Rit2).first << std::endl;
	std::cout << "rbegin:                           \033[1;32mok\033[0m\n";
	std::cout << "rend:                             \033[1;32mok\033[0m\n";

	std::cout << "============|CAPACITY|==============\n";

	std::cout << "size     = " << My.size() << "                      \033[1;32mok\033[0m\n";
	std::cout << "max_size = " << My.max_size() << "     \033[1;32mok\033[0m\n";
	std::cout << "empty    = ";
	if (My.empty()) std::cout << "true" << "                   \033[1;32mok\033[0m\n";
	else std::cout << "false" << "                  \033[1;32mok\033[0m\n";

	std::cout << "==========|ELEMENT_ACCESS|==========\n" << std::endl;
	std::cout << "-------------operator[]-------------\n";

	Stl.insert(std::make_pair<const int, std::string>(1, "a"));
	Stl.insert(std::make_pair<const int, std::string>(2, "b"));
	Stl.insert(std::make_pair<const int, std::string>(3, "c"));
	std::cout << "map[1] = " << My[1] << std::endl;
	std::cout << "map[2] = " << My[2] << std::endl;
	std::cout << "map[3] = " << My[3] << std::endl;
	My[4];
	std::cout << "map[4] (doesn't exist yet) = " << My[42] << std::endl;
	
	std::cout << "map[4] (exists now) = " << My[42] << std::endl;
	std::cout << "map[-1] = " << My[-1] << std::endl;
	std::cout << "stl[1] = " << Stl[1] << std::endl;
	std::cout << "stl[2] = " << Stl[2] << std::endl;
	std::cout << "stl[3] = " << Stl[3] << std::endl;
	std::cout << "stl[4] (doesn't exist yet) = " << Stl[4] << std::endl;
	std::cout << "stl[4] (exists now) = " << Stl[4] << std::endl;
	std::cout << "stl[-1] = " << Stl[-1] << std::endl;
	std::cout << "operator[]                        \033[1;32mok\033[0m\n";
	 
	std::cout << "============|MODIFIERS|=============\n\n";
	std::cout << "------------single_insert-----------\n";

	std::string string("coucou");
	ft::pair<iter, bool> a;
	a = My.insert(ft::make_pair<const int, std::string>(4, string));
	std::cout << a.second << " already exists" << std::endl;
	a = My.insert(ft::make_pair<const int, std::string>(5, "salut"));
	std::cout << a.second << " doesn't exist" <<std::endl;
	a = My.insert(ft::make_pair<const int, std::string>(41, "salut"));
	std::cout << a.second << " doesn't exist" <<std::endl;
	a = My.insert(ft::make_pair<const int, std::string>(1, "bonjour"));
	std::cout << a.second << " already exists" << std::endl;
	std::cout << "insert single:                    \033[1;32mok\033[0m\n";

	std::cout << "-------------hint_insert------------\n";

	My.insert(My.begin(), ft::make_pair<const int, std::string>(7, "f"));
	std::cout << "My[7] = " << My[7] << std::endl;
	My.insert(My.begin(), ft::make_pair<const int, std::string>(7, "z"));
	std::cout << "My[7] = " << My[7] << std::endl;
	My.insert(My.begin(), ft::make_pair<const int, std::string>(8, "g"));
	std::cout << "My[8] = " << My[8] << std::endl;
	std::cout << "hint insert :                     \033[1;32mok\033[0m\n";

	std::cout << "-------------range_insert------------\n";

	copy = My;
	ft::map<int, std::string>	tmp_map1;
	show_map(copy);
	show_map(tmp_map1);
	tmp_map1.insert(copy.begin(), copy.end());
	show_map(copy);
	show_map(tmp_map1);

	std::cout << "range insert :                    \033[1;32mok\033[0m\n";
	 
	std::cout << "-----------iterator_delete----------\n";
	 
	show_map(My);
	My.erase(My.begin());
	show_map(My);
	std::cout << "single delete :                   \033[1;32mok\033[0m\n";
	 
	std::cout << "-------------key_delete-------------\n";

	size_t tmp_size;
	tmp_size = My.erase(1);
	std::cout << "tmp = " << tmp_size << std::endl;
	show_map(My);
	tmp_size = My.erase(1);
	std::cout << "tmp = " << tmp_size << std::endl;
	show_map(My);
	std::cout << "key delete :                      \033[1;32mok\033[0m\n";

	std::cout << "------------range_delete------------\n";
	 
	My.erase(My.begin(), My.begin() + 3);
	show_map(My);
	std::cout << "range delete :                    \033[1;32mok\033[0m\n";

	std::cout << "---------------swap-----------------\n";

	ft::map<int, std::string>	tmp_map2;
	for (char n = 0; n < 5; n++)
		tmp_map2.insert(ft::make_pair<const int, std::string>(n + 1, "tmp"));
	show_map(My);
	show_map(tmp_map2);
	My.swap(tmp_map2);
	show_map(My);
	show_map(tmp_map2);
	std::cout << "swap :                            \033[1;32mok\033[0m\n";

	std::cout << "--------------clear-----------------\n";
	
	My = copy;
	show_map(My);
	My.clear();
	std::cout << "My: ";
	show_map(My);
	std::cout << "clear :                           \033[1;32mok\033[0m\n";

	std::cout << "=============|OBSERVERS|============\n";

	My = copy;
	ft::map<int, std::string>::key_compare compare_tmp = My.key_comp();
	std::cout << compare_tmp(My.begin()->first, (My.begin() + 1)->first) << std::endl;
	std::cout << compare_tmp((My.begin() + 1)->first, My.begin()->first) << std::endl;
	ft::map<int, std::string>::value_compare compare_tmp2 = My.value_comp();
	std::cout << compare_tmp2(*My.begin(), *(My.begin() + 1)) << std::endl;
	std::cout << compare_tmp2(*(My.begin() + 1) , *My.begin()) << std::endl;
	std::cout << "key_compare :                     \033[1;32mok\033[0m\n";
	std::cout << "value_compare :                   \033[1;32mok\033[0m\n";

	std::cout << "============|OPERATIONS|============\n";
	std::cout << "--------------Search----------------\n";

	show_map(My);
	//show_map(Stl);
	std::cout << "Search key 3 " << std::endl;
	std::cout << "key = " << My.find(3)->first << std::endl;
	std::cout << "Search non-existent key " << std::endl;
	std::cout << "key = " << My.find(100)->first << std::endl;
	std::cout << "Search key 3 " << std::endl;
	std::cout << "key = " << Stl.find(3)->first << std::endl;
	std::cout << "Search non-existent key " << std::endl;
	std::cout << "key = " << Stl.find(100)->first << std::endl;
	std::cout << "search :                         \033[1;32mok\033[0m\n";
	std::cout << "--------------Count----------------\n";
	std::cout << "Count existent:     " << My.count(1) << std::endl;
	std::cout << "Count non-existent: " << My.count(18) << std::endl;
	std::cout << "count :                          \033[1;32mok\033[0m\n";

	std::cout << "-----------Lower_bound-------------\n";

	Stl.clear();
	Stl.insert(std::make_pair<const int, std::string>(0, "c"));
	Stl.insert(std::make_pair<const int, std::string>(1, "a"));
	Stl.insert(std::make_pair<const int, std::string>(2, "b"));
	Stl.insert(std::make_pair<const int, std::string>(3, "c"));
	Stl.insert(std::make_pair<const int, std::string>(4, "d"));
	Stl.insert(std::make_pair<const int, std::string>(5, "c"));
	Stl.insert(std::make_pair<const int, std::string>(6, "c"));
	Stl.insert(std::make_pair<const int, std::string>(7, "f"));
	Stl.insert(std::make_pair<const int, std::string>(8, "g"));
	//show_map(Stl);
	//show_map(My);
	std::cout << "Lower bounds:\nStl:\n";
	std::cout << "at min     : " << Stl.lower_bound(0)->first << std::endl;
	std::cout << "at min + 1 : " << Stl.lower_bound(1)->first << std::endl;
	std::cout << "at middle  : " << Stl.lower_bound(5)->first << std::endl;
	std::cout << "at end - 1 : " << Stl.lower_bound(7)->first << std::endl;
	std::cout << "at end     : " << Stl.lower_bound(8)->first << std::endl;
	std::cout << "overflow   : " << Stl.lower_bound(15)->first << std::endl;
	std::cout << "underflow  : " << Stl.lower_bound(-15)->first << std::endl;

	std::cout << "My:\n";
	std::cout << "at min     : " << My.lower_bound(-1)->first << std::endl;
	std::cout << "at nan     : " << My.lower_bound(0)->first << std::endl;
	std::cout << "at min + 1 : " << My.lower_bound(1)->first << std::endl;
	std::cout << "at middle  : " << My.lower_bound(5)->first << std::endl;
	std::cout << "at end - 1 : " << My.lower_bound(7)->first << std::endl;
	std::cout << "at end     : " << My.lower_bound(8)->first << std::endl;
	std::cout << "overflow   : " << My.lower_bound(15)->first << std::endl;
	std::cout << "underflow  : " << My.lower_bound(-15)->first << std::endl;
	std::cout << "lower_bounds :                   \033[1;32mok\033[0m\n";
	std::cout << "-----------Upper_bound-------------\n";

	std::cout << "Upper bounds:\nStl:\n";
	std::cout << "at min     : " << Stl.upper_bound(0)->first << std::endl;
	std::cout << "at min + 1 : " << Stl.upper_bound(1)->first << std::endl;
	std::cout << "at middle  : " << Stl.upper_bound(5)->first << std::endl;
	std::cout << "at end - 1 : " << Stl.upper_bound(7)->first << std::endl;
	std::cout << "at end     : " << Stl.upper_bound(8)->first << std::endl;
	std::cout << "overflow   : " << Stl.upper_bound(15)->first << std::endl;
	std::cout << "underflow  : " << Stl.upper_bound(-15)->first << std::endl;

	std::cout << "My:\n";
	std::cout << "at nan     : " << My.upper_bound(0)->first << std::endl;
	std::cout << "at min     : " << My.upper_bound(-1)->first << std::endl;
	std::cout << "at min + 1 : " << My.upper_bound(1)->first << std::endl;
	std::cout << "at middle  : " << My.upper_bound(5)->first << std::endl;
	std::cout << "at end - 1 : " << My.upper_bound(7)->first << std::endl;
	std::cout << "at end     : " << My.upper_bound(8)->first << std::endl;
	std::cout << "overflow   : " << My.upper_bound(15)->first << std::endl;
	std::cout << "underflow  : " << My.upper_bound(-15)->first << std::endl;
	std::cout << "Upper_bounds :                   \033[1;32mok\033[0m\n";

	std::cout << "-----------equal_range-------------\n";
	ft::pair<iter, iter>Range1(My.equal_range(3));
	ft::pair<iter, iter>Range2(My.equal_range(15));
	while (Range1.first != Range1.second)
	{
		std::cout << "key " << Range1.first->first << std::endl;
		Range1.first++;
	}
	while (Range2.first != Range2.second)
	{
		std::cout << "key " << Range1.first->first << std::endl;
		Range1.first++;
	}
	std::cout << "Range 2: empty" << std::endl;
	std::cout << "equal_range :                    \033[1;32mok\033[0m\n";
	std::cout << "-----------equal_range-------------\n";

	std::cout << "==============|TIMERS|=============\n\n";
	using namespace std::chrono;
	high_resolution_clock				clock;
	high_resolution_clock::time_point	t1;
	high_resolution_clock::time_point	t2;
	microseconds::rep					time_span1;
	microseconds::rep					time_span2;

	ft::map<int, std::string>	My_big;
	std::map<int, std::string>	Stl_big;
	ft::map<int, std::string>	My2_big;
	std::map<int, std::string>	Stl2_big;
	std::cout << "============|INSERTIONS|===========\n\n";

	std::cout << "insert 10000 'a':\n----------------" << std::endl;

	t1 = clock.now();
	for (size_t n = 0; n < 10000; n++)
		My_big.insert(ft::make_pair<const int, std::string>(n, "a"));
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	for (size_t n = 0; n < 10000; n++)
		Stl_big.insert(std::make_pair<const int, std::string>(n, "a"));
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "big_insert :                     \033[1;31mko\033[0m\n";
	else
		std::cout << "big_insert :                     \033[1;32mok\033[0m\n";

	std::cout << "insert 1 at 0, 5000, 10000" << std::endl;
	std::cout << "-------------------------" << std::endl;

	My2_big  = My_big;
	Stl2_big = Stl_big;
	t1 = clock.now();
	My_big.insert(ft::make_pair<const int, std::string>(0, "a"));
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl_big.insert(std::make_pair<const int, std::string>(0, "a"));
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "insert at 0:                     \033[1;31mko\033[0m\n";
	else
		std::cout << "insert at 0:                     \033[1;32mok\033[0m\n";
	std::cout << "--------------" << std::endl;
	
	t1 = clock.now();
	My_big.insert(ft::make_pair<const int, std::string>(5000, "a"));
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl_big.insert(std::make_pair<const int, std::string>(5000, "a"));
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "insert at 5000:                  \033[1;31mko\033[0m\n";
	else
		std::cout << "insert at 5000:                  \033[1;32mok\033[0m\n";
	std::cout << "---------------" << std::endl;

	t1 = clock.now();
	My_big.insert(ft::make_pair<const int, std::string>(10000, "a"));
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl_big.insert(std::make_pair<const int, std::string>(10000, "a"));
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "insert at 10000:                 \033[1;31mko\033[0m\n";
	else
		std::cout << "insert at 10000:                 \033[1;32mok\033[0m\n";
	std::cout << "----------------" << std::endl << std::endl;

	std::cout << "insert range1 into range 2:" << std::endl;
	std::cout << "---------------------------" << std::endl;
	t1 = clock.now();
	My2_big.clear();
	My2_big.insert(My_big.begin(), My_big.end());
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl2_big.clear();
	Stl2_big.insert(Stl_big.begin(), Stl_big.end());
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "clear + range_insert:            \033[1;31mko\033[0m\n";
	else
		std::cout << "clear + range_insert:            \033[1;32mok\033[0m\n";
	std::cout << "---------------------" << std::endl << std::endl;

	std::cout << "==============|ERASES|=============\n\n";

	std::cout << "erase 1 at 0, 5000, 9998 (key):" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	t1 = clock.now();
	My2_big.erase(0);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl2_big.erase(0);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "erase at 0:                      \033[1;31mko\033[0m\n";
	else
		std::cout << "erase at 0:                      \033[1;32mok\033[0m\n";
	std::cout << "-----------" << std::endl;

	t1 = clock.now();
	My2_big.erase(5000);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl2_big.erase(5000);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "erase at 5000:                   \033[1;31mko\033[0m\n";
	else
		std::cout << "erase at 5000:                   \033[1;32mok\033[0m\n";
	std::cout << "--------------" << std::endl;

	t1 = clock.now();
	My2_big.erase(9998);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl2_big.erase(9998);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "erase at 9998:                   \033[1;31mko\033[0m\n";
	else
		std::cout << "erase at 9998:                   \033[1;32mok\033[0m\n";
	std::cout << "--------------" << std::endl;

	std::cout << "erase 1 at 0, 5000, 9998(iterator):" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	t1 = clock.now();
	My_big.erase(My_big.begin());
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl_big.erase(Stl_big.begin());
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "erase at 0:                      \033[1;31mko\033[0m\n";
	else
		std::cout << "erase at 0:                      \033[1;32mok\033[0m\n";
	std::cout << "-----------" << std::endl;

	t1 = clock.now();
	My_big.erase(My_big.find(5000));
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl_big.erase(Stl_big.find(5000));
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "erase at 5000:                   \033[1;31mko\033[0m\n";
	else
		std::cout << "erase at 5000:                   \033[1;32mok\033[0m\n";
	std::cout << "--------------" << std::endl;

	t1 = clock.now();
	My_big.erase(My_big.find(9998));
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl_big.erase(Stl_big.find(9998));
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "erase at 9998:                   \033[1;31mko\033[0m\n";
	else
		std::cout << "erase at 9998:                   \033[1;32mok\033[0m\n";
	std::cout << "--------------" << std::endl;

	My_big.insert(ft::make_pair<const int, std::string>(0, "a"));
	My_big.insert(ft::make_pair<const int, std::string>(5000, "a"));
	My_big.insert(ft::make_pair<const int, std::string>(9998, "a"));
	Stl_big.insert(std::make_pair<const int, std::string>(0, "a"));
	Stl_big.insert(std::make_pair<const int, std::string>(5000, "a"));
	Stl_big.insert(std::make_pair<const int, std::string>(9998, "a"));

	My2_big.insert(ft::make_pair<const int, std::string>(0, "a"));
	My2_big.insert(ft::make_pair<const int, std::string>(5000, "a"));
	My2_big.insert(ft::make_pair<const int, std::string>(9998, "a"));
	Stl2_big.insert(std::make_pair<const int, std::string>(0, "a"));
	Stl2_big.insert(std::make_pair<const int, std::string>(5000, "a"));
	Stl2_big.insert(std::make_pair<const int, std::string>(9998, "a"));

	std::cout << "erase from begin to end:" << std::endl;
	std::cout << "------------------------" << std::endl;
	t1 = clock.now();
	My2_big.erase(My2_big.begin(), My2_big.end());
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl2_big.erase(Stl2_big.begin(), Stl2_big.end());
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "erase all:                       \033[1;31mko\033[0m\n";
	else
		std::cout << "erase all:                       \033[1;32mok\033[0m\n";
	std::cout << "-----------" << std::endl;

	std::cout << "===============|SWAP|==============\n\n";

	std::cout << "swap empty with full twice:" << std::endl;
	std::cout << "---------------------------" << std::endl;
	t1 = clock.now();
	My2_big.swap(My_big);
	My2_big.swap(My_big);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl2_big.swap(Stl_big);
	Stl2_big.swap(Stl_big);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "swap:                            \033[1;31mko\033[0m\n";
	else
		std::cout << "swap:                            \033[1;32mok\033[0m\n";
	std::cout << "-----------" << std::endl;

	std::cout << "===============|FIND|==============\n\n";
	std::cout << "find 0, 5000, 1000:" << std::endl;
	std::cout << "-------------------" << std::endl;

	t1 = clock.now();
	My2_big.find(0);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl2_big.find(0);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms" << std::endl;
	std::cout << "stl_time: " << time_span2 << "ms" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "find 0:                          \033[1;31mko\033[0m\n";
	else
		std::cout << "find 0:                          \033[1;32mok\033[0m\n";
	std::cout << "-----------" << std::endl;

	t1 = clock.now();
	My2_big.find(5000);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl2_big.find(5000);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "find 5000:                       \033[1;31mko\033[0m\n";
	else
		std::cout << "find 5000:                       \033[1;32mok\033[0m\n";
	std::cout << "--------------" << std::endl;

	t1 = clock.now();
	My2_big.find(10000);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	Stl2_big.find(10000);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time : " << time_span1 << "ms\n";
	std::cout << "stl_time: " << time_span2 << "ms\n" << std::endl;
	if (time_span1 > (time_span2 * 20))
		std::cout << "find 10000:                      \033[1;31mko\033[0m\n";
	else
		std::cout << "find 10000:                      \033[1;32mok\033[0m\n";
	std::cout << "---------------" << std::endl;

	std::cout << "============|CONSTANTS|============\n\n";
	ft::map<const int, const std::string>	cMap2;
	ft::map<const int, const std::string>	cMap(My.begin(), My.end());
	std::map<const int, const std::string>	cSmap2;
	std::map<const int, const std::string>	cSmap(Stl.begin(), Stl.end());
	typedef ft::map<const int, const std::string>::const_iterator			Citer;
	typedef ft::map<const int, const std::string>::const_reverse_iterator	CRiter;
	typedef std::map<const int, const std::string>::const_iterator			SCiter;
	typedef std::map<const int, const std::string>::const_reverse_iterator	SCRiter;
	Citer placeholder;
	CRiter placeholder2;
	SCiter placeholder3;
	SCRiter placeholder4;
	(void)placeholder;
	(void)placeholder2;
	(void)placeholder3;
	(void)placeholder4;

	show_map(cMap);
	Citer Cit = cMap.begin();;
	Citer Cit2 = cMap.end();
	CRiter CRit = cMap.rbegin();
	SCiter SCit = cSmap.begin();
	SCiter SCit2 = cSmap.end();
	SCRiter SCRit = cSmap.rbegin();

	std::cout << Cit->first << std::endl;
	std::cout << Cit2->first << std::endl;
	std::cout << CRit->first << std::endl;
	std::cout << SCit->first << std::endl;
	std::cout << SCit2->first << std::endl;
	std::cout << SCRit->first << std::endl;

	cMap.size();
	cMap.max_size();
	cMap.empty();

	std::cout << cMap.find(-1)->first << std::endl;

	return 0;
}






