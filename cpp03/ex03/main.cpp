#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << std::endl << "ClapTrap tests:" << std::endl;
	{
		std::cout << std::endl << "-----FIRST TEST-----" << std::endl;
		ScavTrap scavtrap("Armindo");
		FragTrap fragtrap("Clotilde");
		DiamondTrap diamondtrap("Diamantino");
		scavtrap.guardGate();
		fragtrap.highFivesGuys();
		diamondtrap.whoAmI();
	}
	{
		std::cout << std::endl << "-----SECOND TEST-----" << std::endl;
		ClapTrap claptrap("Emilio");
		DiamondTrap diamondtrap("Diamantino");
		claptrap.attack("Diamantino");
		diamondtrap.takeDamage(0);
		diamondtrap.attack("Emilio");
		claptrap.takeDamage(0);
		diamondtrap.whoAmI();
		diamondtrap.guardGate();
		diamondtrap.highFivesGuys();
	}
	return 0;
}