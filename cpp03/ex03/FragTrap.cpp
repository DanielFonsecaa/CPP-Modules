#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "Default Constructor called!" << std::endl;
	_name = "Default";
	_energyPoints = 10;
	_hitPoints = 10;
	_attackDamage = 0;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
	std::cout << "Frag Name Constructor" << std::endl;
	_energyPoints = 10;
	_hitPoints = 10;
	_attackDamage = 0;
}

FragTrap::~FragTrap (){
	std::cout << "disclap the Frag" << std::endl;
};

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){
	std::cout << "copy contructor Frag" << std::endl;
	*this = other;
};

FragTrap &FragTrap::operator=(const FragTrap &other){
	std::cout << "Copy assignment Frag" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	return *this;
};

void FragTrap::highFivesGuys(void)
{
	std::cout << "I REQUEST THE HIGHEST OF FIVES" << std::endl;
}

