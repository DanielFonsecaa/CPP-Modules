#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal default constructor" << std::endl;
	_type = "AAnimal";
}

AAnimal::AAnimal(std::string type) : _type(type){
	std::cout << "AAnimal Name constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other){
	std::cout << "AAnimal copy constructor" << std::endl;
	*this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other){
	std::cout << "AAnimal assignation operator" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor" << std::endl;
}

void AAnimal::makeSound() const{
	std::cout << "AAnimal is making sound" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->_type;
}