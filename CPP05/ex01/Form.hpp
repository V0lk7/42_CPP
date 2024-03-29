/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:47:07 by jduval            #+#    #+#             */
/*   Updated: 2023/09/06 14:13:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Bureaucrat;

class Form
{
	private	:

		std::string const	_name;
		bool				_isSigned;
		int	const			_gradeToSign;
		int	const			_gradeToExecute;

		Form();						//Default constructor
		Form	&operator=(Form const &rhs);

	public	:

		Form(	std::string const FormName,
				int const InitGradeToSign,
				int const InitGradeToExecute);
		Form(Form const &src);	//Copy constructor
		~Form();						//Destructor

		std::string	getName(void) const;
		bool 		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void		beSigned(Bureaucrat const &employe);

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
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif
