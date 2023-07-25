/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:59:11 by jduval            #+#    #+#             */
/*   Updated: 2023/07/25 14:12:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private	:
		std::string	name;
		Weapon	*weapon;
	public	:
		HumanB(std::string);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon &var);
};
