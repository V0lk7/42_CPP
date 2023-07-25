/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:57:34 by jduval            #+#    #+#             */
/*   Updated: 2023/07/25 13:22:37 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

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
