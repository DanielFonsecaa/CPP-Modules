#pragma once
#include <iostream>
#include <iomanip>

class Contact {
    public :
        Contact();
        ~Contact();
        void setFirstName(std::string firstName);
        void setLastName(std::string lastName);
        void setNickName(std::string nickName);
        void setNumber(std::string number);
        void setDark(std::string dark);
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
    private :
        std::string firstName;
        std::string lastName;    
        std::string nickName;
        std::string dark;
        std::string number;
};