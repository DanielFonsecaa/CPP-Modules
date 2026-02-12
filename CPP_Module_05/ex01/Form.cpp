#include "Form.hpp"

Form::Form() : name("Form"), gradeToSign(150), gradeToExec(150){
	std::cout << "Form default constructor" << std::endl;
	isSigned = false;
}

Form::~Form(){
	std::cout << "Form destructor" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	std::cout << "Form name constructor" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
	isSigned = false;
}

Form::Form(const Form &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec){
	std::cout << "Form copy constructor" << std::endl;
	isSigned = other.isSigned;
}

Form &Form::operator=(const Form &other){
	std::cout << "Form copy assignment" << std::endl;
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return *this;
}

std::string Form::getName() const
{
	return name;
}

bool Form::getSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return (gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (gradeToExec);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	else if (isSigned)
		std::cout << "Form is already signed" << std::endl;
	else
	{
		isSigned = true;
		std::cout << this->getName() << " signed by " << bureaucrat.getName() << std::endl;
	}
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade too low";
}

std::ostream &operator<<(std::ostream &o, Form const &other)
{
	std::cout << "Form: " << other.getName() << " is " << (other.getSigned() ? "" : "not ") << "signed. Grade to sign: " << other.getGradeToSign() << ". Grade to execute: " << other.getGradeToExecute() << ".";
	return (o);
}