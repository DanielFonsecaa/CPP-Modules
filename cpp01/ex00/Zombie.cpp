#include "Zombie.hpp"

Zombie::Zombie(std::string _name) : name(_name) {};
Zombie::~Zombie() {	
	std::cout << this->name << " got shot" << std::endl;
};

void    Zombie::annouce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
