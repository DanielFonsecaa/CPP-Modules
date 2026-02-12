#include "Zombie.hpp"

Zombie::Zombie(){};
Zombie::~Zombie() {	
	std::cout << this->name << " got shot" << std::endl;
};

void    Zombie::annouce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}