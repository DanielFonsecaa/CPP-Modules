#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>{
	public :
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack &other) : std::stack<T>(other) {};
		MutantStack &operator=(const MutantStack &other){
			if (this != other)
				std::stack<T>::operator=(other);
			return *this;
		};

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};