#ifndef KAREN_HPP
# define KAREN_HPP
# define DEBUG	 1
# define INFO	 2
# define WARNING 3
# define ERROR	 4
# include <iostream>

class Karen
{
public:	
	
	Karen();
	~Karen();

	void complain(std::string level);

private:

	void debug();
	void info();
	void warning();
	void error();

};

#endif