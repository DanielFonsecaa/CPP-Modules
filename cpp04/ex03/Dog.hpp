#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(std::string name);
		Dog(Dog const &Dog);
		Dog &operator=(Dog const &Dog);
		~Dog();
		void makeSound() const;
		Brain *getBrain() const;
};
