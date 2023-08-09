/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:31:41 by jduval            #+#    #+#             */
/*   Updated: 2023/08/09 14:30:59 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class Brain;

class Dog : public AAnimal
{
	private	:

		Brain	*_brainptr;

	public	:

		Dog();					//Default constructor
		Dog(Dog const &src);	//Copy constructor
		~Dog();					//Destructor
		Dog	&operator=(Dog const &rhs);

		virtual void	makeSound(void) const;
		Brain const		&getBrainPtr(void) const;
		void			setIdeaInBrain(int const, std::string const) const;
		void			printIdea(int const) const;
};

#endif
