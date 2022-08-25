#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{	
public:

	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(Bureaucrat const & cpy);
	~Bureaucrat();

	Bureaucrat& operator=(Bureaucrat const & rhs);

	std::string	getName()		const;
	int			getGrade()		const;
	void		checkGrade()	const;
	void		promote();
	void		demote();

private:

	const std::string	_name;
	int					_grade;

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
};

std::ostream&	operator<<(std::ostream &ostr, Bureaucrat const & instance);

#endif