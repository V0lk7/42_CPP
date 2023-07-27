/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:59:53 by jduval            #+#    #+#             */
/*   Updated: 2023/07/27 10:16:39 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>

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

#endif
