#include <stack>
#include <iostream>
#include "mutantStack.hpp"
int main()
{
	mutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mutantStack<int>::iterator it = mstack.begin();
	mutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
		std::cout << *it++ << std::endl;
	std::stack<int> s(mstack);
	return 0;
}