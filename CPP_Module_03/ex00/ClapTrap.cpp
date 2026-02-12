#include "ClapTrap.hpp"


ClapTrap::ClapTrap(){
	std::cout << "ClapTrap" << this->_name << " is alive!" << std::endl;
	std::cout << "Default Constructor called!" << std::endl;
	_name = "Default";
	_energyPoints = 10;
	_hitPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) : _name(name) 
{
	std::cout << "clap clap Name Contructor" << std::endl;
	_energyPoints = 10;
	_hitPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap () {
	std::cout << "disclap the clap" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other){
	std::cout << "copy contructor" << std::endl;
	*this = other;
};

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	std::cout << "Copy assignment" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	return *this;
};

void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "Clap " << _name << " cannot atack" << std::endl;
		return;
	}
	this->_energyPoints --;
	std::cout << "Clap " << _name << " attacks " << target << " Causing " << this->_hitPoints << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << _name << " is already dead" << std::endl;
		return ;
	}
	if ((unsigned int)_hitPoints <= amount)
	{
		_hitPoints = 0;
		std::cout << _name << " has taken " << amount << " of damage and died" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << _name << " has taken " << amount << " of damage, having " << _hitPoints << " left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "Clap " << _name << " cannot be repaired" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << _name << " recovered " << amount << "of life" << std::endl;
	_hitPoints += amount;
}