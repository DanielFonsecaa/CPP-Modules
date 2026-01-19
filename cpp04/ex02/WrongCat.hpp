#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat const &WrongCat);
		WrongCat &operator=(WrongCat const &WrongCat);
		virtual ~WrongCat();
		void makeSound() const;
};
