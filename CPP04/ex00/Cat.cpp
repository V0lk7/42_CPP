/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:17:59 by jduval            #+#    #+#             */
/*   Updated: 2023/08/08 14:26:14 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat : " << "Default construtor called" << std::endl;
}

Cat::Cat(Cat const &src)
{
	std::cout << "Cat : " << "Copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat : " << "Destructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	this->_type = rhs.getType();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaouuuuuuu" << std::endl;
	return ;
}
