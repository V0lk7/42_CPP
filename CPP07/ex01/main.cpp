/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:55:02 by jduval            #+#    #+#             */
/*   Updated: 2023/09/20 11:16:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

static void	OnInt(int &a)
{
	a++;
}

static void	OnChar(char &a)
{
	a++;
}

int	main(void)
{
	{
		int	array[3] = {1, 2, 3};

		for (int i = 0; i < 3; i++)
			std::cout << array[i] << " ";
		std::cout << std::endl;
		iter(array, 3, &OnInt);
		for (int i = 0; i < 3; i++)
			std::cout << array[i] << " ";
		std::cout << std::endl;
	}
	{
		char	array[3] = {'a', 'A', '0'};

		for (int i = 0; i < 3; i++)
			std::cout << array[i] << " ";
		std::cout << std::endl;
		iter(array, 3, &OnChar);
		for (int i = 0; i < 3; i++)
			std::cout << array[i] << " ";
		std::cout << std::endl;
	}
	return (0);
}
