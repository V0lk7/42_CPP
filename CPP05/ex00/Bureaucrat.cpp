/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:17:59 by jduval            #+#    #+#             */
/*   Updated: 2023/09/06 12:52:07 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <cstddef>

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat : " << "Default construtor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName())
{
	std::cout << "Bureaucrat : " << "Copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(std::string BureaucrateName, int gradeStartValue) :	_name(BureaucrateName)
{
	if (gradeStartValue < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (gradeStartValue > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade = gradeStartValue;
	std::cout << "Bureaucrat : " << this->_name << " : Construtor with values called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat : " << this->_name << " : Destructor called" << std::endl;
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::IncrementGrade(void)
{
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
	return ;
}

void	Bureaucrat::DecrementGrade(void)
{
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
	return ;
}

char const	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high !");
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low !");
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	Bureaucrat const	*TestNullRef = &rhs;
	if (TestNullRef != NULL)
		this->_grade = rhs.getGrade();
	else
		this->_grade = 150;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	Bureaucrat const	*TestNullRef = &rhs;
	if (TestNullRef != NULL)
		o	<< rhs.getName() << " Bureaucrat grade "
			<< rhs.getGrade() << "." << std::endl;
	else
		o	<< "The ref is null." << std::endl;
	return (o);
}