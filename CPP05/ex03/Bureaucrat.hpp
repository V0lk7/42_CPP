/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/09/19 09:58:00 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class AForm;

class Bureaucrat
{
	private	:

		std::string const	_name;
		int					_grade;

		Bureaucrat();						//Default constructor

	public	:

		Bureaucrat(std::string BureaucrateName, int gradeStartValue);
		Bureaucrat(Bureaucrat const &src);	//Copy constructor
		~Bureaucrat();						//Destructor
		Bureaucrat	&operator=(Bureaucrat const &rhs);

		std::string	getName(void) const;
		int 		getGrade(void) const;
		void		IncrementGrade(void);
		void		DecrementGrade(void);
		void		signForm(AForm &document);

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

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
