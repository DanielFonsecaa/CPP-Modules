#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
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
