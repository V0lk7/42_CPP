/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:35:29 by jduval            #+#    #+#             */
/*   Updated: 2023/08/10 17:46:37 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : _count(0)
{
	std::cout << "MateriaSource : Default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_count[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	std::cout << "MateriaSource : Copy constructor called." << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource : Destructor called." << std::endl;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	(void) rhs;
	return (*this);
}
