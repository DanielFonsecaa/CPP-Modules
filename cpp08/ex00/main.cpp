#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
	{
		std::vector<int>::iterator it;
		std::vector<int> container;
		for (int i = 0; i < 10; i++)
			container.push_back(i);
		try
		{
			it = easyfind(container, 5);
			std::cout << "Found : " << *it << std::endl;
			it = easyfind(container, 10);
			std::cout << "Found : " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    {
		std::list<int>::iterator it;
		std::list<int> container;
		container.push_back(137);
        container.push_back(598);
        container.push_back(942);
        container.push_back(0);
        container.push_back(-627);
        container.push_back(56);
        container.push_back(23);
		try
		{
			it = easyfind(container, 137);
			std::cout << "Found : " << *it << std::endl;
			it = easyfind(container, 100);
			std::cout << "Found : " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}