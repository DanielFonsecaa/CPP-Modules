#include "iter.hpp"

void print(const int &a)
{
	std::cout << a << ",";
}

void add(int &a)
{
	a += 1;
}

int main()
{
	int arr[] = {1, 2, 3};
	const int arr1[] = {4, 5, 6};

	std::cout << std::endl << "NORMAL ARRAY BEFORE: " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << arr[i] << ",";
	std::cout << std::endl;

	::iter(arr, 3, add);
	std::cout << std::endl << "NORMAL ARRAY AFTER: " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << arr[i] << ",";
	std::cout << std::endl;
	
	
	std::cout << std::endl << "CONST ARRAY BEFORE: " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << arr1[i] << ",";
	std::cout << std::endl;
	
	std::cout << std::endl << "CONST ARRAY AFTER: " << std::endl;
	::iter(arr1, 3, print);
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}