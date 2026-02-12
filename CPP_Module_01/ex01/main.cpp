#include "Zombie.hpp"

int main(void)
{
	int input = 100;
	std::string name = "daniel";
	Zombie *h = zombieHorde(input, name);
	for(int i = 0; i < input; i++)
		h[i].annouce();
	delete[] h;
	return 0;
}