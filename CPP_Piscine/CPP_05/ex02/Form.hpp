#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{	
public:

	Form();
	Form(const std::string name, int signGrade, int execGrade);
	Form(Form const & cpy);
	virtual ~Form();

	Form& operator=(Form const & rhs);

	std::string	getName()		const;
	bool		getApproved()	const;
	int			getSign()		const;
	int			getExec()		const;
	Form&		beSigned(Bureaucrat const & bureaucrat);
	virtual	void execute(Bureaucrat const & executor) const = 0;
	void		checkGrade()	const;

private:

	const std::string	_name;
	const int			_signGrade;
	const int			_execGrade;
	bool				_approved;

public:

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade too high, range is [1-150]");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade too low, range is [1-150]");
		}
	};

	class ExecutionError : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Can't execute this form");
		}
	};
};

std::ostream&	operator<<(std::ostream &ostr, Form const & instance);

#endif