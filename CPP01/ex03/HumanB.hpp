/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:59:11 by jduval            #+#    #+#             */
/*   Updated: 2023/07/27 10:16:57 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
class Weapon;

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

#endif
