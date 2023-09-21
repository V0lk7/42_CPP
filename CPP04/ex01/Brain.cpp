/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:55:33 by jduval            #+#    #+#             */
/*   Updated: 2023/09/21 14:48:18 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain : " << "Default construtor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain : " << "Copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain : " << "Destructor called" << std::endl;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	std::copy(rhs.ideas, rhs.ideas + 100, this->ideas);
	return (*this);
}

void	Brain::setBrainIdea(int const index, std::string const item)
{
	if (index < 0 || index > 99)
	{
		std::cout << "Wrong index, out of range brain ideas" << std::endl;
		return ;
	}
	this->ideas[index] = item;
}

std::string const	Brain::getBrainIdea(int const index) const
{
	return (this->ideas[index]);
}
