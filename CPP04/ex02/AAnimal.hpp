/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/08/09 14:30:34 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal
{
	protected	:

		std::string		_type;

	public	:

		AAnimal();					//Default constructor
		AAnimal(AAnimal const &src);	//Copy constructor
		virtual ~AAnimal();					//Destructor
		AAnimal	&operator=(AAnimal const &rhs);

		AAnimal(std::string const);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
