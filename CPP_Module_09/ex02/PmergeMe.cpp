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
	fordJohnsonDeque(); //todo
	clock_t deq_end = clock();
	//calculate vector time
	clock_t vec_start = clock();
	fordJohnsonVector(); //todo
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

void PmergeMe::fordJohnsonDeque(){}

void PmergeMe::fordJohnsonVector(){}