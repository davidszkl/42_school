#include "Interpreter.hpp"

interpreter::interpreter(): _input(nullptr), _char(0), _int(0), _float(0), _double(0) {
//	std::cout << "Default interpreter constructor" << std::endl;
}

interpreter::interpreter(char *str): _input(str), _char(0), _int(0), _float(0), _double(0) {
//	std::cout << "Parametrized interpreter constructor" << std::endl;
}

interpreter::interpreter(interpreter const & cpy) {
//	std::cout << "Copy interpreter constructor" << std::endl;
	*this = cpy;
}

interpreter::~interpreter() {
//	std::cout << "interpreter destructor" << std::endl;
}

interpreter& interpreter::operator=(interpreter const & rhs) {
	_input 	= rhs.getInput();
	_char 	= rhs.getChar();
	_int	= rhs.getInt();
	_float 	= rhs.getFloat();
	_double = rhs.getDouble();
	_type	= rhs.getType();
	return *this;
}

std::string interpreter::getTrimmed() const {return _trimmed;}
char*		interpreter::getInput()	  const {return _input;}
char		interpreter::getChar()	  const {return _char;}
int			interpreter::getInt()	  const {return _int;}
float		interpreter::getFloat()	  const {return _float;}
double		interpreter::getDouble()  const {return _double;}
int			interpreter::getType()	  const {return _type;}

void	interpreter::setTrimmed(std::string input)	{_trimmed = input;}
void	interpreter::setChar(char trimmed)			{_char	  = trimmed;}
void	interpreter::setInt(int	trimmed)			{_int	  = trimmed;}
void	interpreter::setFloat(float trimmed)		{_float   = trimmed;}
void	interpreter::setDouble(double trimmed)		{_double  = trimmed;}

std::string	interpreter::strtrim(std::string str)
{
	std::string input;
	size_t	n = 0;

	while (n < str.length())
	{
		if (str[n] != ' ')
			break ;
		n++;
	}
	input = str.substr(n, str.length() - n);
	n = input.length();
	while (n > 0)
	{
		if (input[n] != ' ')
			break ;
		n--;
	}
	input = input.substr(0, n + 1);
	return input;
}

std::string interpreter::readInput()
{
	std::string tmp 	= _input;
	std::string input 	= strtrim(tmp);
	size_t		counter = 0;

	if (!input[0])
	{
		_type = -1;
		throw ReadError();
	}

	//Check char

	if (input.length() == 1 && !std::isdigit(input[0]) && input[0] > 31 && input[0] < 127)
	{
		_type = 0;
		return input;
	}

	//Check int

	for (size_t n = 0; n < input.length(); n++)
	{
		if (!std::isdigit(input[n]) || (input[n] == '-' && n == 0))
			break ;
		counter++;
	}
	if (counter == input.length())
	{
		_type = 1;
		return input;
	}

	//Check float

	int	dot = 0;
	int	f	= 0;
	for (counter = 0; counter < input.length(); counter++)
	{
		if (input[counter] == '.' && counter < input.length() - 2 && counter)
			dot++;
		else if (input[counter] == 'f' && counter == input.length() - 1 && counter)
			f++;
		else if (input[counter] == '-')
		{
			if (counter)
				break ;
			continue ;
		}
		else if (!std::isdigit(input[counter]))
			break ;
	}
	//std::cout << "counter = " << counter << "\ninputLength = " << input.length() << "\ndot = " << dot << "\nf = " << f << std::endl;
	if ((dot == 1 && f == 1 && counter == input.length()) || input == "-inff" || input == "+inff" || input == "nanf")
	{
		_type = 2;
		return input;
	}

	//Check double

	dot	= 0;
	for (counter = 0; counter < input.length(); counter++)
	{
		if (input[counter] == '.' && counter < input.length() - 1 && counter)
			dot++;
		else if (input[counter] == '-')
		{
			if (counter)
				break ;
			continue ;
		}
		else if (!std::isdigit(input[counter]))
			break ;
	}
	if ((dot == 1 && counter == input.length()) || input == "-inf" || input == "+inf" || input == "nan")
	{
		_type = 3;
		return input;
	}
	throw ReadError();
}

void	interpreter::output() const
{
	std::stringstream ss;
	std::string tmp;

///////////////////////////////////////////**CHAR**////////////////////////////////////////////////

	if (_char >= 32 && _char <= 126)
		std::cout << "char   = '" << _char << "'\n";
	else if ((_char >= 0 && _char < 32) || _char == 127)
		std::cout << "char   = non displayable" << std::endl;
	else
		std::cout << "char   = impossible" << std::endl;
///////////////////////////////////////////**INT**/////////////////////////////////////////////////

	if (_int > std::numeric_limits<int>::max() || _int < std::numeric_limits<int>::min())
		std::cout << "int    = impossible";
	else
		std::cout << "int    = " << _int << "\n";
/////////////////////////////////////////**FLOAT**/////////////////////////////////////////////////

	if (_float > std::numeric_limits<float>::max() || _float < std::numeric_limits<float>::min())
		std::cout << "float  = impossible" << std::endl;
	else
	{
		std::cout << "float  = " << _float;
		ss << getFloat();
		tmp = ss.str();
		if (tmp.find('.') == std::string::npos)
			std::cout << ".0";
		std::cout << "f\n";
	}
//////////////////////////////////////////**DOUBLE**//////////////////////////////////////////////

	if (_double > std::numeric_limits<double>::max() || _double < std::numeric_limits<double>::min())
		std::cout << "double = impossible" << std::endl;
	else
	{
		std::cout << "double = " << _double;
		ss << getDouble();
		tmp = ss.str();
		if (tmp.find('.') == std::string::npos)
			std::cout << ".0" << std::endl;
		std::cout << std::endl;
	}
}

