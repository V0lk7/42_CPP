/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:35:29 by jduval            #+#    #+#             */
/*   Updated: 2023/09/04 14:54:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : _count(0)
{
//	std::cout << "MateriaSource : Default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_stock[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
//	std::cout << "MateriaSource : Copy constructor called." << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource()
{
//	std::cout << "MateriaSource : Destructor called." << std::endl;
	for (int i = 0; i < this->_count; i++)
			delete this->_stock[i];
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	for (int i = 0; i < this->_count; i++)
	{
		if (this->_stock[i] != NULL)
			delete _stock[i];
	}
	this->_count = rhs.getCount();
	AMateria	*tmp;
	for (int i = 0; i < this->_count; i++)
	{
		tmp = rhs.getMateria(i);
		if (tmp != NULL)
			this->_stock[i] = tmp->clone();
	}

	return (*this);
}

void		MateriaSource::learnMateria(AMateria *materia)
{
	if (materia == NULL)
		return ;
	else if (this->_count > 3)
	{
		delete materia;
		return ;
	}
	this->_stock[this->_count] = materia->clone();
	this->_count++;
	delete materia;
	return ;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = this->_count - 1; i >= 0; i--)
	{
		if (this->_stock[i] != NULL && type.compare(this->_stock[i]->getType()) == 0)
			return (this->_stock[i]->clone());
	}
	return (NULL);
}

int			MateriaSource::getCount(void) const
{
	return (this->_count);
}

AMateria	*MateriaSource::getMateria(int index) const
{
	if (index < 0 || index > 3)
		return (NULL);
	return (this->_stock[index]);
}
