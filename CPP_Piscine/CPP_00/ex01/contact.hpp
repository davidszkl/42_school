#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>

class contact
{

public:

	contact();
	~contact();

	std::string	getinfo(int nbr) const;
	int			setinfo(std::string info, int nbr);

private:

	std::string	info[5];
};

#endif