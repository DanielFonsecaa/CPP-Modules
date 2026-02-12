/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:25:35 by dda-fons          #+#    #+#             */
/*   Updated: 2026/01/21 18:23:27 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "Test 1" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Daniel", 150);
		std::cout << *bureaucrat << std::endl;
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat << std::endl;
		delete bureaucrat;
		std::cout << std::endl;
	}
	{
		try
		{
			std::cout << "Test 2" << std::endl;
			Bureaucrat *bureaucrat1 = new Bureaucrat("bot alberto", 150);
			Bureaucrat *bureaucrat2 = new Bureaucrat("bot denis", 1);
			std::cout << *bureaucrat1 << std::endl;
			std::cout << *bureaucrat2 << std::endl;
			bureaucrat1->decrementGrade();
			bureaucrat2->incrementGrade();	
			delete bureaucrat1;
			delete bureaucrat2;
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}