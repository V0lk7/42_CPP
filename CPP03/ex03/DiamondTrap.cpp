/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:24:56 by jduval            #+#    #+#             */
/*   Updated: 2023/08/08 14:38:45 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30; 
	std::cout << "DiamondTrap : " << "Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :	ClapTrap(name + "_clap_name"),
												_diamond_name(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
	std::cout << "DiamondTrap : " << this->_diamond_name << " : Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap : " << this->_diamond_name << " : Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
{
	*this = src;
	std::cout	<< "DiamondTrap : " << this->_diamond_name
				<< " : Copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs)
{
	this->_diamond_name = rhs.getDiamondName();
	this->_name = rhs.getName();
	this->_hit_points = rhs.getHitPoints();
	this->_energy_points = rhs.getEnergyPoints();
	this->_attack_damage = rhs.getAttackDamage();
	return (*this);	
}

std::string	DiamondTrap::getDiamondName(void) const
{
	return (this->_diamond_name);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout	<< "First _name = " << getName() << "\n"
				<< "Diamond name = " << getDiamondName()
				<< std::endl;
	return ;
}
