#include "contact.hpp"

contact::contact(){}
contact::~contact(){}

std::string	contact::getinfo(int nbr) const
{
	if (nbr < 0 || nbr > 4)
		return NULL;
	return (contact::info[nbr]);
}

int	contact::setinfo(std::string str, int nbr)
{
	if (nbr < 0 || nbr > 4)
		return 1;
	this->info[nbr] = str;
	return 0;
}