#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor" << std::endl;
	_type = "Cat";
}

Cat::Cat(std::string type) : Animal(type){
	std::cout << "Cat Name constructor" << std::endl;
}

Cat::Cat(const Cat &other){
	std::cout << "Cat copy constructor" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Cat assignation operator" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Miau Miau Bitch-nyan" << std::endl;
}