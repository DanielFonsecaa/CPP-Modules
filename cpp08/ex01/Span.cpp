#include "Span.hpp"

Span::Span() : size(0) {}

Span::Span(unsigned int num) : size(num) {}

Span::~Span(){
}

Span::Span(const Span &other) : size(other.size){
	for (size_t i = 0; i < other.container.size(); i++)
		container[i] = other.container[i];
}

Span &Span::operator=(const Span &other){
	if (this != &other)
	{
		this->size = other.size;
		for (size_t i = 0; i < other.container.size(); i++)
			container[i] = other.container[i];
	}
	return *this;
}

int Span::getSize(){
	return (size);
}

int Span::shortestSpan()
{
	if (container.size() < 2)
		throw numOfIntegersToLow();
	std::vector<int> copy = container;
	std::sort(copy.begin(), copy.end());

	std::vector<int> differences(copy.size());
	std::adjacent_difference(copy.begin(), copy.end(), differences.begin());
	int span = *std::min_element(differences.begin() + 1, differences.end());
	return span;
}

int Span::longestSpan()
{
	if (container.size() < 2)
		throw numOfIntegersToLow();
	int min = *std::min_element(container.begin(), container.end());
	int max = *std::max_element(container.begin(), container.end());
	return max - min;
}

void Span::addNumber(unsigned int num)
{
	if (container.size() >= size)
		throw maxNumOfIntegers();
	container.push_back(num);
}

void Span::addRandomNumbers(unsigned int quantity)
{
	if (container.size() + quantity > size)
		throw maxNumOfIntegers();
	container.reserve(container.size() + quantity);

	for (unsigned int i = 0; i < quantity; i++)
		container.push_back(rand());
}

const char* Span::maxNumOfIntegers::what() const throw() {
	return "ERROR. Maximum of numbers reached\nCannot add more\n\n";
}
const char* Span::numOfIntegersToLow::what() const throw() {
	return "ERROR. Number integers inside container is too low\nCannot find span\n\n";
}
