/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:55:52 by jduval            #+#    #+#             */
/*   Updated: 2023/08/09 17:10:26 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp" 

//class ICharacter;

class Cure : public AMateria 
{
	private	:
		Cure	&operator=(Cure const &rhs);

	public	:
		Cure();
		Cure(Cure const &src);
		virtual	~Cure();

		Cure(std::string const &type);

		virtual	AMateria	*clone(void) const;
//		virtual void		use(ICharacter &target) const;
};

#endif
