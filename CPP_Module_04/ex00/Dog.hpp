#pragma once
#include <string>
#include <iostream>

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(Dog const &Dog);
		Dog &operator=(Dog const &Dog);
		virtual ~Dog();
		void makeSound() const;
};
