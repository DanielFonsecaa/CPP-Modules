#include "ClapTrap.hpp"

int main(){
	//Base ClapTrap
	std::cout << "First Test" << std::endl;
	{
		ClapTrap claptrap("Claptrap");

		claptrap.attack("Handsome Jack");
		claptrap.takeDamage(5);
		claptrap.beRepaired(3);
	}
	//ClapTrap with other name
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Second Test" << std::endl;
	{
		ClapTrap claptrap("Emilio");
		claptrap.attack("Handsome Jack");
		claptrap.takeDamage(9);
		claptrap.beRepaired(9);
	}
	//Energy
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Third Test" << std::endl;
	{
		ClapTrap claptrap("TrapClap");
		claptrap.attack("Handsome Jack");
		claptrap.attack("Handsome Jack");
		claptrap.attack("Handsome Jack");
		claptrap.attack("Handsome Jack");
		claptrap.attack("Handsome Jack");
		claptrap.beRepaired(10);
		claptrap.beRepaired(10);
		claptrap.beRepaired(10);
		claptrap.beRepaired(10);
		claptrap.beRepaired(10);
		//No energy
		claptrap.beRepaired(10);
		claptrap.attack("Handsome Jack");
	}
	//ClapTrap without name
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Fourth Test" << std::endl;
	{
		ClapTrap claptrap;
	}
	return 0;
}