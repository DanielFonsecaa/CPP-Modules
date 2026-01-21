#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class Intern{
	public:
		Intern();
		Intern(Intern const &Intern);
		Intern &operator=(Intern const &Intern);
		~Intern();

		AForm *makeForm(std::string const &formName, std::string const &target);
};

std::ostream &operator<<(std::ostream &out, Intern const &);