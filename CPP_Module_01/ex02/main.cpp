#include <iostream>
#include <string>
#include <iomanip>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memorie address of the string: " << &str << std::endl;
	std::cout << "Memorie address of the stringPTR: " << stringPTR << std::endl;
	std::cout << "Memorie address of the stringREF: " << &stringREF << std::endl;
	std::cout << "String: " << str << std::endl;
	std::cout << "StringPTR: " << *stringPTR << std::endl;
	std::cout << "StringREF: " << stringREF << std::endl;
}