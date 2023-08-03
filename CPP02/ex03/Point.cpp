/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:44:25 by jduval            #+#    #+#             */
/*   Updated: 2023/08/03 13:58:26 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#include <cmath>

Point::Point() : _x(0), _y(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Point::Point(float const x_val, float const y_val) : _x(x_val), _y(y_val)
{
//	std::cout << "Params constructor called" << std::endl;
}

Point::Point(Point const  &src) : _x(src.getX()), _y(src.getY())
{
//	std::cout << "Copy constructor called" << std::endl;
}

Point::~Point()
{
//	std::cout << "Destructor called" << std::endl;
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}

Point	&Point::operator=(Point const &rhs)
{
	(void)rhs;
	//std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}
