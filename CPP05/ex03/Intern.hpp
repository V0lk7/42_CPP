/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:14:17 by jduval            #+#    #+#             */
/*   Updated: 2023/10/04 15:34:05 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern
{
	private :
		Intern(Intern const &src);	//Copy constructor
		Intern	&operator=(Intern const &rhs);

		AForm	*CreateShrubberyForm(std::string target);
		AForm	*CreateRobotomyForm(std::string target);
		AForm	*CreatePresidentialForm(std::string target);

	public	:
		Intern();						//Default constructor
		~Intern();						//Destructor

		AForm	*makeForm(std::string name, std::string target);

		class IllegalForm : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
};

#endif
