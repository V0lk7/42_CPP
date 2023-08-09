/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:17:59 by jduval            #+#    #+#             */
/*   Updated: 2023/08/09 14:29:11 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	std::cout << "AAnimal : " << "Default construtor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << "AAnimal : " << "Copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal : " << "Destructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	this->_type = rhs.getType();
	return (*this);
}

AAnimal::AAnimal(std::string const new_type) : _type(new_type)
{
	std::cout << "AAnimal : " << "Type constructor called" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
