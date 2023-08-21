/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:23:55 by jduval            #+#    #+#             */
/*   Updated: 2023/08/21 15:43:51 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character()
{
	for (int i = 0; i < INVENTORY_COUNT; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character : Default constructor called." << std::endl;
}

Character::Character(std::string const name) :	_name(name)
{
	for (int i = 0; i < INVENTORY_COUNT; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character : Constructor with name called." << std::endl;
}

Character::Character(Character const &src)
{
	std::cout << "Character : Copy constructor called." << std::endl;
	*this = src;
}

Character::~Character()
{
	for (int i = 0; i < INVENTORY_COUNT; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	std::cout << "Character : Destructor called." << std::endl;
}

Character	&Character::operator=(Character const &rhs)
{
	for (int i = 0; i < INVENTORY_COUNT; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	this->_name = rhs.getName();
	for (int i = 0; i < INVENTORY_COUNT; i++)
	{
		if (rhs._inventory[i] != NULL)
			this->_inventory[i] = (rhs._inventory[i])->clone();
	}
	return (*this);
}

void	Character::equip(AMateria *m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < INVENTORY_COUNT; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (!(idx >= 0 && idx <= 3) || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (!(idx >= 0 && idx <= 3) || this->_inventory[idx] == NULL)
		return ;
	(this->_inventory[idx])->use(target);
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}
