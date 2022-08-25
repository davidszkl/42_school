#include "ClapTrap.hpp"

int main()
{
	ClapTrap Jeff = ClapTrap("Jeff");
	ClapTrap employee = ClapTrap("employee");
	ClapTrap Union = ClapTrap("Union");

	Jeff.attack(employee.getName());
	employee.takeDamage(Jeff.getATT());
	employee.beRepaired(10);
	return 0;
}