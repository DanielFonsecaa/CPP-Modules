#include "includes/Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void    Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void    Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void    Contact::setNickName(std::string nickName)
{
    this->nickName = nickName;
}

void    Contact::setDark(std::string dark)
{
    this->dark = dark;
}

void    Contact::setNumber(std::string number)
{
    this->number = number;
}

std::string Contact::getFirstName()
{
    return this->firstName;
}

std::string    Contact::getLastName()
{
    return this->lastName;
}

std::string    Contact::getNickName()
{
    return this->nickName;
}