/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:03:53 by jduval            #+#    #+#             */
/*   Updated: 2023/08/03 16:59:23 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
//#include <iostream>

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

Fixed		&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed const	&Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed		&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed const	&Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_number = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed	&Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	Fixed	result (this->toFloat() + rhs.toFloat());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	Fixed	result (this->toFloat() - rhs.toFloat());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	Fixed	result (this->toFloat() * rhs.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	Fixed	result (this->toFloat() / rhs.toFloat());
	return (result);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
