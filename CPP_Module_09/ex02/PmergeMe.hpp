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
		void fordJohnsonVector(std::vector<int> &vector, int pairSize);
		void fordJohnsonDeque(std::deque<int> &vector, int pairSize);

		class InvalidArgument : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

int jacobsthal(int n);

// Returns the last element of a pair at the given index
template <typename T>
int getLastPair(const T& container, int index, int size)
{
	return container[index * size + size - 1];
}

// Swaps two adjacent pairs
template <typename T>
void swapPair(T& container, int index, int size)
{
	int start1 = index * size;
	int start2 = (index + 1) * size;
	
	for (int i = 0; i < size; i++)
		std::swap(container[start1 + i], container[start2 + i]);
}

// Comparator for comparing pairs by their last element
template <typename T>
struct PairComparator
{
	const T& container;
	int size;
	
	PairComparator(const T& cont, int sz) : container(cont), size(sz) {}
	
	bool operator()(int indexA, int indexB) const {
		int lastA = (indexA + 1) * size - 1;
		int lastB = (indexB + 1) * size - 1;
		return container[lastA] < container[lastB];
	}
};

template <typename T, typename L>
void helperJohnson(T &main, T &pend, const L &comp){
	int prevJacob = jacobsthal(1);
	int numbersInserted = 0;
	for (int k = 2; ; k++)
	{
		int currJacob = jacobsthal(k);
		int differenceJacobs = currJacob - prevJacob;
		if (differenceJacobs > static_cast<int>(pend.size()))
			break;
		int boundaryHits = 0;
		int pendIndex = differenceJacobs - 1;
		// Insert pend elements using binary search
		for (int j = 0; j < differenceJacobs; j++)
		{
			int searchLimit = currJacob + numbersInserted - boundaryHits;
			typename T::iterator pos = std::upper_bound(
				main.begin(), main.begin() + searchLimit, pend[pendIndex], comp);

			int insertPosition = pos - main.begin();
			if (insertPosition == searchLimit)
				boundaryHits++;

			main.insert(pos, pend[pendIndex]);
			pendIndex--;
		}
		// Remove processed elements from pend and update counters
		pend.erase(pend.begin(), pend.begin() + differenceJacobs);
		prevJacob = currJacob;
		numbersInserted += differenceJacobs;
	}
};