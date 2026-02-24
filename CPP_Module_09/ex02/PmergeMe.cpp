#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other){
	if (this != &other){
		vec = other.vec;
		deq = other.deq;
	}
	return *this;
}

void PmergeMe::run(int argc, char **argv){
	for(int i = 1; i < argc; i++){
		std::istringstream iss(argv[i]);
		std::string token;
		//validate each argument
		while (iss >> token){
			bool isValid = true;
			for( int j = 0; j < token.size(); j++){
				if (std::isdigit(token[j])){
					isValid = false;
					break;
				}
			}
			if (!isValid)
				throw InvalidArgument();
			int num;
			std::stringstream ss(token);
			ss >> num;
			if (ss.fail() || num < 0)
				throw InvalidArgument();
			deq.push_back(num);
			vec.push_back(num);
		}
	}
	mergeInsert();
};

void print(int num) {
	std::cout << num << " ";
}

void PmergeMe::mergeInsert(){

	//print vector
	std::cout << "Before: ";
	std::for_each(vec.begin(), vec.end(), print);
	std::cout << std::endl;
	//calculate deque time
	clock_t deq_start = clock();
	fordJohnsonDeque(deq, 1); //todo
	clock_t deq_end = clock();
	//calculate vector time
	clock_t vec_start = clock();
	fordJohnsonVector(vec, 1); //todo
	clock_t vec_end = clock();
	
	std::cout << "After: ";
	std::for_each(vec.begin(), vec.end(), print);
	std::cout << std::endl;

	std::cout << "Time to process a range of ";
	std::cout << deq.size();
	std::cout << " elements with std::deque : " ;
	std::cout << (double)(deq_end - deq_start) * 100000 / CLOCKS_PER_SEC << "us" << std::endl;

	std::cout << "Time to process a range of ";
	std::cout << vec.size();
	std::cout << " elements with std::vector : " ;
	std::cout << (double)(vec_end - vec_start) * 100000 / CLOCKS_PER_SEC << "us" << std::endl;
};

// Computes the n-th Jacobsthal number using dynamic programming.
// Formula: J(n) = J(n-1) + 2*J(n-2)
// @param n: The index of the Jacobsthal number to compute (n >= 1)
// @return: The n-th Jacobsthal number
int jacobsthal(int n)
{
	int a = 1, b = 3;  //initial values
	for (int i = 2; i <= n; i++)
	{
		int temp = b;
		b = b + 2 * a;  // J(i) = J(i-1) + 2*J(i-2)
		a = temp;
	}
	return a;  // Return J(n)
}

void PmergeMe::fordJohnsonVector(std::vector<int> &vector, int pairSize){
	// Calculate how many pairs exist at this recursion level
	int pairCount = vector.size() / pairSize;
	if (pairCount < 2)
		return;
	bool isOdd = pairCount % 2 == 1;
	// Number of pairs we can process (excluding the odd one)
	int workPairs = pairCount - isOdd;
	// Phase 1: Compare adjacent pairs and swap if right < left
	// This ensures the larger element of each pair is in the right position
	for(int i = 0; i < workPairs; i += 2){
		int lastLeft = getLastPair(vector, i, pairSize);
		int rightLeft = getLastPair(vector, i + 1, pairSize);
		if (rightLeft < lastLeft)
			swapPair(vector, i, pairSize);
	}
	// Phase 2: Recursively sort pairs at the next level (pair size doubles)
	fordJohnsonVector(vector, pairSize * 2);

	std::vector<int> main;
	std::vector<int> pend;
	// Reserve to avoid reallocations while inserting
	main.reserve(pairCount);
	pend.reserve(pairCount);
	// Start main chain with the first two sorted pairs
	main.push_back(0);
	main.push_back(1);
	// Distribute remaining pairs: evens to pend, odds to main
	// The main is initialised with the elements {b1, a1} and then with the rest of as.
	// The pend is initialised with the rest of bs starting from b2
	for (int i = 2; i < pairCount - isOdd; i++)
		(i % 2 == 0 ? pend : main).push_back(i);
	// If there's an unpaired last pair, add it to pend
	if (isOdd)
		pend.push_back(pairCount - 1);
	// Comparator for comparing pair indices by last element
	PairComparator< std::vector<int> > comp(vector, pairSize);
	// Jacobsthal insertion of pend into main
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
			std::vector<int>::iterator pos = std::upper_bound(
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
	// Insert any remaining pend elements
	// Process from the end to preserve the intended insertion order
	for (int i = static_cast<int>(pend.size()) - 1; i >= 0; i--)
	{
		// Bound the search to the already-sorted prefix of main
		int searchLimit = main.size() - pend.size() + i + isOdd;
		std::vector<int>::iterator pos = std::upper_bound(
			main.begin(), main.begin() + searchLimit, pend[i], comp);
		main.insert(pos, pend[i]);
	}
	// Rebuild the final sorted sequence by copying pairs in 'main' order
	std::vector<int> temp;
	temp.reserve(vector.size());
	for (size_t i = 0; i < main.size(); ++i)
	{
		size_t pairStart = static_cast<size_t>(main[i]) * pairSize;
		size_t end = std::min(pairStart + pairSize, vector.size());
		for (size_t idx = pairStart; idx < end; ++idx)
			temp.push_back(vector[idx]);
	}
	// Copy the rebuilt order back into the original vector
	vector.assign(temp.begin(), temp.end());
};

void PmergeMe::fordJohnsonDeque(std::deque<int> &deque, int pairSize){}