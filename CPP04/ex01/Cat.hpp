/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/08/09 14:17:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Brain;

class Cat : public Animal
{
	private	:

		Brain	*_brainptr;

	public	:

		Cat();					//Default constructor
		Cat(Cat const &src);	//Copy constructor
		~Cat();					//Destructor
		Cat	&operator=(Cat const &rhs);

		virtual void	makeSound(void) const;
		Brain const		&getBrainPtr(void) const;
		void			setIdeaInBrain(int const, std::string const) const;
		void			printIdea(int const) const;
};

#endif
