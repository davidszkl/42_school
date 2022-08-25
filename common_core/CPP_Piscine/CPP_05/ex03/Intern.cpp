#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Intern constructor" << std::endl;
}

Intern::Intern(Intern const & cpy)
{
	std::cout << "Copy Intern constructor" << std::endl;
	*this = cpy;
}

Intern::~Intern()
{
	std::cout << "Intern destructor" << std::endl;
}

Intern& Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

Form*	Intern::makeForm(std::string name, std::string target)
{
	t_formList	pile[] =
	{
		{ "PresidentialPardonForm", new PresidentialPardonForm(target) },
		{ "RobotomyRequestForm", new RobotomyRequestForm(target) },
		{ "ShrubberyCreationForm", new ShrubberyCreationForm(target) }
	};

	Form	*correctForm = NULL;

	for (int n = 0; n < 3; n++)
	{
		if (name == pile[n].formName)
			correctForm = pile[n].formType;
		else
			delete pile[n].formType;
	}
	if (!correctForm)
		std::cout << "Form doesn't exist" << std::endl;
	else
		std::cout << "Intern makes " << name << std::endl;
	return (correctForm);
}

std::ostream &	operator<<( std::ostream & ostr, Intern const & instance)
{
	(void)instance;
	ostr << "Intern" << std::endl;
	return ostr;
}