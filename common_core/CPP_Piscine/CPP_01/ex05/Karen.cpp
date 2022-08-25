#include "Karen.hpp"

Karen::Karen()
{
	std::cout << "Karen entered the shop" << std::endl;
}

Karen::~Karen()
{
	std::cout << "Karen left the shop unhappy of your service, she will you give you a negative revue" << std::endl;
}

void Karen::complain(std::string level)
{
	void (Karen::*FuncPtr[])(void) = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};
	std::string levels[] = {
		"debug",
		"info",
		"warning",
		"error"
	};
	for (int n = 0; n < 4; n++)
	{
		void (Karen::*selectedComplaint)(void) = FuncPtr[n];
		if (level == levels[n])
			(this->*selectedComplaint)();
	}
}

void Karen::debug()
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}