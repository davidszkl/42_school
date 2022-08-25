#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:

	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & cpy);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(RobotomyRequestForm const & rhs);

	std::string	getTarget() const;
	virtual	void execute(Bureaucrat const & executor) const;

private:

	std::string _target;
};

#endif