/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:31:55 by jduval            #+#    #+#             */
/*   Updated: 2023/08/09 14:17:44 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	this->_brainptr = new Brain();
	std::cout << "Dog : " << "Default construtor called" << std::endl;
}

Dog::Dog(Dog const &src)
{
	this->_brainptr = new Brain(src.getBrainPtr());
	std::cout << "Dog : " << "Copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog : " << "Destructor called" << std::endl;
	delete this->_brainptr;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	this->_type = rhs.getType();
	*(this->_brainptr) = rhs.getBrainPtr();
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "BARK BARK" << std::endl;
	return ;
}

Brain const	&Dog::getBrainPtr(void) const
{
	return (*(this->_brainptr));
}

void	Dog::printIdea(int const index) const
{
	std::cout	<< "At index " << index
				<< " There is : " << this->_brainptr->getBrainIdea(index)
				<< std::endl;
}

void	Dog::setIdeaInBrain(int const index, std::string const item) const
{
	this->_brainptr->setBrainIdea(index, item);
	return ;
}
