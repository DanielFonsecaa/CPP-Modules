#pragma once
#include <string>
#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(std::string name);
		WrongCat(WrongCat const &WrongCat);
		WrongCat &operator=(WrongCat const &WrongCat);
		~WrongCat();
		void makeSound() const;
};
