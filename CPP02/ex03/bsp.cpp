/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:53:03 by jduval            #+#    #+#             */
/*   Updated: 2023/08/03 17:04:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

static bool	is_vertical(Point const &a, Point const &b)
{
	if (a.getX() == b.getX())
		return (true);
	else
		return (false);
}

static bool	is_horizontal(Point const &a, Point const &b)
{
	if (a.getY() == b.getY())
		return (true);
	else
		return (false);
}

//Equation de droite
//	y = mx + b
//	m = (y2 - y1) / (x2 - x1)
//	b = y1 - a * x1;

static bool	is_on_line(Point const &a, Point const &b, Point const &point)
{
	if (is_vertical(a, b) == true)
	{
		if (point.getX() == a.getX())
			return (true);
		else
			return (false);
	}
	else if (is_horizontal(a, b) == true)
	{
		if (point.getY() == a.getY())
			return (true);
		else
			return (false);
	}

	Fixed	m((b.getY() - a.getY()) / (b.getX() - a.getX()));
	Fixed	B(a.getY() - (m * a.getX()));
	Fixed	result (m * point.getX() + B);

	if (result == point.getY())
		return (true);
	else
		return (false);
}

//Area of a triangle with 3 points
// (1/2) * (Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By))

static bool	area_is_equal(Point const &a, Point const &b, Point const &c, Point const &point)
{
	Fixed	ABC(Fixed(0.5f) *((a.getX() * (b.getY() - c.getY()))
							+ (b.getX() * (c.getY() - a.getY()))
							+ (c.getX() * (a.getY() - b.getY()))));
	if (ABC < Fixed(0.0f))
		ABC = ABC * Fixed(-1.0f);

	Fixed	Areas[3];
	Areas[0] = Fixed(0.5f) *( (a.getX() * (point.getY() - c.getY()))			//APC
								+ (point.getX() * (c.getY() - a.getY()))
								+ (c.getX() * (a.getY() - point.getY())));
	if (Areas[0] < Fixed(0.0f))
		Areas[0] = Areas[0] * Fixed(-1.0f);

	Areas[1] = Fixed(0.5f) *( (point.getX() * (b.getY() - c.getY()))			//BPC
								+ (b.getX() * (c.getY() - point.getY()))
								+ (c.getX() * (point.getY() - b.getY())));
	if (Areas[1] < Fixed(0.0f))
		Areas[1] = Areas[1] * Fixed(-1.0f);

	Areas[2] = Fixed(0.5f) *( (a.getX() * (b.getY() - point.getY()))			//ABP
								+ (b.getX() * (point.getY() - a.getY()))
								+ (point.getX() * (a.getY() - b.getY())));
	if (Areas[2] < Fixed(0.0f))
		Areas[2] = Areas[2] * Fixed(-1.0f);

	if (roundf((Areas[0] + Areas[1] + Areas[2]).toFloat()) == roundf(ABC.toFloat()))
		return (true);
	else
		return (false);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (is_on_line(a, b, point) == true
		|| is_on_line(a, c, point) == true
		|| is_on_line(b, c, point) == true)
		return (false);
	if (area_is_equal(a, b, c, point) == true)
		return (true);
	else
		return (false);
	return (true);
}
