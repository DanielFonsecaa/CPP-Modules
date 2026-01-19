#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << "WrongCat default constructor" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other){
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
	std::cout << "WrongCat assignation operator" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "Wrong Wrong Miau Miau Bitch-nyan" << std::endl;
}