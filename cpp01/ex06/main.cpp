#include "Harl.hpp"

int main(int argc, char **argv){
	Harl harl;

	if(argc == 1)
	{
		std::cout << "Usage: ./harl [debug/info/warning/error]" << std::endl;
		return 1;
	}
	else
		harl.complain(argv[1]);
	return 0;
}