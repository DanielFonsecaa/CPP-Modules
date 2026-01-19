#pragma once
#include <string>
#include <iostream>

class AAnimal{
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal const &AAnimal);
		AAnimal &operator=(AAnimal const &AAnimal);
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		std::string getType() const;
};
