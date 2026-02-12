#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45){
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string targ) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm name constructor" << std::endl;
	target = targ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other){
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	std::cout << "RobotomyRequestForm copy assignment" << std::endl;
	if (this != &other) {
		target = other.target;
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (target);
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const 
{
	AForm::execute(bureaucrat);
	srand(time(NULL));
	int randNum = rand() % 2;
	std::cout << "*drilling noises* " << std::endl;
	if (randNum)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << target << " robotomization failed." << std::endl;
}

AForm *RobotomyRequestForm::createRobotomyForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &other)
{
	out << "Form: " << other.getName() << std::endl;
	out << "Signed: " << other.getSigned() << std::endl;
	out << "Grade to sign: " << other.getGradeToSign() << std::endl;
	out << "Grade to execute: " << other.getGradeToExecute() << std::endl;
	return out;
}