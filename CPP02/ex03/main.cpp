/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:10:48 by jduval            #+#    #+#             */
/*   Updated: 2023/08/03 13:50:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	bool	flag;

	std::cout << "TEST1" << std::endl;
	std::cout << "x = " << 3.0f << " y = " << 3.0f << std::endl;
	flag = bsp(Point(2.0f, 3.0f), Point(4.0f, 4.0f), Point(4.0f, 2.0f), Point(3.0f, 3.0f));	
	if (flag == true)
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point not in triangle" << std::endl;

	std::cout << "TEST2" << std::endl;
	std::cout << "x = " << 2.1f << " y = " << 3.0f << std::endl;
	flag = bsp(Point(2.0f, 3.0f), Point(4.0f, 4.0f), Point(4.0f, 2.0f), Point(2.1f, 3.0f));	
	if (flag == true)
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point not in triangle" << std::endl;

	std::cout << "TEST3" << std::endl;
	std::cout << "x = " << 2.1f << " y = " << 2.96f << std::endl;
	flag = bsp(Point(2.0f, 3.0f), Point(4.0f, 4.0f), Point(4.0f, 2.0f), Point(2.1f, 2.96f));	
	if (flag == true)
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point not in triangle" << std::endl;

	std::cout << "TEST4" << std::endl;
	std::cout << "x = " << 2.1f << " y = " << 2.95f << std::endl;
	flag = bsp(Point(2.0f, 3.0f), Point(4.0f, 4.0f), Point(4.0f, 2.0f), Point(2.1f, 2.95f));	
	if (flag == true)
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point not in triangle" << std::endl;

	std::cout << "TEST5" << std::endl;
	std::cout << "x = " << 4.0f << " y = " << 3.0f << std::endl;
	flag = bsp(Point(2.0f, 3.0f), Point(4.0f, 4.0f), Point(4.0f, 2.0f), Point(4.0f, 3.0f));	
	if (flag == true)
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point not in triangle" << std::endl;

	std::cout << "TEST6" << std::endl;
	std::cout << "x = " << 3.99f << " y = " << 3.0f << std::endl;
	flag = bsp(Point(2.0f, 3.0f), Point(4.0f, 4.0f), Point(4.0f, 2.0f), Point(3.99f, 3.0f));	
	if (flag == true)
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point not in triangle" << std::endl;

	std::cout << "TEST7" << std::endl;
	std::cout << "x = " << 4.0f << " y = " << 4.0f << std::endl;
	flag = bsp(Point(2.0f, 3.0f), Point(4.0f, 4.0f), Point(4.0f, 2.0f), Point(4.0f, 4.0f));	
	if (flag == true)
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point not in triangle" << std::endl;

	std::cout << "TEST8" << std::endl;
	std::cout << "x = " << 2.0f << " y = " << 3.0f << std::endl;
	flag = bsp(Point(2.0f, 3.0f), Point(4.0f, 4.0f), Point(4.0f, 2.0f), Point(2.0f, 3.0f));	
	if (flag == true)
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point not in triangle" << std::endl;

	std::cout << "TEST9" << std::endl;
	std::cout << "x = " << 3.5f << " y = " << 2.5f << std::endl;
	flag = bsp(Point(2.0f, 3.0f), Point(4.0f, 4.0f), Point(3.5f, 2.5f), Point(3.5f, 2.5f));	
	if (flag == true)
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point not in triangle" << std::endl;

	std::cout << "TEST10" << std::endl;
	std::cout << "x = " << 4.0f << " y = " << 2.0f << std::endl;
	flag = bsp(Point(2.0f, 3.0f), Point(4.0f, 4.0f), Point(3.5f, 2.5f), Point(4.0f, 2.0f));	
	if (flag == true)
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point not in triangle" << std::endl;
	return (0);
}
