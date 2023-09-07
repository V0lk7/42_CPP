/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:34:09 by jduval            #+#    #+#             */
/*   Updated: 2023/09/07 11:01:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static void	testShrubbery(void)
{
	std::cout << "TEST SHRUBBERY" << std::endl;
	AForm	*HomeForm = new ShrubberyCreationForm("HOME");
	AForm	*NoForm = new ShrubberyCreationForm("NoForm");
	Bureaucrat	joe("Joe", 150);
	Bureaucrat	eddy("Eddy", 137);

	std::cout << *HomeForm << "\n" << std::endl;
	std::cout << joe << std::endl;
	std::cout << eddy << std::endl;

	joe.signForm(*HomeForm);
	std::cout << *HomeForm << std::endl;
	eddy.signForm(*HomeForm);
	std::cout << *HomeForm << std::endl;

	try{
		HomeForm->execute(joe);
	}
	catch (std::exception &e){
		std::cout	<< "Couldn't execute form : " << HomeForm->getName()
					<< " because " << e.what() << std::endl;
	}

	try{
		NoForm->execute(eddy);
	}
	catch (std::exception &e){
		std::cout	<< "Couldn't execute form : " << NoForm->getName()
					<< " because " << e.what() << std::endl;
	}

	HomeForm->execute(eddy);
	delete HomeForm;
	delete NoForm;
}

static void	testRobotomy(void)
{
	std::cout << "\nTEST ROBOTOMY" << std::endl;
	AForm	*FormForRobotomize = new RobotomyRequestForm("Eddy");
	Bureaucrat	joe("Joe", 1);

	joe.signForm(*FormForRobotomize);
	FormForRobotomize->execute(joe);
	return ;
}

static void testPresidentialPardon(void)
{
	std::cout << "\nTEST PRESIDENTIAL" << std::endl;
	AForm		*dave = new PresidentialPardonForm("Dave");
	Bureaucrat	employe("Lambda", 1);
	Bureaucrat	employe2("Lambda2", 5);
	Bureaucrat	employe3("Lambda3", 6);

	std::cout << *dave << std::endl;
	std::cout << employe << std::endl;
	employe.signForm(*dave);
	dave->execute(employe);
	dave->execute(employe2);
	try{
		dave->execute(employe3);
	}
	catch (std::exception &e){
		std::cout	<< "Couldn't execute form : " << dave->getName()
					<< " because " << e.what() << std::endl;
	}
	delete dave;
}

int	main(void)
{
	testShrubbery();
	testRobotomy();
	testPresidentialPardon();
	return (0);
}
