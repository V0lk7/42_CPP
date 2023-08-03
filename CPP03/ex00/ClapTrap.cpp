/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:20:49 by jduval            #+#    #+#             */
/*   Updated: 2023/08/03 16:42:06 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :	_hit_points(10),
						_energy_points(10),
						_attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :	_name(name),
										_hit_points(10),
										_energy_points(10),
										_attack_damage(0)
{
	std::cout << this->_name << " : Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " : Destructor called" << std::endl;
}

void	ClapTrap::Setname(std::string new_name)
{
	this->_name = new_name;
}

std::string	ClapTrap::Getname(void) const
{
	return (this->_name);
}
