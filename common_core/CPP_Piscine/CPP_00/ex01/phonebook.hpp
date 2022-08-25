#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "contact.hpp"
# include <iomanip>
# include <iostream>

class phonebook
{

public:

	phonebook();
	~phonebook();

	int		add();
	void	search() const;
	int		getnbr() const;
	void	setnbr(int nbr);

private:

contact	book[8];
int		_nbr;

};

#endif