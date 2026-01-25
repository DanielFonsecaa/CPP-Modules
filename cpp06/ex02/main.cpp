#include "Base.hpp"

int main()
{
	std::srand(std::time(NULL));

	// Test multiple random generations
	for (int i = 0; i < 3; i++)
	{
		std::cout << "-------- TEST " << i + 1 << " --------\n";

		Base* p = Base::generate();

		std::cout << "identify(ptr): ";
		Base::identify(p);

		std::cout << "identify(ref): ";
		Base::identify(*p);

		delete p;
		std::cout << std::endl;
	}

	// Test NULL pointer case
	std::cout << "-------- NULL TEST --------\n";
	Base* nullPtr = NULL;
	std::cout << "identify(ptr): ";
	Base::identify(nullPtr);
	std::cout << "identify(ref): ";
	Base::identify(*nullPtr);

	return 0;
}
