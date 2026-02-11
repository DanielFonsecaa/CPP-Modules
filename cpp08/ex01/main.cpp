#include "Span.hpp"

int main()
{
	{
		std::cout << "\n----- Test 1: Adding more numbers than capacity -----\n" << std::endl;
		Span sp = Span(4);

		try {
			sp.addNumber(1);
			sp.addNumber(4);
			sp.addNumber(8);
			sp.addNumber(9);
			std::cout << "\nAdding another number...\n" << std::endl;
			sp.addNumber(15); // This should throw an exception
		} catch (const std::exception &e) {
			std::cout << e.what();
		}
	}
	{
		std::cout << "\n----- Test 2: Calculating Spans with insufficient numbers -----\n" << std::endl;
		Span sp = Span(3);

		try {
			sp.addNumber(5);
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what();
		}
	}
	{
		std::cout << "----- Test 3: Normal operation -----\n" << std::endl;

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\n----- Test 4: Adding random numbers -----\n" << std::endl;

		srand(time(NULL));
		Span sp = Span(10010);
		sp.addNumber(rand());
		sp.addNumber(rand());
		sp.addNumber(rand());
		sp.addRandomNumbers(10000);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	return 0;
}