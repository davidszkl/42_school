#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:

	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & cpy);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(PresidentialPardonForm const & rhs);

	std::string	getTarget() const;
	virtual	void execute(Bureaucrat const & executor) const;

private:

	std::string _target;
};

#endif