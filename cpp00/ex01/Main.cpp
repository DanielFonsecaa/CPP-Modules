#include "includes/PhoneBook.hpp"

int main(void)
{
    PhoneBook p;
	std::string option;
	int choice;
	while (1)
	{
		std::cout << "type your option:" << std::endl;
		std::cout << "ADD" << std::endl;
		std::cout << "SEARCH" << std::endl;
		std::cout << "EXIT" << std::endl;
		std::getline(std::cin, option);
		if (std::cin.eof())
		{
			std::clearerr(stdin);
			std::cin.clear();
			return 0;
		}
		if (option.compare("ADD") == 0)
			choice = 1;
		else if (option.compare("SEARCH") == 0)
			choice = 2;
		else if (option.compare("EXIT") == 0)
			choice = 3;
		else
		{
			std::cout << RR << "\nPlease type ADD, SEARCH or EXIT\n" << RST << std::endl;
			continue ;
		}	
		switch (choice)
		{
		case 1:
			p.addContact();
			break;
		case 2:
			p.searchContact();
			break;
		case 3:
			std::cout << BB << "\nGood bye\n" << RST << std::endl;
			return (0);
		default:
			break;
		}
	}
    return 0;
}