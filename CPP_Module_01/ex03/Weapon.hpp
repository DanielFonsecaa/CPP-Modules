#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

class Weapon{
	public:
		Weapon(std::string type);
		~Weapon();
		void setType(std::string type);
		std::string getType();
	private:
		std::string type;
};