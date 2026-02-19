#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{

	try
	{
		if (argc != 2)
			throw std::runtime_error("Error: invalid number of arguments. Usage: ./btc <input_file>");
		BitcoinEx bit;
		bit.process(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}