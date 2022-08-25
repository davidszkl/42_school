#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("SCF", 145, 137), _target("")
{
	std::cout << "Default ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("SCF", 145, 137), _target(target)
{
	std::cout << "Parametrized ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & cpy)
{
	std::cout << "Copy ShrubberyCreationForm constructor" << std::endl;
	*this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << "assignement operator ShrubberyCreationForm" << std::endl;
	_target = rhs.getTarget();
	return *this;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExec() || !getApproved())
		throw Form::ExecutionError();
		
	std::string fileName = _target + "_shrubbery";
	std::ofstream ofs;

	ofs.open(fileName, std::ofstream::out);
	ofs << 	"         _-_"			<< "\n";
	ofs <<	"      /~~   ~~\\"		<< "\n";
	ofs << 	"   /~~         ~~\\"	<< "\n";
	ofs << 	"  {               }"	<< "\n";
	ofs << 	"   \\  _-     -_  /"	<< "\n";
	ofs << 	"    ~   \\\\ //  ~"	<< "\n";
	ofs << 	"  _- -   | | _- _"		<< "\n";
	ofs << 	"  _ -    | |   -_"		<< "\n";
	ofs << 	"        // \\\\"		<< std::endl;
	ofs.close();

	std::cout << "Created shrug in " << fileName << std::endl;
}