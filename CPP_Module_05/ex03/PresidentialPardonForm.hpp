#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
		std::string getTarget() const;
		static AForm *createPresidentialForm(std::string const &target);
		void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &PresidentialPardonForm);