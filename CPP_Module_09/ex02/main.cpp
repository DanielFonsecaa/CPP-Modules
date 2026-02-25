#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::runtime_error("Usage: ./PmergeMe '<positive sequence of unsorted numbers>'");
		PmergeMe pm;
		pm.run(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
};