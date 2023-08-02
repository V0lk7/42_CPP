/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:44:25 by jduval            #+#    #+#             */
/*   Updated: 2023/08/02 17:59:12 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#include <cmath>

Point::Point() : _x(0), _y(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(float const x_val, float const y_val) : _x(x_val), _y(y_val)
{
	std::cout << "Params constructor called" << std::endl;
}

Point::Point(Point const  &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Point::~Point()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}

Fixed	&Point::getSegment(Point const &a, Point const &b)
{
	float	result;

	result = b.getX() - a.getX()
	result += powf((b.getY() - a.getY()).toFloat());
	result = sqrtf(result);
	return (Fixed(result));
}

Point	&Point::operator=(Point const &rhs)
{
	(void)rhs;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}
