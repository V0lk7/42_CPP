/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:20:49 by jduval            #+#    #+#             */
/*   Updated: 2023/08/08 14:31:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :	_hit_points(10),
						_energy_points(10),
						_attack_damage(0)
{
	std::cout << "ClapTrap : "<< "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :	_name(name),
										_hit_points(10),
										_energy_points(10),
										_attack_damage(0)
{
	std::cout << "ClapTrap : "<< this->_name << " : Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap : "<< this->_name << " : Destructor called" << std::endl;
}


ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
	std::cout << "ClapTrap : "<< this->_name << " : Copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs.getName();
	this->_hit_points = rhs.getHitPoints();
	this->_energy_points = rhs.getEnergyPoints();
	this->_attack_damage = rhs.getAttackDamage();
	return (*this);	
}

int		ClapTrap::getAttackDamage() const
{
	return (this->_attack_damage);
}

int		ClapTrap::getEnergyPoints() const
{
	return (this->_energy_points);
}

int		ClapTrap::getHitPoints() const
{
	return (this->_hit_points);
}

std::string		ClapTrap::getName() const
{
	return (this->_name);
}

void	ClapTrap::displayStats(void) const
{
	std::cout	<< "Name : " << this->_name << "\n"
				<< "Hit points : " << this->_hit_points << "\n"
				<< "Energy points : " << this->_energy_points << "\n"
				<< "Attack damage : " << this->_attack_damage << std::endl;
	return ;
}


void	ClapTrap::attack(std::string const &target)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
		return ;
	std::cout	<< "ClapTrap : " << this->_name << " attacks " << target
				<< " causing " << this->_attack_damage << " points of damage !"
				<< std::endl;
	this->_energy_points -= 1;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout	<< "ClapTrap : " << this->_name << " takes "
				<< amount << " of damages" << std::endl;
	this->_hit_points -= amount;
	if (_hit_points < 0)
		this->_hit_points = 0;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
		return ;
	std::cout	<< "ClapTrap : " << this->_name << " repairing itself. Gain "
				<< amount << " hit points." << std::endl;
	this->_hit_points += amount;
	this->_energy_points -= 1;
}
