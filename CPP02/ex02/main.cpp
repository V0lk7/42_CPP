/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:57:39 by jduval            #+#    #+#             */
/*   Updated: 2023/08/02 14:15:37 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main( void ) 
{
	{
		std::cout << "Subject test" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
		std::cout << "###############################################" << std::endl;
	}
	{
		std::cout << "INT : a = 2, b = 5" << std::endl;
		std::cout << "max = " << Fixed::max(Fixed(2), Fixed(5)) << std::endl;
		std::cout << "min = " << Fixed::min(Fixed(2), Fixed(5)) << std::endl;
		std::cout << "FLOAT : a = 2.5, b = 5.025" << std::endl;
		std::cout << "max = " << Fixed::max(Fixed(2.5f), Fixed(5.025f)) << std::endl;
		std::cout << "min = " << Fixed::min(Fixed(2.5f), Fixed(5.025f)) << std::endl;
		std::cout << "MIX : a = 2, b = 5.025" << std::endl;
		std::cout << "max = " << Fixed::max(Fixed(2), Fixed(5.025f)) << std::endl;
		std::cout << "min = " << Fixed::min(Fixed(2), Fixed(5.025f)) << std::endl;
		std::cout << "###############################################" << std::endl;
		std::cout << "val = 0 "<< std::endl;
		Fixed	val(0);
		std::cout << "incrementation" << std::endl;
		std::cout << "POST" << std::endl;
		std::cout << val++ << std::endl;
		std::cout << val << std::endl;
		std::cout << "PRE" << std::endl;
		std::cout << ++val << std::endl;
		std::cout << "decrementation" << std::endl;
		std::cout << "POST" << std::endl;
		std::cout << val-- << std::endl;
		std::cout << val << std::endl;
		std::cout << "PRE" << std::endl;
		std::cout << --val << std::endl;

		std::cout << "###############################################" << std::endl;
		std::cout << "Addition INT" << std::endl;
		std::cout << "a = 5, b = 10" << std::endl;
		std::cout << Fixed(5) + Fixed(10) << std::endl;
		std::cout << "Addition FLOAT" << std::endl;
		std::cout << "a = 5.45f, b = 10.5f" << std::endl;
		std::cout << Fixed(5.45f) + Fixed(10.5f) << std::endl;
		std::cout << "Addition MIX" << std::endl;
		std::cout << "a = 5f, b = 10.5f" << std::endl;
		std::cout << Fixed(5) + Fixed(10.5f) << std::endl;

		std::cout << "###############################################" << std::endl;
		std::cout << "Substraction INT" << std::endl;
		std::cout << "a = 5, b = 10" << std::endl;
		std::cout << Fixed(5) - Fixed(10) << std::endl;
		std::cout << "Substraction FLOAT" << std::endl;
		std::cout << "a = 5.45f, b = 10.5f" << std::endl;
		std::cout << Fixed(5.45f) - Fixed(10.5f) << std::endl;
		std::cout << "Substraction MIX" << std::endl;
		std::cout << "a = 5f, b = 10.5f" << std::endl;
		std::cout << Fixed(5) - Fixed(10.5f) << std::endl;

		std::cout << "###############################################" << std::endl;
		std::cout << "Multiplication INT" << std::endl;
		std::cout << "a = 2, b = 3" << std::endl;
		std::cout << Fixed(2) * Fixed(3) << std::endl;
		std::cout << "Multplication FLOAT" << std::endl;
		std::cout << "a = 2.5f, b = 3.0f" << std::endl;
		std::cout << Fixed(2.5f) * Fixed(3.0f) << std::endl;
		std::cout << "Multiplication MIX" << std::endl;
		std::cout << "a = 2, b = 3.5f" << std::endl;
		std::cout << Fixed(2) * Fixed(3.5f) << std::endl;

		std::cout << "###############################################" << std::endl;
		std::cout << "Division INT" << std::endl;
		std::cout << "a = 2, b = 3" << std::endl;
		std::cout << Fixed(2) / Fixed(3) << std::endl;
		std::cout << "Division FLOAT" << std::endl;
		std::cout << "a = 2.5f, b = 3.0f" << std::endl;
		std::cout << Fixed(2.0f) / Fixed(3.0f) << std::endl;
		std::cout << "Division MIX" << std::endl;
		std::cout << "a = 5.5f, b = 2" << std::endl;
		std::cout << Fixed(5.5f) / Fixed(2) << std::endl;

		std::cout << "###############################################" << std::endl;
		std::cout << "Comparator operators"<< std::endl;
		Fixed	i(10);
		Fixed	j(20);

		std::cout << "  >   with i = 10, j = 20" << std::endl;
		if (i > j)
			std::cout << "i sup" << std::endl;
		else
			std::cout << "i not sup" << std::endl;
		i = i + Fixed(30);
		std::cout << "with i = 40, j = 20" << std::endl;
		if (i > j)
			std::cout << "i sup" << std::endl;
		else
			std::cout << "i not sup" << std::endl;
		i = i - Fixed(30);

		std::cout << "###############################################" << std::endl;
		std::cout << "  <   with i = 10, j = 20" << std::endl;
		if (i < j)
			std::cout << "i inf" << std::endl;
		else
			std::cout << "i not inf" << std::endl;
		i = i + Fixed(30);
		std::cout << "with i = 40, j = 20" << std::endl;
		if (i < j)
			std::cout << "i inf" << std::endl;
		else
			std::cout << "i not inf" << std::endl;
		i = i - Fixed(30);

		std::cout << "###############################################" << std::endl;
		std::cout << "  <=   with i = 10, j = 20" << std::endl;
		if (i <= j)
			std::cout << "i inf or equal" << std::endl;
		else
			std::cout << "i not inf or equal" << std::endl;
		i = i + Fixed(10);
		std::cout << "with i = 20, j = 20" << std::endl;
		if (i <= j)
			std::cout << "i inf or equal" << std::endl;
		else
			std::cout << "i not inf or equal" << std::endl;
		i = i - Fixed(10);

		std::cout << "###############################################" << std::endl;
		std::cout << "  >=   with i = 10, j = 20" << std::endl;
		if (i >= j)
			std::cout << "i sup or equal" << std::endl;
		else
			std::cout << "i not sup or equal" << std::endl;
		i = i + Fixed(10);
		std::cout << "with i = 20, j = 20" << std::endl;
		if (i >= j)
			std::cout << "i sup or equal" << std::endl;
		else
			std::cout << "i not sup or equal" << std::endl;
		i = i - Fixed(10);

		std::cout << "###############################################" << std::endl;
		std::cout << "  ==   with i = 10, j = 20" << std::endl;
		if (i == j)
			std::cout << "i equal" << std::endl;
		else
			std::cout << "i not equal" << std::endl;
		i = i + Fixed(10);
		std::cout << "with i = 20, j = 20" << std::endl;
		if (i == j)
			std::cout << "i equal" << std::endl;
		else
			std::cout << "i equal" << std::endl;
		i = i - Fixed(10);

		std::cout << "###############################################" << std::endl;
		std::cout << "  !=   with i = 10, j = 20" << std::endl;
		if (i != j)
			std::cout << "i not equal" << std::endl;
		else
			std::cout << "i equal" << std::endl;
		i = i + Fixed(10);
		std::cout << "with i = 20, j = 20" << std::endl;
		if (i != j)
			std::cout << "i not equal" << std::endl;
		else
			std::cout << "i equal" << std::endl;
		i = i - Fixed(10);
	}
	return (0);
}
