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
		int lastA = (indexA + 1) * size - 1;  // Last element of pair A
		int lastB = (indexB + 1) * size - 1;  // Last element of pair B
		return container[lastA] < container[lastB];
	}
};

// Ford-Johnson merge-insert sort for any random-access container (vector/deque)
template <typename T>
void fordJohnsonSort(T &container, int pairSize)
{
	int pairCount = static_cast<int>(container.size()) / pairSize;
	if (pairCount < 2)
		return;
	bool isOdd = (pairCount % 2) == 1;
	int workPairs = pairCount - isOdd;

	// Phase 1: Compare adjacent pairs and swap if right < left
	for (int i = 0; i < workPairs; i += 2)
	{
		int lastLeft = getLastPair(container, i, pairSize);
		int lastRight = getLastPair(container, i + 1, pairSize);
		if (lastRight < lastLeft)
			swapPair(container, i, pairSize);
	}

	// Phase 2: Recursively sort pairs at the next level (pair size doubles)
	fordJohnsonSort(container, pairSize * 2);

	std::vector<int> main;
	std::vector<int> pend;
	main.reserve(pairCount);
	pend.reserve(pairCount);

	// Start main chain with the first two sorted pairs
	main.push_back(0);
	main.push_back(1);

	// Distribute remaining pairs: evens to pend, odds to main
	for (int i = 2; i < pairCount - isOdd; i++)
		(i % 2 == 0 ? pend : main).push_back(i);

	if (isOdd)
		pend.push_back(pairCount - 1);

	PairComparator<T> comp(container, pairSize);
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

		for (int j = 0; j < differenceJacobs; j++)
		{
			int searchLimit = currJacob + numbersInserted - boundaryHits;
			typename std::vector<int>::iterator pos = std::upper_bound(
				main.begin(), main.begin() + searchLimit, pend[pendIndex], comp);

			int insertPosition = static_cast<int>(pos - main.begin());
			if (insertPosition == searchLimit)
				boundaryHits++;

			main.insert(pos, pend[pendIndex]);
			pendIndex--;
		}

		pend.erase(pend.begin(), pend.begin() + differenceJacobs);
		prevJacob = currJacob;
		numbersInserted += differenceJacobs;
	}

	// Insert any remaining pend elements
	for (int i = static_cast<int>(pend.size()) - 1; i >= 0; i--)
	{
		int searchLimit = static_cast<int>(main.size() - pend.size()) + i + (isOdd ? 1 : 0);
		typename std::vector<int>::iterator pos = std::upper_bound(
			main.begin(), main.begin() + searchLimit, pend[i], comp);
		main.insert(pos, pend[i]);
	}

	// Rebuild the final sorted sequence by copying pairs in 'main' order
	T temp;
	temp.resize(container.size());
	T rebuilt;
	rebuilt.reserve(container.size());

	for (size_t i = 0; i < main.size(); ++i)
	{
		size_t pairStart = static_cast<size_t>(main[i]) * pairSize;
		size_t end = std::min(pairStart + static_cast<size_t>(pairSize), container.size());
		for (size_t idx = pairStart; idx < end; ++idx)
			rebuilt.push_back(container[idx]);
	}

	container.assign(rebuilt.begin(), rebuilt.end());
}