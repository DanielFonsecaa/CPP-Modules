#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor" << std::endl;
	_type = "Animal";
}

Animal::Animal(std::string type) : _type(type){
	std::cout << "Animal Name constructor" << std::endl;
}

Animal::Animal(const Animal &other){
	std::cout << "Animal copy constructor" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other){
	std::cout << "Animal assignation operator" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal destructor" << std::endl;
}

void Animal::makeSound() const{
	std::cout << "Animal is making sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}