#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public:
		FragTrap();                            // 1. Default constructor
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);       // 2. Copy constructor
		FragTrap &operator=(const FragTrap &ther); // 3. Copy assignment
		~FragTrap();                         // 4. Destructor
		void attack(const std::string &target);
		void highFivesGuys(void);
};
