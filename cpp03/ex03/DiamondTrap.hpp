#pragma once
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap();                            // 1. Default constructor
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);       // 2. Copy constructor
		DiamondTrap &operator=(const DiamondTrap &ther); // 3. Copy assignment
		~DiamondTrap();                         // 4. Destructor
		void whoAmI(void);
};
