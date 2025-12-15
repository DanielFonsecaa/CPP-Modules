#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

#include "Weapon.hpp"

class HumanB{
	public:
		HumanB(std::string name);
		~HumanB();
		std::string getName();
		void setName(std::string name);
		std::string getWeapon();
		void setWeapon(Weapon &weapon);
		void attack();
	private:
		std::string name;
		Weapon *weapon;
};