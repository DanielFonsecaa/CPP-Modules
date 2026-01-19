#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(Dog const &Dog);
		Dog &operator=(Dog const &Dog);
		virtual ~Dog();
		void makeSound() const;
		Brain *getBrain() const;
};
