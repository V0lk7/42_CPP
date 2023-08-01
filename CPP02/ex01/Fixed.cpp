/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:03:53 by jduval            #+#    #+#             */
/*   Updated: 2023/08/01 16:40:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <cmath>

int const	Fixed::_nbr_of_bits = 8;

Fixed::Fixed() : _number(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
	this->_number = value << Fixed::_nbr_of_bits;
//	std::cout << "Constructor Int to Fixed called" << std::endl;
}

Fixed::Fixed(float const value)
{
	this->_number = roundf(value * (1 << Fixed::_nbr_of_bits));
//	std::cout << "Constructor Float to Fixed called" << std::endl;
}

Fixed::Fixed(Fixed const  &src)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void	Fixed::setRawBits(int const raw)
{
	this->_number = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (1 << Fixed::_nbr_of_bits));
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> Fixed::_nbr_of_bits);
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_number = rhs.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
