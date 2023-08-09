/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:14:56 by jduval            #+#    #+#             */
/*   Updated: 2023/08/09 13:32:46 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.hpp"
#include <iostream>

int	main(void)
{
	Zombie	*hordes;
	int		N[] = {0, -10, 2147483647, 10};
	int		len = 4;

	for (int i = 0; i < len; i++)
	{
		hordes = zombieHorde(N[i], "ROGER");
		if (hordes == NULL)
			std::cout << "Hordes == NULL " << "Bad allocation for N = " << N[i] << std::endl;
		else
			delete[] hordes;
	}
	return (0);
}
