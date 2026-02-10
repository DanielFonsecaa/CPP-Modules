#include <iostream>
#include <Array.hpp>

int main () {

	std::cout << "----INT ARRAYS----" << std::endl;
	std::cout << "\nCreating Arrays" << std::endl;
	std::cout << "Array1: ";
	Array<int> array1(10);
	std::cout << "Array2: ";
	Array<int> array2;
	std::cout << "Array3: ";
	Array<int> array3(0);

	std::cout << "\nPrint Array 1" << std::endl;
	for (unsigned int i = 0; i < array1.size(); i++)
	{
		std::cout << array1[i] << std::endl;
	}

	std::cout << "\nPrint Array 2" << std::endl;
	for (unsigned int i = 0; i <= array2.size(); i++)
	{
		try {
        	std::cout << array2[i] << std::endl;
    	} catch (ArrayNullException& e) {
        	std::cout << e.what() << std::endl;
    	} catch (std::exception& error) {
        	std::cout << error.what() << std::endl;
   		}
	}

	std::cout << "\nArray2 = Array1: ";
	array2 = array1;

	std::cout << "\nPrint Array 2" << std::endl;
	for (unsigned int i = 0; i < array2.size(); i++)
	{
		try {
			std::cout << array2[i] << std::endl;
		} catch (std::exception& error) {
			std::cout << error.what() << std::endl;
		}
	}

	std::cout << "\nEditing Array 1" << std::endl;
	for (unsigned int i = 0; i < array1.size(); i++)
	{
		try {
			array1[i] += 42; 
			std::cout << array1[i] << std::endl;
		} catch (std::exception& error) {
			std::cout << error.what() << std::endl;
		}
	}

	std::cout << "\nPrint Array 2 to check Assignment Operator" << std::endl;
	array2 = array1;
	for (unsigned int i = 0; i < array2.size(); i++)
	{
		try {
			std::cout << array2[i] << std::endl;
		} catch (std::exception& error) {
			std::cout << error.what() << std::endl;
		}
	}

	std::cout << "\nDeep Copy check (changed array1 value)" << std::endl;
	array1[1] = 1;
	std::cout << "Value of [1] in Array1: " << array1[1] << std::endl;
	for (unsigned int i = 0; i < array1.size(); i++)
	{
		std::cout << array1[i] << std::endl;
	}
	std::cout << "Value of [1] in Array2: " << array2[1] << std::endl;

	std::cout << "\n----STR ARRAYS----" << std::endl;
	std::cout << "\nCreating Array" << std::endl;
	Array<std::string> arrayStr1(4);

	std::cout << "\nEdit, Print and invalid index check" << std::endl;
	for (unsigned int i = 0; i <= arrayStr1.size(); i++)
	{
		try {
			arrayStr1[i] = "oi";
			std::cout << arrayStr1[i] << std::endl;
		} catch (std::exception& error) {
			std::cout << error.what() << std::endl;
		}
	}

	std::cout << "\nDestructors" << std::endl;
	return (0);
}