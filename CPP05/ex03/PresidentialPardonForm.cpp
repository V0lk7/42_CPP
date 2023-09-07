/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:42:22 by jduval            #+#    #+#             */
/*   Updated: 2023/09/07 10:59:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm() : AForm("", 25, 5)
{
//	std::cout << "PresidentialPardonForm : " << "Default construtor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
	AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute())
{
//	std::cout << "PresidentialPardonForm : " << "Copy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm(target, 25, 5)
{
//	std::cout	<< "PresidentialPardonForm : " << this->getName()
//				<< " : Construtor with values called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
//	std::cout	<< "PresidentialPardonForm : " << this->getName()
//				<< " : Destructor called" << std::endl;
}

void		PresidentialPardonForm::execute(Bureaucrat const &execute) const
{
	if (this->getIsSigned() == false)
		throw (AForm::FormIsNotSigned());
	else if (this->getGradeToExecute() < execute.getGrade())
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout	<< this->getName() << " has been pardonned by Zaphod Beeblebrox."
					<< std::endl;
		std::cout	<< execute.getName() << " executed form : "
					<< this->getName() << "." << std::endl;
	}
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	(void) rhs;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs)
{
	PresidentialPardonForm const	*TestNullRef = &rhs;

	if (TestNullRef != NULL)
	{
		o	<< "PresidentialPardonForm Name : " << rhs.getName() << "\n"
			<< "PresidentialPardonForm signed : " << rhs.getIsSigned() << "\n"
			<< "Grade to sign : " << rhs.getGradeToSign() << "\n"
			<< "Grade to execute : " << rhs.getGradeToExecute() << "\n";
	}
	else
		o	<< "The ref is null.";
	return (o);
}
