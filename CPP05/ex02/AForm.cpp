/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:46:11 by jduval            #+#    #+#             */
/*   Updated: 2023/10/03 17:07:07 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstddef>

AForm::AForm() :
	_name(""), _isSigned(false),
	_gradeToSign(1), _gradeToExecute(1)
{
//	std::cout << "AForm : " << "Default construtor called" << std::endl;
}

AForm::AForm(AForm const &src) :
	_name(src.getName()), _isSigned(src.getIsSigned()),
	_gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
//	std::cout << "AForm : " << "Copy constructor called" << std::endl;
}

AForm::AForm(std::string const AFormName, int const InitGradeToSign, int const InitGradeToExecute) :
	_name(AFormName), _isSigned(false),
	_gradeToSign(InitGradeToSign), _gradeToExecute(InitGradeToExecute)
{
	if (InitGradeToSign < 1 || InitGradeToExecute < 1)
		throw (AForm::GradeTooHighException());
	else if (InitGradeToSign > 150 || InitGradeToExecute > 150)
		throw (AForm::GradeTooLowException());
//	std::cout << "AForm : " << this->_name << " : Construtor with values called" << std::endl;
}

AForm::~AForm()
{
//	std::cout << "AForm : " << this->_name << " : Destructor called" << std::endl;
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void		AForm::beSigned(Bureaucrat const &employe)
{
	if (employe.getGrade() > this->_gradeToSign)
		throw (AForm::GradeTooLowException());
	else
		this->_isSigned = true;
}

char const	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high !");
}

char const	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low !");
}

char const	*AForm::FormIsNotSigned::what(void) const throw()
{
	return ("The form isn't signed yet !");
}

AForm	&AForm::operator=(AForm const &rhs)
{
	AForm const	*TestNullRef = &rhs;
	if (TestNullRef != NULL)
		this->_isSigned = rhs.getIsSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
{
	AForm const	*TestNullRef = &rhs;
	if (TestNullRef != NULL)
	{
		o	<< "AForm Name : " << rhs.getName() << "\n"
			<< "AForm signed : " << rhs.getIsSigned() << "\n"
			<< "Grade to sign : " << rhs.getGradeToSign() << "\n"
			<< "Grade to execute : " << rhs.getGradeToExecute() << "\n";
	}
	else
		o	<< "The ref is null.";
	return (o);
}
