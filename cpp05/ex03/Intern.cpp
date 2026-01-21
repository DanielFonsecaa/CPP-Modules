#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(){
	std::cout << "Intern default constructor" << std::endl;
}

Intern::~Intern(){
	std::cout << "Intern destructor" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern copy constructor" << std::endl;
}

Intern &Intern::operator=(const Intern &other){
	(void)other;
	std::cout << "Intern copy assignment" << std::endl;
	return *this;
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	AForm *(*forms[3])(std::string const &targ) = {
		&ShrubberyCreationForm::createShrubberyForm,
		&RobotomyRequestForm::createRobotomyForm,
		&PresidentialPardonForm::createPresidentialForm
	};
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i](target);
		}
	}
	std::cout << "Error creating Form " << formName << std::endl;
    throw AForm::FormCreationException();
	return NULL;
}

/*void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;
	for(; i < 4; i++)
	{
		if (level == levels[i])
			break ;
	}
	switch (i)
	{
	case 0:
		(this->*complain[0])();
	case 1:
		(this->*complain[1])();
	case 2:
		(this->*complain[2])();
	case 3:
		(this->*complain[3])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	
}*/

std::ostream &operator<<(std::ostream &out, Intern const &)
{
	out << "Intern";
	return out;
}