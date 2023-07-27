/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:57:34 by jduval            #+#    #+#             */
/*   Updated: 2023/07/27 10:18:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private	:
		std::string	type;
	public	:
		Weapon(std::string);
		~Weapon();
		const std::string	&getType(void);
		void				setType(std::string);
};

#endif
