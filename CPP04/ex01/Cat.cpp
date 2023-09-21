/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:17:59 by jduval            #+#    #+#             */
/*   Updated: 2023/09/21 14:49:23 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	this->_brainptr = new Brain();
	std::cout << "Cat : " << "Default construtor called" << std::endl;
}

Cat::Cat(Cat const &src)
{
	this->_brainptr = new Brain(src.getBrainPtr());
	std::cout << "Cat : " << "Copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat : " << "Destructor called" << std::endl;
	delete this->_brainptr;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	this->_type = rhs.getType();
	*(this->_brainptr) = rhs.getBrainPtr();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaouuuuuuu" << std::endl;
	return ;
}

Brain const	&Cat::getBrainPtr(void) const
{
	return (*(this->_brainptr));
}

void	Cat::printIdea(int const index) const
{
	std::cout	<< "At index " << index
				<< " There is : " << this->_brainptr->getBrainIdea(index)
				<< std::endl;
}

void	Cat::setIdeaInBrain(int const index, std::string const item) const
{
	this->_brainptr->setBrainIdea(index, item);
	return ;
}
