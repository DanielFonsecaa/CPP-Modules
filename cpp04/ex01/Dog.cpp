#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor" << std::endl;
	_type = "Dog";
}

Dog::Dog(std::string type) : Animal(type){
	std::cout << "Dog Name constructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Dog assignation operator" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Woof Woof bitch" << std::endl;
}
