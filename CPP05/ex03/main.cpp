/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:34:09 by jduval            #+#    #+#             */
/*   Updated: 2023/09/07 15:18:27 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

static void	ErrorTest(void)
{
	Intern employe;

	AForm	*Form;

	try{
		Form = employe.makeForm("shrubbery", "Home");
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		Form = employe.makeForm("robotomy", "Eddy");
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		Form = employe.makeForm("president", "Joe");
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	Intern	employe;
	AForm	*Form = employe.makeForm("Shrubbery", "Home");
	
	std::cout << *Form << std::endl;
	delete Form;
	Form = employe.makeForm("Robotomy", "Eddy");
	std::cout << *Form << std::endl;
	delete Form;
	Form = employe.makeForm("Presidential", "Joe");
	std::cout << *Form << std::endl;
	delete Form;
	ErrorTest();
	return (0);
}
