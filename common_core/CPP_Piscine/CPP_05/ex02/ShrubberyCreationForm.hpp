#ifndef SHRUBBERYCRETIONFORM_HPP
# define SHRUBBERYCRETIONFORM_HPP
# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form
{
public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const & cpy);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(ShrubberyCreationForm const & rhs);

	std::string	getTarget() const;
	virtual	void execute(Bureaucrat const & executor) const;

private:

	std::string _target;
};

#endif