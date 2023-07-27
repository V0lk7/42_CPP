/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:54:42 by jduval            #+#    #+#             */
/*   Updated: 2023/07/27 10:18:09 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string new_name, Weapon &var) : weapon (var)
{
	name = new_name;
}

HumanA::~HumanA(){}

void	HumanA::attack(void)
{
	std::cout << "attacks with their " << weapon.getType() << std::endl;
}
