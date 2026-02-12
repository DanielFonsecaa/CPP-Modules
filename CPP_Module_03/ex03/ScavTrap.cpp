#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "ScavTrap default constructor" << std::endl;
	_name = "Default Scav";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "ScavTrap Name constructor" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap){
	std::cout << "ScavTrap copy constructor" << std::endl;
	*this = scavTrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap){
	std::cout << "ScavTrap assignation operator" << std::endl;
	if (this != &scavTrap)
	{
		_name = scavTrap._name;
		_hitPoints = scavTrap._hitPoints;
		_energyPoints = scavTrap._energyPoints;
		_attackDamage = scavTrap._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor" << std::endl;
}

void ScavTrap::attack(std::string const &target){
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "Scav " << _name << " cannot atack" << std::endl;
		return;
	}
	this->_energyPoints --;
	std::cout << "ScavTrap " << _name << " attacks " << target << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << _name << " has entered Gate keeper mode" << std::endl;
}