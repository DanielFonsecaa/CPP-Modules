#include "Zombie.hpp"

int main(void)
{
	Zombie a("zombie 1");
	a.annouce();
	Zombie *b = newZombie("zombie 2");
	b->annouce();
	randomChump("zombie 3");
	delete(b);
}
