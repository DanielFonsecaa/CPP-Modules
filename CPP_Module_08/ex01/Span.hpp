#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class maxNumOfIntegers : public std::exception{
	public :
		virtual const char *what() const throw(){
			return "ERROR. Maximum of numbers reached\nCannot add more\n\n";
		}
};

class Span{
	private:
		unsigned int size;
		std::vector<int> container;
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &src);
		Span &operator=(const Span &src);
		int getSize();
		int shortestSpan();
		int longestSpan();
		void addNumber(unsigned int num);
		void addRandomNumbers(unsigned int num);
		class maxNumOfIntegers : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class numOfIntegersToLow : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};