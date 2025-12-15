#include "Zombie.hpp"

int main(void)
{
	std::string name;
	int input = 0;

	std::cout << "Enter the name of the zombies:" << std::endl;
	std::cin >> name;
	while(!std::cin.eof())
	{
		std::cout << "Enter the number of zombies between 0 and 100:";
		std::cin >> input;
		if(std::cin.fail() || input <= 0 || input > 100){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please try again." << std::endl;
		}
		else
			break;
	}

	if (std::cin.eof())
		return 0;
	Zombie *h = zombieHorde(input, name);
	for(int i = 0; i < input; i++)
		h[i].annouce();
	delete[] h;
	return 0;
}