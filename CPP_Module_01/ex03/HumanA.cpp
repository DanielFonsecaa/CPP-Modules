#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : name(name), weapon(w) {}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

std::string	HumanA::getWeapon()
{
	return this->weapon.getType();
}

void	HumanA::setName(std::string name)
{
	this->name = name;
}

std::string HumanA::getName()
{
	return this->name;
}
