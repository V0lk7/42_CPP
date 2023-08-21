/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:42:56 by jduval            #+#    #+#             */
/*   Updated: 2023/08/21 13:46:38 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>
# include "AMateria.hpp"

class ICharacter
{
	public	:
		virtual	~ICharacter(){};

		virtual std::string const	&getName(void) const = 0;
		virtual void		equip(AMateria *m) = 0;
		virtual void		unequip(int idx) = 0;
		virtual void		use(int idx, ICharacter &target) = 0;
};

#endif
