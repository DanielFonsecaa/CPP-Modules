#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5){
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string targ) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm name constructor" << std::endl;
	target = targ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other){
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	std::cout << "PresidentialPardonForm copy assignment" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (target);
}

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const 
{
	AForm::execute(bureaucrat);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &other)
{
	out << "Form: " << other.getName() << std::endl;
	out << "Signed: " << other.getSigned() << std::endl;
	out << "Grade to sign: " << other.getGradeToSign() << std::endl;
	out << "Grade to execute: " << other.getGradeToExecute() << std::endl;
	return out;
}