#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:

	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const& cpy);
	~FragTrap();

	FragTrap& operator=(FragTrap const &rhs);

	void highFivesGuys() const;
};

#endif