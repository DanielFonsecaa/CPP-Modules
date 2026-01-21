#include "AForm.hpp"

AForm::AForm() : name("AForm"), gradeToSign(150), gradeToExec(150){
	std::cout << "AForm default constructor" << std::endl;
	isSigned = false;
}

AForm::~AForm(){
	std::cout << "AForm destructor" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	std::cout << "AForm name constructor" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
	isSigned = false;
}

AForm::AForm(const AForm &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec){
	std::cout << "AForm copy constructor" << std::endl;
	isSigned = other.isSigned;
}

AForm &AForm::operator=(const AForm &other){
	std::cout << "AForm copy assignment" << std::endl;
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return *this;
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (gradeToExec);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	else if (isSigned)
		std::cout << "AForm is already signed" << std::endl;
	else
	{
		isSigned = true;
		std::cout << this->getName() << " signed by " << bureaucrat.getName() << std::endl;
	}
}

void AForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (bureaucrat.getGrade() > gradeToExec)
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

const char* AForm::FileNotOpenedException::what() const throw() {
	return "File not opened";
}

const char* AForm::FormCreationException::what() const throw() {
	return "Form does not exist";
}

std::ostream &operator<<(std::ostream &out, AForm const &other)
{
	out << "Form: " << other.getName() << std::endl;
	out << "Signed: " << other.getSigned() << std::endl;
	out << "Grade to sign: " << other.getGradeToSign() << std::endl;
	out << "Grade to execute: " << other.getGradeToExecute() << std::endl;
	return out;
}