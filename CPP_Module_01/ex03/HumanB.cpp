#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	weapon = NULL;
}

HumanB::~HumanB() {}


void	HumanB::attack()
{
	if (!weapon)
		std::cout << name << " does not posses a weapon" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

std::string	HumanB::getWeapon()
{
	if (!weapon)
		return NULL;
	return this->weapon->getType();
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::setName(std::string name)
{
	this->name = name;
}

std::string HumanB::getName()
{
	return this->name;
}
