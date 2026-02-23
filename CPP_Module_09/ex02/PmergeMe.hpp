#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <algorithm>
#include <vector>
#include <deque>

class PmergeMe {
	private:
	public:
		std::vector<int> vec;
		std::deque<int> deq;
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		void run(int argc, char **argv);
		void mergeInsert(void);
		void fordJohnsonVector();
		void fordJohnsonDeque();

		class InvalidArgument : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

/*
template< typename T >
void sort(T &x) {
	if (x.size() <= 1)
		return;
	
	size_t mid = x.size() / 2;
	
	T left(x.begin(), x.begin() + mid);
	T right(x.begin() + mid, x.end());

	sort(left);
	sort(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), x.begin());
}
*/