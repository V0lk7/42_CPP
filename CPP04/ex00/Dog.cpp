/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:31:55 by jduval            #+#    #+#             */
/*   Updated: 2023/08/08 13:43:37 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog : " << "Default construtor called" << std::endl;
}

Dog::Dog(Dog const &src)
{
	std::cout << "Dog : " << "Copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog : " << "Destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	this->_type = rhs.getType();
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "BARK BARK" << std::endl;
	return ;
}
