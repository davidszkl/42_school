#include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Form			*form = NULL;
	Bureaucrat		bob("bob", 1);
	Bureaucrat		phil("phil", 1);
	Bureaucrat		luc("luc", 1);

	try
	{
		form = new PresidentialPardonForm("28Z");
		form->execute(bob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		delete form;
		form = new PresidentialPardonForm("28A");
		form->beSigned(bob);
		form->execute(bob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		delete form;
		form = new RobotomyRequestForm("28B");
		form->beSigned(bob);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		delete form;
		form = new ShrubberyCreationForm("28C");
		form->beSigned(bob);
		form->execute(bob);
		form->execute(luc);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form;
	return 0;
}