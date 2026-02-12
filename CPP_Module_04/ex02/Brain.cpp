#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain destructor" << std::endl;
}

Brain::Brain(const Brain &other){
	std::cout << "Brain copy constructor" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other){
	std::cout << "Brain assignation operator" << std::endl;
	if (this != &other)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cerr << "Error: Index out of bounds (0-99)" << std::endl;
		return "";
	}
	return ideas[index];
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
	{
		std::cerr << "Error: Index out of bounds (0-99)" << std::endl;
		return;
	}
	ideas[index] = idea;
}
