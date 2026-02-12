#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

static void run_one(const std::string& s)
{
	std::cout << "\n============================\n";
	std::cout << "INPUT: \"" << s << "\"\n";
	std::cout << "============================\n";
	ScalarConverter::convert(s);
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		run_one(argv[1]);
		return 0;
	}

	// No args: run a small test suite
	const std::string tests[] = {
		"a", "Z", "0", "9",
		"42", "-42", "+42",
		"2147483647", "2147483648", "-2147483649",
		"4.2", "-0.0", "0.0",
		"4.2f", "-0.0f", "0.0f",
		"+inf", "-inf", "+inff", "-inff", "nan", "nanf",
		"12..3", ".3", "3.", "0.f", "0.0ff", "0.0f0",
		"--42", "42-", "+-3"
	};

	for(size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
		run_one(tests[i]);

	std::cout << "\nUsage:\n  ./convert <literal>\n";
	return 0;
}