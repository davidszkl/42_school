#include "Form.hpp"

Form::Form(): _name("unnamed"), _signGrade(1), _execGrade(1), _approved(false)
{
	std::cout << "Default Form constructor" << std::endl;
}

Form::Form(const std::string name, int signGrade, int execGrade):	
	_name(name),
	_signGrade(signGrade),
	_execGrade(execGrade),
	_approved(false)
{
	checkGrade();
	std::cout << "Parametrzied Form constructor" << std::endl;
}

Form::Form(Form const & cpy):	_name(cpy.getName()),
								_signGrade(cpy.getSign()),
								_execGrade(cpy.getExec()),
								_approved(false)
{
	std::cout << "Copy Form constructor" << std::endl;
	*this = cpy;
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

Form& Form::operator=(Form const & rhs)
{
	std::cout << "Form assignement operator" << std::endl;
	_approved	= rhs.getApproved();
	return *this;
}

std::ostream&	operator<<(std::ostream &ostr, Form const & instance)
{
	ostr << "FORM " << instance.getName()	<< "\n"
											<< "signGrade: " << instance.getSign()		<< "\n"
											<< "execGrade: " << instance.getExec()		<< "\n"
											<< "signed: " 	<< instance.getApproved()	<< std::endl;
	return ostr;
}

std::string	Form::getName() const
{
	return _name;
}

int	Form::getSign() const
{
	return _signGrade;
}

int	Form::getExec() const
{
	return _execGrade;
}

bool	Form::getApproved() const
{
	return _approved;
}

void	Form::checkGrade()	const
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

Form& Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	else
		_approved = true;
	return *this;
}