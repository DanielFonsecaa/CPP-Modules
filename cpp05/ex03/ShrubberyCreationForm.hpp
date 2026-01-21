#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
		std::string getTarget() const;
		static AForm *createShrubberyForm(std::string const &target);
		void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &ShrubberyCreationForm);