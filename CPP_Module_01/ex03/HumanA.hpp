#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

#include "Weapon.hpp"

class HumanA{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		std::string getName();
		void setName(std::string name);
		std::string getWeapon();
		void attack();
	private:
		std::string name;
		Weapon& weapon;
};