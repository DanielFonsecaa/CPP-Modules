#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
	std::cout << std::endl << "ClapTrap tests:" << std::endl;
	{
		std::cout << std::endl << "-----FIRST TEST-----" << std::endl;
		ClapTrap claptrap("Emilio");
		ScavTrap scavtrap("Armindo");
		claptrap.attack("Armindo");
		scavtrap.takeDamage(0);
		scavtrap.attack("Emilio");
		claptrap.takeDamage(20);
		claptrap.beRepaired(20);
		scavtrap.guardGate();
	}
	{
		std::cout << std::endl << "-----SECOND TEST-----" << std::endl;
		ClapTrap claptrap("Soperman");
		ClapTrap claptrap2("Botman");
		ScavTrap scavtrap("Juker");
		claptrap.attack("Juker");
		scavtrap.takeDamage(0);
		claptrap2.attack("Juker");
		scavtrap.takeDamage(0);
		scavtrap.attack("Soperman");
		scavtrap.attack("Botman");
		scavtrap.guardGate();
		claptrap.takeDamage(20);
		claptrap2.takeDamage(20);
		claptrap.beRepaired(20);
		claptrap2.beRepaired(20);
	}
	return 0;
}