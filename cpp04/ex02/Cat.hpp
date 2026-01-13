#pragma once
#include <string>
#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(std::string name);
		Cat(Cat const &Cat);
		Cat &operator=(Cat const &Cat);
		~Cat();
		void makeSound() const;
		Brain *getBrain() const;
};
