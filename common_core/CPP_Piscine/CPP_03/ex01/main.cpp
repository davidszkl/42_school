#include "ScavTrap.hpp"

int main()
{
	// ClapTrap Jeff = ClapTrap("Jeff");
	// ClapTrap employee = ClapTrap("employee");
	// ClapTrap Union = ClapTrap("Union");
	ScavTrap Boris("Boris");

	// Jeff.attack(employee.getName());
	// employee.takeDamage(Jeff.getATT());
	// employee.beRepaired(10);

	Boris.attack("Jeff");
	Boris.guardGate();

	return 0;
}