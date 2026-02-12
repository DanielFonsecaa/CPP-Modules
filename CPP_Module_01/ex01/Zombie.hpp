#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

class Zombie {
	public:
	Zombie();
	~Zombie();
	void	annouce(void);
	void	setName(std::string name);
	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name);
