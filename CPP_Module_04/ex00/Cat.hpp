#pragma once
#include <string>
#include <iostream>

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &Cat);
		Cat &operator=(Cat const &Cat);
		virtual ~Cat();
		void makeSound() const;
};
