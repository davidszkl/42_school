#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <iostream>

class ClapTrap
{
public:

	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(ClapTrap const &cpy);
	~ClapTrap();

	ClapTrap& operator=(ClapTrap const &rhs);

	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string getName()	const;
	int			getHP()		const;
	int			getEP()		const;
	int			getATT()	const;

private:

	std::string	_Name;
	int			_HP;
	int			_EP;
	int			_ATT;

};

#endif