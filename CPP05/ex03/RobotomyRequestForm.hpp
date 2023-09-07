/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:16:30 by jduval            #+#    #+#             */
/*   Updated: 2023/09/07 15:33:38 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private :
		RobotomyRequestForm();						//Default constructor
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

	public	:

		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);	//Copy constructor
		~RobotomyRequestForm();						//Destructor

		virtual void		execute(Bureaucrat const &executor) const;

		class RobotomyFailed : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
};

#endif
