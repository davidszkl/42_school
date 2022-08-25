#ifndef INTERN_HPP
# define INTERN_HPP
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
public:

	Intern();
	Intern(Intern const & cpy);
	~Intern();

	Intern& operator=(Intern const & rhs);

	Form*	makeForm(std::string name, std::string target);

private:

	typedef struct	formList
	{
		std::string	formName;
		Form		*formType;
	}	t_formList;
};

std::ostream &	operator<<( std::ostream & ostr, Intern const & instance);

#endif