#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat{
	protected:
		std::string const name;
		int	grade;
		void setGrade(int grade);
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &Bureaucrat);
		Bureaucrat &operator=(Bureaucrat const &Bureaucrat);
		~Bureaucrat();
		std::string const &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);