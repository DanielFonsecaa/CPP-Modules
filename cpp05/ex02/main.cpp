/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:44:50 by gude-jes          #+#    #+#             */
/*   Updated: 2026/01/21 18:23:36 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		std::cout << "Test 1" << std::endl;
		std::cout << "Failed Tests" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Daniel", 150);
		std::cout << *bureaucrat << std::endl;
		ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");
		std::cout << *shrubbery << std::endl;
		bureaucrat->signForm(*shrubbery);
		bureaucrat->executeForm(*shrubbery);
		RobotomyRequestForm *robotomy = new RobotomyRequestForm("Home");
		std::cout << *robotomy << std::endl;
		bureaucrat->signForm(*robotomy);
		bureaucrat->executeForm(*robotomy);
		PresidentialPardonForm *presidential = new PresidentialPardonForm("Home");
		std::cout << *presidential << std::endl;
		bureaucrat->signForm(*presidential);
		bureaucrat->executeForm(*presidential);
		delete bureaucrat;
		delete shrubbery;
		delete robotomy;
		delete presidential;
		std::cout << std::endl;
	}
	{
		std::cout << "------Test 2------" << std::endl;
		std::cout << "------Sucessuful Test------" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Daniel", 1);
		std::cout << *bureaucrat << std::endl;
		std::cout << std::endl;
		ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");
		std::cout << *shrubbery << std::endl;
		std::cout << std::endl;
		bureaucrat->signForm(*shrubbery);
		bureaucrat->executeForm(*shrubbery);
		std::cout << std::endl;
		std::cout << *shrubbery << std::endl;
		std::cout << std::endl;
		
		RobotomyRequestForm *robotomy = new RobotomyRequestForm("Bot Robot");
		std::cout << *robotomy << std::endl;
		std::cout << std::endl;
		bureaucrat->signForm(*robotomy);
		bureaucrat->executeForm(*robotomy);
		std::cout << std::endl;
		std::cout << *robotomy << std::endl;
		std::cout << std::endl;
		PresidentialPardonForm *presidential = new PresidentialPardonForm("Daniel");
		std::cout << *presidential << std::endl;
		std::cout << std::endl;
		bureaucrat->signForm(*presidential);
		bureaucrat->executeForm(*presidential);
		std::cout << std::endl;
		delete bureaucrat;
		delete shrubbery;
		delete robotomy;
		delete presidential;
		std::cout << std::endl;
	}
}