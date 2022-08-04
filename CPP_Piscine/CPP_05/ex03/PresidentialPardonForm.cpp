#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("SCF", 145, 137), _target("")
{
	std::cout << "Default PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("SCF", 145, 137), _target(target)
{
	std::cout << "Parametrized PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & cpy)
{
	std::cout << "Copy PresidentialPardonForm constructor" << std::endl;
	*this = cpy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	std::cout << "assignement operator PresidentialPardonForm" << std::endl;
	_target = rhs.getTarget();
	return *this;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExec() || !getApproved())
		throw Form::ExecutionError();
	std::cout << _target << " was pardoned by Zafod Beeblebrox" << std::endl;
}