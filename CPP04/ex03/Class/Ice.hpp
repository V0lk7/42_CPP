/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:53:59 by jduval            #+#    #+#             */
/*   Updated: 2023/08/21 15:22:47 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp" 

class ICharacter;

class Ice : public AMateria 
{
	private	:
		Ice	&operator=(Ice const &rhs);

	public	:
		Ice();
		Ice(Ice const &src);
		virtual	~Ice();

		Ice(std::string const &type);

		virtual	AMateria	*clone(void) const;
		virtual void		use(ICharacter &target) const;
};

#endif
