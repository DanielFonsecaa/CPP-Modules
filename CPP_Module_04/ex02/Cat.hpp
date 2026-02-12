#pragma once
#include <string>
#include <iostream>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(Cat const &Cat);
		Cat &operator=(Cat const &Cat);
		virtual ~Cat();
		void makeSound() const;
		Brain *getBrain() const;
};
