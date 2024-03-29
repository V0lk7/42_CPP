/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:23:55 by jduval            #+#    #+#             */
/*   Updated: 2023/09/05 10:46:02 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character()
{
	for (int i = 0; i < INVENTORY_COUNT; i++)
		this->_inventory[i] = NULL;
//	std::cout << "Character : Default constructor called." << std::endl;
}

Character::Character(std::string const name) :	_name(name)
{
	for (int i = 0; i < INVENTORY_COUNT; i++)
		this->_inventory[i] = NULL;
//	std::cout << this->_name << " Character : Constructor with name called." << std::endl;
}

Character::Character(Character const &src)
{
//	std::cout << "Character : Copy constructor called." << std::endl;
	*this = src;
}

Character::~Character()
{
	for (int i = 0; i < INVENTORY_COUNT; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
//	std::cout << this->_name << " Character : Destructor called." << std::endl;
}

Character	&Character::operator=(Character const &rhs)
{
	for (int i = 0; i < INVENTORY_COUNT; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	this->_name = rhs.getName();
	for (int i = 0; i < INVENTORY_COUNT; i++)
	{
		AMateria	*ptr;
		ptr = rhs.getItem(i);
		if (ptr != NULL)
			this->_inventory[i] = ptr->clone();
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
	if ((idx < 0 || idx > 3) || this->_inventory[idx] == NULL)
		return ;
	(this->_inventory[idx])->use(target);
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

AMateria	*Character::getItem(int index) const
{
	if ((index < 0 || index > 3) || this->_inventory[index] == NULL)
		return (NULL);
	return (this->_inventory[index]);
}

std::ostream	&operator<<(std::ostream &o, Character const &rhs)
{
	o << rhs.getName() << std::endl;
	for (int i = 0; i < INVENTORY_COUNT; i++)
	{
		AMateria	*ptr;
		ptr = rhs.getItem(i);
		if (ptr == NULL)
			break ;
		else
			o << ptr->getType() << " Address : " << ptr << std::endl;
	}
	return (o);
}
