#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150){
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(150){
	std::cout << "Bureaucrat Name constructor" << std::endl;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
	std::cout << "Bureaucrat copy constructor" << std::endl;
	setGrade(other.grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	std::cout << "Bureaucrat copy assignment" << std::endl;
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

std::string const &Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::setGrade(int value)
{
	if (value < 1)
		throw GradeTooHighException();
	if (value > 150)
		throw GradeTooLowException();
	grade = value;
}

void Bureaucrat::decrementGrade()
{
	setGrade(grade + 1);
}

void Bureaucrat::incrementGrade()
{
	setGrade(grade - 1);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}