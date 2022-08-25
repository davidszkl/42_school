#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("SCF", 145, 137), _target("")
{
	std::cout << "Default RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("SCF", 145, 137), _target(target)
{
	std::cout << "Parametrized RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & cpy)
{
	std::cout << "Copy RobotomyRequestForm constructor" << std::endl;
	*this = cpy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	std::cout << "assignement operator RobotomyRequestForm" << std::endl;
	_target = rhs.getTarget();
	return *this;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExec() || !getApproved())
		throw Form::ExecutionError();
	std::cout << "* drilling sounds * ";
	std::srand(std::time(nullptr));
	int rand = std::rand();
	if (rand % 2)
		std::cout << "SUCCESS" << std::endl;
	else
		std::cout << "PATIENT DIED" << std::endl;
}
