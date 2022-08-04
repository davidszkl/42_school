#ifndef INTERPRETER_HPP
# define INTERPRETER_HPP
# include <iostream>
# include <string>
# include <limits>
# include <sstream>

class interpreter
{
public:

	interpreter();
	interpreter(char *str);
	interpreter(interpreter const & cpy);
	~interpreter();

	interpreter& operator=(interpreter const & rhs);

	std::string getTrimmed()const;
	char*		getInput()	const;
	char		getChar()	const;
	int			getInt()	const;
	float		getFloat()	const;
	double		getDouble()	const;
	int			getType()	const;

	void	setTrimmed(std::string input);
	void	setChar(char	 trimmed);
	void	setInt(int		 trimmed);
	void	setFloat(float	 trimmed);
	void	setDouble(double trimmed);

	std::string	readInput();
	std::string	strtrim(std::string str);
	void		output() const;

private:

	std::string	_trimmed;
	char*		_input;
	char		_char;
	int			_int;
	float		_float;
	double		_double;
	int			_type; 		// 0 = char, 1 = int, 2 = float, 3 = double

public:

	class ReadError : public std::exception
	{
		const char * what() const throw()
		{
			return "Error : not an int, float, double or char";
		}
	};
};

#endif