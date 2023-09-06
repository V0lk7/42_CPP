/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:16:30 by jduval            #+#    #+#             */
/*   Updated: 2023/09/06 16:43:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
		ShrubberyCreationForm();						//Default constructor
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

	public	:

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);	//Copy constructor
		~ShrubberyCreationForm();						//Destructor

		void		execute(Bureaucrat const &executor) const;
};

#endif
