/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:51:10 by jduval            #+#    #+#             */
/*   Updated: 2023/07/25 14:11:58 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type_of_weapon)
{
	type = type_of_weapon;
}

Weapon::~Weapon(){}

const std::string	&Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string new_type)
{
	type = new_type;
}
