#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate()
{
	Base *ptr;

	std::srand(std::time(nullptr));
	switch (std::rand() % 3){
		case 0:
			return ptr = new A();
		case 1:
			return ptr = new B();
		case 2:
			return ptr = new C();
	}
	return nullptr;
}

void identify(Base * p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" ;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" ;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" ;
}

void identifyRef(Base & p)
{
	Base *tmp = 0;

	try {
		*tmp = dynamic_cast<A &>(p);
		std::cout << "A" ;
	}
	catch (std::exception &e){};
	try {
		*tmp = dynamic_cast<B &>(p);
		std::cout << "B" ;
	}
	catch (std::exception &e){};
	try {
		*tmp = dynamic_cast<C &>(p);
		std::cout << "C" ;
	}
	catch (std::exception &e){};
}

#include <unistd.h>
int main()
{
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		
		Base *o = generate();
		std::cout << "Test " << i << ": ";
		identify(o);
		std::cout << ", ";
		identifyRef(*o);
		std::cout << "\n";
		delete o;
		usleep(100000);
	}

	return (0);
}