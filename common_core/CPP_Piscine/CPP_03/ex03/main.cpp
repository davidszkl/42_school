#include "DiamondTrap.hpp"

int main()
{
	ClapTrap Clap("Clap");
	ScavTrap Scav("Scav");
	FragTrap Frag("Frag");
	DiamondTrap Diamond("Diamond");

	std::cout << "ClapTrap:-----"<< std::endl;
	std::cout << "Name: "	<< Clap.getName()	<< std::endl;
	std::cout << "HP: "		<< Clap.getHP()		<< std::endl;
	std::cout << "EP: "		<< Clap.getEP()		<< std::endl;
	std::cout << "ATT: "	<< Clap.getATT()	<< std::endl << std::endl;
	Clap.attack("ClapTarget");
	Clap.takeDamage(10);
	Clap.beRepaired(10);

	std::cout << "ScavTrap:-----"<< std::endl;
	std::cout << "Name: "	<< Scav.getName()	<< std::endl;
	std::cout << "HP: "		<< Scav.getHP()		<< std::endl;
	std::cout << "EP: "		<< Scav.getEP()		<< std::endl;
	std::cout << "ATT: "	<< Scav.getATT()	<< std::endl << std::endl;
	Scav.attack("ScavTarget");
	Scav.takeDamage(10);
	Scav.beRepaired(10);
	Scav.guardGate();

	std::cout << "FragTrap-----:"<< std::endl;
	std::cout << "Name: "	<< Frag.getName()	<< std::endl;
	std::cout << "HP: "		<< Frag.getHP()		<< std::endl;
	std::cout << "EP: "		<< Frag.getEP()		<< std::endl;
	std::cout << "ATT: "	<< Frag.getATT()	<< std::endl << std::endl;
	Frag.attack("FragTarget");
	Frag.takeDamage(10);
	Frag.beRepaired(10);
	Frag.highFivesGuys();

	std::cout << "DiamondTrap-----:"<< std::endl;
	Diamond.whoAmI();
	std::cout << "HP: "		<< Diamond.getHP()		<< std::endl;
	std::cout << "EP: "		<< Diamond.getEP()		<< std::endl;
	std::cout << "ATT: "	<< Diamond.getATT()		<< std::endl << std::endl;
	Diamond.attack("DiamondTarget");
	Diamond.takeDamage(10);
	Diamond.beRepaired(10);
	Diamond.guardGate();
	Diamond.highFivesGuys();

	std::cout << "TEST" << std::endl;
	DiamondTrap Diamond2 = DiamondTrap();
	std::cout << "NAME = " << Diamond2.getName() << std::endl;
	Diamond2 = Diamond;
	std::cout << "NAME AFTER = " << Diamond2.getName() << std::endl;

	return 0;
}