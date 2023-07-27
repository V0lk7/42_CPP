/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:01:52 by jduval            #+#    #+#             */
/*   Updated: 2023/07/27 10:17:57 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <new>
#include <iostream>

HumanB::HumanB(std::string new_name)
{
	weapon = NULL;
	name = new_name;
}
HumanB::~HumanB(){}

void	HumanB::attack(void)
{
	std::cout << "attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &var)
{
	weapon = &var;
}
