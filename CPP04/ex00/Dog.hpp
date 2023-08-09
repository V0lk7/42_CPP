/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:31:41 by jduval            #+#    #+#             */
/*   Updated: 2023/08/08 13:42:23 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public	:

		Dog();					//Default constructor
		Dog(Dog const &src);	//Copy constructor
		~Dog();					//Destructor
		Dog	&operator=(Dog const &rhs);

		virtual void	makeSound(void) const;
};

#endif
