#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Form	f("EB110", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Form	f("EB111", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Form	f("EB112", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Form	f("EB113", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat	john = Bureaucrat("John", 1);
		Form		f("EB114", 150, 150);

		std::cout << f << std::endl;
		john.signForm(f);
		f.beSigned(john);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat	joe = Bureaucrat("Joe", 10);
		Form		f("EB115", 1, 1);

		std::cout << f << std::endl;
		joe.signForm(f);
		f.beSigned(joe);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}