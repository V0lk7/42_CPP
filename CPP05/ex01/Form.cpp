/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:46:11 by jduval            #+#    #+#             */
/*   Updated: 2023/10/03 11:14:45 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstddef>

Form::Form() :
	_name(""), _isSigned(false),
	_gradeToSign(1), _gradeToExecute(1)
{
//	std::cout << "Form : " << "Default construtor called" << std::endl;
}

Form::Form(Form const &src) :
	_name(src.getName()), _isSigned(src.getIsSigned()),
	_gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
//	std::cout << "Form : " << "Copy constructor called" << std::endl;
}

Form::Form(std::string const FormName, int const InitGradeToSign, int const InitGradeToExecute) :
	_name(FormName), _isSigned(false),
	_gradeToSign(InitGradeToSign), _gradeToExecute(InitGradeToExecute)
{
	if (InitGradeToSign < 1 || InitGradeToExecute < 1)
		throw (Form::GradeTooHighException());
	else if (InitGradeToSign > 150 || InitGradeToExecute > 150)
		throw (Form::GradeTooLowException());
//	std::cout << "Form : " << this->_name << " : Construtor with values called" << std::endl;
}

Form::~Form()
{
//	std::cout << "Form : " << this->_name << " : Destructor called" << std::endl;
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void		Form::beSigned(Bureaucrat const &employe)
{
	if (employe.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException());
	else
		this->_isSigned = true;
}

char const	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high !");
}

char const	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low !");
}

Form	&Form::operator=(Form const &rhs)
{
	Form const	*TestNullRef = &rhs;
	if (TestNullRef != NULL)
		this->_isSigned = rhs.getIsSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	Form const	*TestNullRef = &rhs;
	if (TestNullRef != NULL)
	{
		o	<< "Form Name : " << rhs.getName() << "\n"
			<< "Form signed : " << rhs.getIsSigned() << "\n"
			<< "Grade to sign : " << rhs.getGradeToSign() << "\n"
			<< "Grade to execute : " << rhs.getGradeToExecute() << "\n";
	}
	else
		o	<< "The ref is null.";
	return (o);
}
