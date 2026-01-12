#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &scavTrap);
		ScavTrap &operator=(ScavTrap const &scavTrap);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
};
