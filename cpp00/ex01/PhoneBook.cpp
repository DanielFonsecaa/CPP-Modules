#include "includes/PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->numContacts = 0;
    this->maxContacts = 0;
}

PhoneBook::~PhoneBook() {
}

void    PhoneBook::addContact()
{
    int pos = this->numContacts % 8;
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string number;
    std::string dark;
    
    std::cout << "Enter first name: " << std::endl;
    std::getline(std::cin, firstName);
    
    std::cout << "Enter last name: " << std::endl;
    std::getline(std::cin, lastName);
    
    std::cout << "Enter nickname: " << std::endl;
    std::getline(std::cin, nickName);
    std::cout << "Enter phone number: " << std::endl;
    std::getline(std::cin, number);
    while (!is_digit(number))
    {
        std::cout << RR << "\nIt was to be a valid number\n" << RST << std::endl;
        std::cout << "Enter phone number: " << std::endl;
        std::getline(std::cin, number);
    }
    std::cout << "Enter darkest secret: " << std::endl;
    std::getline(std::cin, dark);
    
    if (firstName.empty() || lastName.empty() || nickName.empty() || number.empty() || dark.empty())
    {
        std::cout << "Can not have empty values" << std::endl;
        return ;
    }    
    this->numContacts++;
    if (this->maxContacts < 8)
        this->maxContacts++;
    this->contacts[pos].setFirstName(firstName);
    this->contacts[pos].setLastName(lastName);
    this->contacts[pos].setNickName(nickName);
    this->contacts[pos].setNumber(number);
    this->contacts[pos].setDark(dark);
}

void    PhoneBook::searchContact()
{
    if (this->numContacts == 0)
    {
        std::cout << RR << "No contacts in your phone book" << RST << std::endl;
        std::cout << "Please, add someone to your frinds list\n" << std::endl;
        return ;
    }
    std::cout << std::setw(10) << "Index" << '|';
    std::cout << std::setw(10) << "First Name" << '|';
    std::cout << std::setw(10) << "Last Name" << '|';
    std::cout << std::setw(10) << "Nick Name" << '|' << std::endl;
    for (int i = 0; i < this->maxContacts; i++)
    {
        std::cout << std::setw(10) << i << '|';
        std::cout << std::setw(10) << trunc(contacts[i].getFirstName()) << '|';
        std::cout << std::setw(10) << trunc(contacts[i].getLastName()) << '|';
        std::cout << std::setw(10) << trunc(contacts[i].getNickName()) << '|' << std::endl;
    }
}

std::string    PhoneBook::trunc(std::string str)
{
    if (str.length() > 10)
        str = str.substr(0, 9) + '.';
    return str;
}

bool	PhoneBook::is_digit(std::string number)
{
	for (int i = 0; number[i]; i++)
	{
		if (!std::isdigit(number[i]))
			return false;
	}
	return true;
}
