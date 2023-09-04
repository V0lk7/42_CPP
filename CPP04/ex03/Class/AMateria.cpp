/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:41:46 by jduval            #+#    #+#             */
/*   Updated: 2023/09/04 14:54:51 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
//	std::cout << "AMateria : Default constructor called." << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
//	std::cout << "AMateria : Copy constructor called." << std::endl;
	*this = src;
}

AMateria::~AMateria()
{
//	std::cout << "AMateria : Destructor called." << std::endl;
}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	(void) rhs;
	return (*this);
}

AMateria::AMateria(std::string const &type) : _type(type)
{
//	std::cout << "AMateria : Constructor with type called." << std::endl;
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);	
}

void		AMateria::use(ICharacter &target) const 
{
	(void) target;
}
