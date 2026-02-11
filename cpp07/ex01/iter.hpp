#pragma once
#include <iostream>

template <typename T,typename N>
void iter(T *arr, const int length, void (*f)(N &))
{
	if (!arr)
	{
		std::cerr << "Error - Null array pointer" << std::endl;
		return;
	}
	if (length < 1)
	{
		std::cerr << "Error - Array length must be bigger then 0." << std::endl;
		return;
	}
	for (int i = 0; i < length; i++)
		f(arr[i]);
}

//template <typename T>
//void iter(const T *arr, const int length, void (*f)(const T &))
//{
//	if (!arr)
//	{
//		std::cerr << "Error - Null array pointer" << std::endl;
//		return;
//	}
//	if (length < 1)
//	{
//		std::cerr << "Error - Array length must be bigger then 0." << std::endl;
//		return;
//	}
//	for (int i = 0; i < length; i++)
//		f(arr[i]);
//}