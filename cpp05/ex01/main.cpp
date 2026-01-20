/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:25:35 by dda-fons          #+#    #+#             */
/*   Updated: 2026/01/20 14:19:55 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << "Test 1" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Daniel", 150);
		std::cout << *bureaucrat << std::endl;
		Form *form = new Form();
		std::cout << *form << std::endl;
		form->beSigned(*bureaucrat);
		std::cout << *form << std::endl;
		delete form;
		delete bureaucrat;
		std::cout << std::endl;
	}
	{
		std::cout << "Test 2" << std::endl;
		Bureaucrat *b1 = new Bureaucrat("Daniel", 150);
		Bureaucrat *b2 = new Bureaucrat("bot denis", 1);
		std::cout << *b1 << std::endl;
		std::cout << *b2 << std::endl;
		Form *form = new Form("Form", 1, 1);
		std::cout << *form << std::endl;
		try
		{
			form->beSigned(*b1);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			form->beSigned(*b2);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		std::cout << *form << std::endl;
		delete form;
		delete b1;
		delete b2;
		std::cout << std::endl;
	}
	{
		std::cout << "Test 3" << std::endl;
		Bureaucrat *b1 = new Bureaucrat("Maria", 150);
		Bureaucrat *b2 = new Bureaucrat("Daniel lindao", 1);
		std::cout << *b1 << std::endl;
		std::cout << *b2 << std::endl;
		Form *form1 = new Form("FormA", 1, 1);
		Form *form2 = new Form("FormB", 1, 1);
		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		try
		{
			b1->signForm(*form1);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			b2->signForm(*form2);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		delete form1;
		delete form2;
		delete b1;
		delete b2;
	}
}