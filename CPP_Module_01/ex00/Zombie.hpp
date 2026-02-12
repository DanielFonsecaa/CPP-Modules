#pragma once
#include <iostream>
#include <iomanip>


class Zombie {
	public:
	Zombie(std::string name);
	~Zombie();
	void	annouce(void);
	private:
		std::string name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);