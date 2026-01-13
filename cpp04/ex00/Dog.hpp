#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(std::string name);
		Dog(Dog const &Dog);
		Dog &operator=(Dog const &Dog);
		~Dog();
		void makeSound() const;
};
