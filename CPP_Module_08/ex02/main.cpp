#include "MutantStack.hpp"

int main()
{
	{
		std::cout << "Same as subject - \n" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n\nList indead os MutantStack - \n" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(mstack);
	}
	{
		std::cout << "\n\nOther tests:\n";
		std::cout << "Creating Stack\n";
		MutantStack<int> s;
		std::cout << "Testing if stack is empty: " << (s.empty() ? "True" : "False") << "\n";
		std::cout << "\nAdding 5 random numbers\n";
		for (int i = 0; i < 5; i++)
		{
			s.push(rand() % 10000);
			std::cout << "Added " << i+1 << "º number: " << s.top() << " to the stack" << std::endl;
		}
		std::cout << "Testing if stack is empty: " << (s.empty() ? "True" : "False") << "\n";
		std::cout << "\nIterators: \n";
		MutantStack<int>::iterator it = s.begin();
		MutantStack<int>::iterator ite = s.end();
		std::cout << "first element of the stack: " << *it << std::endl;
		std::cout << "last element of the stack: " << *(ite - 1) << std::endl;
		std::cout << "incrementing and decrementing iterators: \n";
		std::cout << "incrementing first element position \n";
		it++;
		std::cout << "new first element of the stack: " << *it << std::endl;
		std::cout << "decrementing last element position \n";
		ite--;
		std::cout << "new last element of the stack: " << *(ite - 1) << std::endl;
		it--;
		ite++;
		std::cout << "Reordering and pop elements\n";
		std::cout << "Before popping:\n";
		std::cout << "Stack size: " << s.size() <<"\n";
		int i = 0;
		while (it != ite)
		{
			std::cout << *it << " " << std::endl;
			++it;
			i++;
		}
		std::cout << "After popping:\n";
		s.pop();
		std::cout << "Stack size: " << s.size() <<"\n";
		it = s.begin();
		ite = s.end();
		i = 0;
		while (it != ite)
		{
			std::cout << *it << " " << std::endl;
			i++;
			++it;
		}
	}
	return 0;
}