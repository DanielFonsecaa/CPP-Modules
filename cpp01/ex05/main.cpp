#include "Harl.hpp"

int main(int argc, char **argv){
	Harl harl;

	if(argc == 1)
	{
		std::cout << "Usage: ./harl [DEBUG/INFO/WARNING/ERROR]" << std::endl;
		return 1;
	}
	else
		harl.complain(argv[1]);
	return 0;
}