#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const& cpy);
	~ScavTrap();

	ScavTrap& operator=(ScavTrap const &rhs);

	void guardGate() const;
};

#endif