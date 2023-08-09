/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/08/08 13:53:40 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected	:

		std::string		_type;

	public	:

		Animal();					//Default constructor
		Animal(Animal const &src);	//Copy constructor
		virtual ~Animal();					//Destructor
		Animal	&operator=(Animal const &rhs);

		Animal(std::string const);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
