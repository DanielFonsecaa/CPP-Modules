#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
		std::string getTarget() const;
		static AForm *createRobotomyForm(std::string const &target);
		void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &RobotomyRequestForm);