#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor" << std::endl;
}

Brain::Brain(Brain const & cpy)
{
	std::cout << "Copy Brain constructor" << std::endl;
	*this = cpy;
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl; 
}

Brain &Brain::operator=(Brain const & rhs)
{
	for (int n = 0; n < 100; n++)
		_Ideas[n] = rhs.getIdea(n);
	return *this;
}

std::string Brain::getIdea(int nbr) const
{
	return _Ideas[nbr];
}

void	Brain::setIdea(int nbr, std::string idea)
{
	if (nbr < 0 || nbr > 99)
		return ;
	_Ideas[nbr] = idea;
}

void	Brain::setIdeas(std::string idea)
{
	for (int n = 0; n < 100; n++)
		_Ideas[n] = idea;
}