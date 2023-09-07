/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:27:29 by jduval            #+#    #+#             */
/*   Updated: 2023/09/07 15:18:24 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstddef>

static const std::string	PathernForm[3] = {"Shrubbery", "Robotomy", "Presidential"};

Intern::Intern()
{
//	std::cout << "Intern : " << "Default construtor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
//	std::cout << "Intern : " << "Copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
//	std::cout << "Intern : " << this->_name << " : Destructor called" << std::endl;
}

AForm	*Intern::CreateShrubberyForm(std::string target)
{
	AForm	*Form = new ShrubberyCreationForm(target);
	return (Form);
}

AForm	*Intern::CreateRobotomyForm(std::string target)
{
	AForm	*Form = new RobotomyRequestForm(target);
	return (Form);
}

AForm	*Intern::CreatePresidentialForm(std::string target)
{
	AForm	*Form = new PresidentialPardonForm(target);
	return (Form);
}

static bool	FindPathernInName(std::string name, int i)
{
	if (name.find(PathernForm[i]) != std::string::npos)
		return (true);
	else
		return (false);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm	*(Intern::*CreateForm[3])(std::string target) = {	&Intern::CreateShrubberyForm, 
																&Intern::CreateRobotomyForm,
																&Intern::CreatePresidentialForm};
	for (int i = 0; i < 3; i++)
	{
		switch (FindPathernInName(name, i)){
			case false :
				continue ;
			default :
			{
				try{
					AForm	*GoodForm = (this->*CreateForm[i])(target);
					return (GoodForm);
				}
				catch (std::exception &e){
					std::cout << e.what() << std::endl;
				}
			}
		}
	}
	throw (Intern::IllegalForm());
}

char const	*Intern::IllegalForm::what() const throw()
{
	return ("Form name not recognised");
}

Intern	&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}
