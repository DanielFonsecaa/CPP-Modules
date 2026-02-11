#pragma once

#include <iostream>
#include <exception>
#include <algorithm>
#include <iterator>

class notFoundException : public std::exception{
	public :
		virtual const char *what() const throw(){
			return "ERROR. No Occurance was found\n";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(
		container.begin(), container.end(), value
	); //from, where, value to search
	if (it == container.end())
		throw notFoundException();
	return it;
}