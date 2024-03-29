/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:53:07 by jduval            #+#    #+#             */
/*   Updated: 2023/09/05 09:54:19 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# define INVENTORY_COUNT 4

class Character : public ICharacter
{
	private	:
		std::string	_name;
		AMateria	*_inventory[INVENTORY_COUNT];

	public	:
		~Character();
		Character();
		Character(Character const &src);
		Character(std::string const name);
		Character	&operator=(Character const &rhs);

		std::string const	&getName(void) const;
		AMateria			*getItem(int index) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};

std::ostream	&operator<<(std::ostream &o, Character const &rhs);

#endif
