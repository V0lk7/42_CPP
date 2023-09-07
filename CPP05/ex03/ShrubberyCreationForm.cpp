/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:46:11 by jduval            #+#    #+#             */
/*   Updated: 2023/09/07 11:01:47 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>

static const	std::string	TreeInAscii =
"	   *      \n	  ***     \n	 *****    \n	*******   \n	  | |     \n	_/___\\_  \n";

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137)
{
//	std::cout << "ShrubberyCreationForm : " << "Default construtor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
	AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute())
{
//	std::cout << "ShrubberyCreationForm : " << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm(target, 145, 137)
{
//	std::cout	<< "ShrubberyCreationForm : " << this->getName()
//				<< " : Construtor with values called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
//	std::cout	<< "ShrubberyCreationForm : " << this->getName()
//				<< " : Destructor called" << std::endl;
}

static void	PutTreeInFile(std::string target)
{
	target += "_shrubbery";

	std::ofstream	outfile(target.c_str());
	outfile << TreeInAscii << "\n" << TreeInAscii;
	outfile.close();
}

void		ShrubberyCreationForm::execute(Bureaucrat const &execute) const
{
	if (this->getIsSigned() == false)
		throw (AForm::FormIsNotSigned());
	else if (this->getGradeToExecute() < execute.getGrade())
		throw (AForm::GradeTooLowException());
	else
	{
		try {
			PutTreeInFile(this->getName());
			std::cout	<< execute.getName() << " executed form : "
						<< this->getName() << "." << std::endl;
		}
		catch (std::exception &e){
			std::cout	<< "Exception occured in executing the form : "
						<< this->getName() << " : " << e.what() << std::endl;
		}
	}
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	(void) rhs;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &rhs)
{
	ShrubberyCreationForm const	*TestNullRef = &rhs;

	if (TestNullRef != NULL)
	{
		o	<< "ShrubberyCreationForm Name : " << rhs.getName() << "\n"
			<< "ShrubberyCreationForm signed : " << rhs.getIsSigned() << "\n"
			<< "Grade to sign : " << rhs.getGradeToSign() << "\n"
			<< "Grade to execute : " << rhs.getGradeToExecute() << "\n";
	}
	else
		o	<< "The ref is null.";
	return (o);
}
