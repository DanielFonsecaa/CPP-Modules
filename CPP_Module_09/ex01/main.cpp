#include "Rpn.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::runtime_error("Usage: ./rpn '<input>'");
		Rpn rpn;
		int result = rpn.execute(argv[1]);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}