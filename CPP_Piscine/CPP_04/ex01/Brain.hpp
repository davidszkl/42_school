#ifndef BRAIN_H
# define BRAIN_H
# include <iostream>
class Brain
{
public:

	Brain();
	Brain(Brain const & cpy);
	~Brain();

	Brain &operator=(Brain const & rhs);
	
	std::string getIdea(int nbr) const;
	void		setIdea(int nbr, std::string idea);
	void		setIdeas(std::string idea);

private:
	
	std::string	_Ideas[100];
};

#endif