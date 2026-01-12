#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "Default  Diamond Constructor called!" << std::endl;
	_name = "Default";
	_energyPoints = 10;
	_hitPoints = 10;
	_attackDamage = 0;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
	std::cout << "Diamond Name Constructor" << std::endl;
	this->_name = name;
	_energyPoints = 10;
	_hitPoints = 10;
	_attackDamage = 0;
	ClapTrap::_name = name + "_clap_name";

}

DiamondTrap::~DiamondTrap (){
	std::cout << "disclap the Diamond" << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "copy contructor Diamond" << std::endl;
	*this = other;
};

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
	std::cout << "Copy assignment Diamond" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	return *this;
};

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->_name << " and my clap name is " << this->_name << std::endl;
}

