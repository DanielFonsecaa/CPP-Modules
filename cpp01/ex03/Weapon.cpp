#include "Weapon.hpp"

Weapon::Weapon(std::string name) : type(name) {}
Weapon::~Weapon() {}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

std::string Weapon::getType()
{
	return this->type;
}
