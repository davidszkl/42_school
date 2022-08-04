#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern		usefulIdiot;
	Bureaucrat	paul("Paul", 3);
	Form		*form;

	form = usefulIdiot.makeForm("this one doesn't exist", "Justin");
	if (form)
		delete form;
	std::cout << std::endl;

	form = usefulIdiot.makeForm("PresidentialPardonForm", "Maynard");
	if (form)
		delete form;
	std::cout << std::endl;

	form = usefulIdiot.makeForm("ShrubberyCreationForm", "Danny");
	if (form)
		delete form;
	std::cout << std::endl;
	
	form = usefulIdiot.makeForm("RobotomyRequestForm", "Adam");
	form->beSigned(paul);
	form->execute(paul);
	if (form)
		delete form;
}
