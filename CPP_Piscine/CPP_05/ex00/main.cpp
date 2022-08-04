#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	joe = Bureaucrat("Joe", 1);
		std::cout << joe << std::endl;
		joe.demote();
		std::cout << joe << std::endl;
		joe.promote();
		std::cout << joe << std::endl;
		joe.promote();
		std::cout << joe << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat		jack = Bureaucrat("Jack", 150);
		std::cout << jack << std::endl;
		jack.promote();
		std::cout << jack << std::endl;
		jack.demote();
		std::cout << jack << std::endl;
		jack.demote();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat		john = Bureaucrat("John", 0);
		std::cout << john << std::endl;
		john.demote();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat		jillian = Bureaucrat("Jillian", 151);
		std::cout << "TEST" << std::endl;
		jillian.promote();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}