/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:58:37 by jduval            #+#    #+#             */
/*   Updated: 2023/08/08 14:40:47 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap : " << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap : " << this->_name << " : Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap : " << this->_name << " : Destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	*this = src;
	std::cout << "ScavTrap : " << this->_name << " : Copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	this->_name = rhs.getName();
	this->_hit_points = rhs.getHitPoints();
	this->_energy_points = rhs.getEnergyPoints();
	this->_attack_damage = rhs.getAttackDamage();
	return (*this);	
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
		return ;
	std::cout	<< "ScavTrap : " << this->_name << " attacks " << target
				<< " causing " << this->_attack_damage << " points of damage !"
				<< std::endl;
	this->_energy_points -= 1;
	return ;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout	<< "ScavTrap : " << this->_name << " takes "
				<< amount << " of damages" << std::endl;
	this->_hit_points -= amount;
	if (_hit_points < 0)
		this->_hit_points = 0;
	return ;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
		return ;
	std::cout	<< "ScavTrap : " << this->_name << " repairing itself. Gain "
				<< amount << " hit points." << std::endl;
	this->_hit_points += amount;
	this->_energy_points -= 1;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
		return ;
	std::cout	<< "ScavTrap : " << this->_name << " In Gate keeper position mode."
				<< std::endl;
	this->_energy_points -= 1;
}
