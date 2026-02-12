#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;
	public:

		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(AForm const &other);
		virtual ~AForm();

		AForm &operator=(AForm const &other);
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &bureaucrat) const = 0;
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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FileNotOpenedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &AForm);