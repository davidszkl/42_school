#include "phonebook.hpp"

phonebook::phonebook(){}
phonebook::~phonebook(){}

int	phonebook::add()
{
	std::string temp;

	if (_nbr > 7)
	{
		std::cout << "Phonebook full" << std::endl;
		return (0);
	}
	int	i = 0;
	while (!i)
	{
		std::cout << "First Name: ";
		getline(std::cin, temp);
		size_t	n;
		for (n = 0; n < temp.length(); n++)
			if ((std::isspace(temp[n]) && temp[n + 1]) || !std::isprint(temp[n]))
				break ;
		if (n < temp.length())
			continue ;
		book[_nbr].setinfo(temp, 0);
		i++;
	}
	i = 0;
	while (!i)
	{
		std::cout << "Last Name: ";
		getline(std::cin, temp);
		size_t	n;
		for (n = 0; n < temp.length(); n++)
			if ((std::isspace(temp[n]) && temp[n + 1]) || !std::isprint(temp[n]))
				break ;
		if (n < temp.length())
			continue ;
		book[_nbr].setinfo(temp, 1);
		i++;
	}
	i = 0;
	while (!i)
	{
		std::cout << "Nickname: ";
		getline(std::cin, temp);
		size_t	n;
		for (n = 0; n < temp.length(); n++)
			if ((std::isspace(temp[n]) && temp[n + 1]) || !std::isprint(temp[n]))
				break ;
		if (n < temp.length())
			continue ;
		book[_nbr].setinfo(temp, 2);
		i++;
	}
	i = 0;
	while (!i)
	{
		std::cout << "Phone Number: ";
		getline(std::cin, temp);
		size_t	n;
		for (n = 0; n < temp.length(); n++)
			if ((std::isspace(temp[n]) && temp[n + 1]) || !std::isprint(temp[n]))
				break ;
		if (n < temp.length())
			continue ;
		book[_nbr].setinfo(temp, 3);
		i++;
	}
	i = 0;
	while (!i)
	{
		std::cout << "Darkest Secret: ";
		getline(std::cin, temp);
		book[_nbr].setinfo(temp, 4);
		i++;
	}
	_nbr++;
	return (0);
}

void	phonebook::search() const
{
	if (!_nbr)
	{
		std::cout << "no contacts yet" << std::endl;
		return ;
	}
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	for(int	n = 0; n < _nbr; n++)
	{
		std::cout << std::setw(10) << n + 1 << "|";
		for (int j = 0; j < 3; j++)
		{
			if (book[n].getinfo(j).length() < 10)
				std::cout << std::setw(10) << book[n].getinfo(j) << "|";
			else
				std::cout << book[n].getinfo(j).substr(0, 9) << "." << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "Select a recipient's index to see more information\n";
	int	index;
	std::string temp;
	getline(std::cin, temp);
	index = std::atoi(temp.c_str());
	if (index < 1 || index > 8 || index > _nbr)
	{
		std::cout << "invalid index" << std::endl;
		return;
	}
	std::cout << "First Name    : "	<< book[index - 1].getinfo(0) << "\n";
	std::cout << "Last Name     : "	<< book[index - 1].getinfo(1) << "\n";
	std::cout << "Nickname      : "	<< book[index - 1].getinfo(2) << "\n";
	std::cout << "Phone Number  : "	<< book[index - 1].getinfo(3) << "\n";
	std::cout << "Darkest Secret: "	<< book[index - 1].getinfo(4) << "\n" << std::endl;
	return ;
}

int	phonebook::getnbr(void) const
{
	return _nbr;
}

void	phonebook::setnbr(int nbr)
{
	_nbr = nbr;
}
