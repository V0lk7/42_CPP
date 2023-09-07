/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:16:30 by jduval            #+#    #+#             */
/*   Updated: 2023/09/07 15:31:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private :
		ShrubberyCreationForm();						//Default constructor
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

	public	:

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);	//Copy constructor
		~ShrubberyCreationForm();						//Destructor

		virtual void		execute(Bureaucrat const &executor) const;
};

#endif
