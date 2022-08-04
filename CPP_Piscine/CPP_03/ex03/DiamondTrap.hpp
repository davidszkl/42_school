#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:

	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &cpy);
	~DiamondTrap();
		
	DiamondTrap& operator=(DiamondTrap const &rhs);

	void	whoAmI();

private:

	std::string	_Name;
};

#endif