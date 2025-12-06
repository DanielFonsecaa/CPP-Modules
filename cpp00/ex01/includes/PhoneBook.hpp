#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include "Contact.hpp"
#include <cstdlib>

//colors
#define R "\033[0;31m" //RED
#define RST "\033[0m" //RESET
#define G "\033[0;32m"   // GREEN
#define B "\033[0;34m"   // BLUE
#define RR "\033[1;31m" //BOLD RED
#define GG "\033[1;32m"   // BOLD GREEN
#define BB "\033[1;34m"   // BOLD BLUE

class PhoneBook {
    public :
        PhoneBook();
        ~PhoneBook();
        void addContact();
        void searchContact();
        bool is_digit(std::string number);
        std::string trunc(std::string str);
    private :
        Contact contacts[8];
        int numContacts;
        int maxContacts;
};