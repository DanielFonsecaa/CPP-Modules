#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

class ClapTrap{
	protected:
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
		std::string _name;
	public:
	ClapTrap();                            // 1. Default constructor
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);       // 2. Copy constructor
	ClapTrap &operator=(const ClapTrap &ther); // 3. Copy assignment
	virtual ~ClapTrap();                         // 4. Destructor
	virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
