#pragma once
#include <string>
#include <iostream>

class WrongAnimal{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &WrongAnimal);
		WrongAnimal &operator=(WrongAnimal const &WrongAnimal);
		virtual ~WrongAnimal();
		virtual void makeSound() const;
		std::string getType() const;
};
