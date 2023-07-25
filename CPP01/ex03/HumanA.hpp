/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:59:53 by jduval            #+#    #+#             */
/*   Updated: 2023/07/25 14:12:01 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Weapon;

class HumanA
{
	private	:
		std::string	name;
		Weapon	&weapon;
	public	:
		HumanA(std::string, Weapon &var);
		~HumanA();
		void	attack(void);
};
