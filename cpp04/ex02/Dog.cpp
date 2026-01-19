#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"){
	std::cout << "Dog default constructor" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog(){
	std::cout << "Dog destructor" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &other) : AAnimal(other) {
	std::cout << "Dog copy constructor" << std::endl;
	_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Dog assignation operator" << std::endl;
	if (this != &other)
	{
		delete _brain;
		_brain = new Brain(*other._brain);
		_type = other._type;
	}
	return *this;
}

void Dog::makeSound() const{
	std::cout << "Woof Woof bitch" << std::endl;
}

Brain *Dog::getBrain() const
{
	return _brain;
}