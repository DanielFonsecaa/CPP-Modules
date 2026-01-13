#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor" << std::endl;
	_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){
	std::cout << "WrongAnimal Name constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
	std::cout << "WrongAnimal copy constructor" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
	std::cout << "WrongAnimal assignation operator" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal is making sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}