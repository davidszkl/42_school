#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
public:

	HumanA(std::string name, Weapon& weapon);
	~HumanA();

	void	attack();
	Weapon&	getWeapon();

private:

	std::string _name;
	Weapon&		_Weapon;
};

#endif