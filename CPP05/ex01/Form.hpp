/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:47:07 by jduval            #+#    #+#             */
/*   Updated: 2023/09/06 12:02:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;

class Form
{
	private	:

		std::string const	_name;
		bool const			Signed;
		int	const			_gradeToSign;
		int	const			_gradeToExecute;

		Form();						//Default constructor

	public	:

		Form(std::string FormName, int gradeStartValue);
		Form(Form const &src);	//Copy constructor
		~Form();						//Destructor
		Form	&operator=(Form const &rhs);

		std::string	getName(void) const;
		int 		getSignedStatement(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void		IncrementGrade(void);
		void		DecrementGrade(void);

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
