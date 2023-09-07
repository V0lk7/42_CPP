/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:27:29 by jduval            #+#    #+#             */
/*   Updated: 2023/09/07 11:40:49 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstddef>

static const	std::string[3] = {"Shrubbery", "Robotomy", "Presidential"};

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

AForm	*Intern::makeForm(std::string name, std::string target)
{
	for (int i = 0; i < 3; i++)
	{
		switch (name)
	}
}

char const	*Intern::IllegalForm::what(void) const throw()
{
	return ("Form name not recognised");
}

Intern	&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}
