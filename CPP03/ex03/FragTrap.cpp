/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:58:37 by jduval            #+#    #+#             */
/*   Updated: 2023/08/07 15:40:49 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap() : ClapTrap::ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap : " << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap : " << this->_name << " : Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap : " << this->_name << " : Destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap::ClapTrap(src)
{
	*this = src;
	std::cout << "FragTrap : " << this->_name << " : Copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	this->_name = rhs.getName();
	this->_hit_points = rhs.getHitPoints();
	this->_energy_points = rhs.getEnergyPoints();
	this->_attack_damage = rhs.getAttackDamage();
	return (*this);	
}

void	FragTrap::attack(std::string const &target)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
		return ;
	std::cout	<< "FragTrap " << this->_name << " attacks " << target
				<< " causing " << this->_attack_damage << " points of damage !"
				<< std::endl;
	this->_energy_points -= 1;
	return ;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout	<< "FragTrap " << this->_name << " takes "
				<< amount << " of damages" << std::endl;
	this->_hit_points -= amount;
	if (_hit_points < 0)
		this->_hit_points = 0;
	return ;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
		return ;
	std::cout	<< "FragTrap " << this->_name << " repairing itself. Gain "
				<< amount << " hit points." << std::endl;
	this->_hit_points += amount;
	this->_energy_points -= 1;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
		return ;
	std::cout	<< "FragTrap : " << this->_name << " Want to do a high fives !"
				<< std::endl;
	this->_energy_points -= 1;
}
