#include "span.hpp"

int main()
{
	span sp = span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	span big(10000);
	size_t n = 0;
	while (n++ < 10000)
		big.addNumber(n);
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;
	span big2(10000);
	try {
		big2.addNumber(big.getStored().begin(), big.getStored().end());
	}
	catch (std::exception &e) {}
	std::cout << big2.shortestSpan() << std::endl;
	std::cout << big2.longestSpan() << std::endl;
}