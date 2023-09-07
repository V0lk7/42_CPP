/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:46:11 by jduval            #+#    #+#             */
/*   Updated: 2023/09/07 15:33:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

#define HEADS 1
#define TAILS 0

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45)
{
//	std::cout << "RobotomyRequestForm : " << "Default construtor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
	AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute())
{
//	std::cout << "RobotomyRequestForm : " << "Copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm(target, 72, 45)
{
//	std::cout	<< "RobotomyRequestForm : " << this->getName()
//				<< " : Construtor with values called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
//	std::cout	<< "RobotomyRequestForm : " << this->getName()
//				<< " : Destructor called" << std::endl;
}

static void	RobotomyOngoing(std::string const &target)
{
	srand(time(NULL));	//This helps ensure that the sequence of
						//random numbers generated in different
						//program runs will be different
	int HeadsOrTails = rand() % 2;
	std::cout << "Rizzz, RiZZZzzz, BZzzzzz, Rizzz, bzzzzzz" << std::endl;
	if (HeadsOrTails == TAILS)
		throw(RobotomyRequestForm::RobotomyFailed());
	else
		std::cout << target << " has been successfully robotomized" << std::endl;
	return ;
}

void		RobotomyRequestForm::execute(Bureaucrat const &execute) const
{
	if (this->getIsSigned() == false)
		throw (AForm::FormIsNotSigned());
	else if (this->getGradeToExecute() < execute.getGrade())
		throw (AForm::GradeTooLowException());
	else
	{
		try {
			RobotomyOngoing(this->getName());
			std::cout	<< execute.getName() << " executed form : "
						<< this->getName() << "." << std::endl;

		}
		catch (std::exception &e){
			std::cout	<< "Exception occured in executing the form : "
						<< this->getName() << " : " << e.what() << std::endl;
		}
	}
}

char const	*RobotomyRequestForm::RobotomyFailed::what(void) const throw()
{
	return ("Robotomy has failed");
}


RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	(void) rhs;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &rhs)
{
	RobotomyRequestForm const	*TestNullRef = &rhs;

	if (TestNullRef != NULL)
	{
		o	<< "RobotomyRequestForm Name : " << rhs.getName() << "\n"
			<< "RobotomyRequestForm signed : " << rhs.getIsSigned() << "\n"
			<< "Grade to sign : " << rhs.getGradeToSign() << "\n"
			<< "Grade to execute : " << rhs.getGradeToExecute() << "\n";
	}
	else
		o	<< "The ref is null.";
	return (o);
}
