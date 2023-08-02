/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:10:48 by jduval            #+#    #+#             */
/*   Updated: 2023/08/02 17:59:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int	main(void)
{
	Point	a(1.5f, 1.0f);

	std::cout << "x = " << a.getX().toFloat() << std::endl;
	std::cout << "y = " << a.getY().toFloat() << std::endl;
	float	result = (a.getX() - a.getY()).toFloat();
	std::cout << result << std::endl;
	return (0);
}
