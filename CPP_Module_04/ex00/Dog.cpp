#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog default constructor" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &other){
	std::cout << "Dog copy constructor" << std::endl;
	*this = other;
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
