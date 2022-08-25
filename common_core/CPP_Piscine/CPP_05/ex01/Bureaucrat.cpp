#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("unnamed"), _grade(1)
{
	std::cout << "Default Bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Parametrzied Bureaucrat constructor" << std::endl;
	checkGrade();
}

Bureaucrat::Bureaucrat(Bureaucrat const & cpy)
{
	std::cout << "Copy Bureaucrat constructor" << std::endl;
	*this = cpy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << "Bureaucrat assignement operator" << std::endl;
	_grade	= rhs.getGrade();
	return *this;
}

std::ostream&	operator<<(std::ostream &ostr, Bureaucrat const & instance)
{
	ostr << instance.getName() << ", bureaucrat grade " << instance.getGrade() << std::endl;
	return ostr;
}

std::string	Bureaucrat::getName() const
{
	return _name;
}

int			Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::checkGrade() const
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::promote()
{
	if (_grade < 2)
		throw Bureaucrat::GradeTooHighException();
	std::cout << _name << " got promoted" << std::endl;
	_grade--;

}

void	Bureaucrat::demote()
{
	if (_grade > 149)
		throw Bureaucrat::GradeTooLowException();
	std::cout << _name << " got demoted" << std::endl;
	_grade++;
}

void	Bureaucrat::signForm(Form const & form)	const
{
	if (_grade > form.getSign())
		std::cout << _name << "'s rank is too low to sign this form" << std::endl;
	else
		std::cout << _name << " signs" << form.getName() << std::endl;
}