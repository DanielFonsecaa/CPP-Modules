#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137){
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string targ) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm name constructor" << std::endl;
	target = targ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other){
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	std::cout << "ShrubberyCreationForm copy assignment" << std::endl;
	if (this != &other) {
		target = other.target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const 
{
	AForm::execute(bureaucrat);
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file.is_open())
		throw AForm::FileNotOpenedException();
	file << "      /\\" << std::endl;
	file << "     /  \\" << std::endl;
	file << "    /    \\" << std::endl;
	file << "   /      \\" << std::endl;
	file << "  /        \\" << std::endl;
	file << " /__________\\" << std::endl;
	file << "      ||" << std::endl;
	file << "      ||" << std::endl;
	file << "      ||" << std::endl;
	file.close();
}


std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &other)
{
	out << "Form: " << other.getName() << std::endl;
	out << "Signed: " << other.getSigned() << std::endl;
	out << "Grade to sign: " << other.getGradeToSign() << std::endl;
	out << "Grade to execute: " << other.getGradeToExecute() << std::endl;
	return out;
}