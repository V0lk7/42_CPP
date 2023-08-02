/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:41:15 by jduval            #+#    #+#             */
/*   Updated: 2023/08/02 17:16:56 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private	:
		Fixed const	_x;
		Fixed const	_y;

	public	:
		Point();					//Default constructor
		Point(Point const &src);	//Copy constructor
		~Point();					//Destructor
		Point(float const x_val, float const y_val);

		Point	&operator=(Point const &rhs);

		Fixed	getX() const;
		Fixed	getY() const;

		static  Fixed	&getSegment(Point const &a, Point const &b);

};

#endif
