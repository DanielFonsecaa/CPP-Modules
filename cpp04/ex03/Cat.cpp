#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat(){
	std::cout << "Cat destructor" << std::endl;
	delete _brain;
}
Cat::Cat(std::string type) : Animal(type){
	std::cout << "Cat Name constructor" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Cat assignation operator" << std::endl;
	if (this != &other)
	{
		delete _brain;
		_brain = new Brain(*other._brain);
		_type = other._type;
	}
	return *this;
}

void Cat::makeSound() const{
	std::cout << "Miau Miau Bitch-nyan" << std::endl;
}

Brain *Cat::getBrain() const
{
	return _brain;
}
