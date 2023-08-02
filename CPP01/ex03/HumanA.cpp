/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:54:42 by jduval            #+#    #+#             */
/*   Updated: 2023/08/02 10:27:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string new_name, Weapon &var) : name (new_name),
													weapon (var)
{
}

HumanA::~HumanA(){}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}
