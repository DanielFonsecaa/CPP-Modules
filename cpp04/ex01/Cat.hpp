#pragma once
#include <string>
#include <iostream>

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(std::string name);
		Cat(Cat const &Cat);
		Cat &operator=(Cat const &Cat);
		~Cat();
		void makeSound() const;
};
