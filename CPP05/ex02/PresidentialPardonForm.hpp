/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:40:43 by jduval            #+#    #+#             */
/*   Updated: 2023/09/07 15:32:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private :
		PresidentialPardonForm();						//Default constructor
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

	public	:

		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);	//Copy constructor
		~PresidentialPardonForm();						//Destructor

		virtual void		execute(Bureaucrat const &executor) const;
};

#endif
