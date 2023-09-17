/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:47:07 by jduval            #+#    #+#             */
/*   Updated: 2023/09/17 07:50:34 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>

class Bureaucrat;

class AForm
{
	private	:

		std::string const	_name;
		bool				_isSigned;
		int	const			_gradeToSign;
		int	const			_gradeToExecute;

		AForm();						//Default constructor
		AForm	&operator=(AForm const &rhs);

	public	:

		AForm(	std::string const AFormName,
				int const InitGradeToSign,
				int const InitGradeToExecute);
		AForm(AForm const &src);	//Copy constructor
		virtual ~AForm();			//Destructor

		std::string			getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		void				beSigned(Bureaucrat const &employe);
		virtual void		execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
		class FormIsNotSigned : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif
