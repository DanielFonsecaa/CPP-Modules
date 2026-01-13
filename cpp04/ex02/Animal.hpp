#pragma once
#include <string>
#include <iostream>

class Animal{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &Animal);
		Animal &operator=(Animal const &Animal);
		virtual ~Animal();
		virtual void makeSound() const = 0;
		std::string getType() const;
};
