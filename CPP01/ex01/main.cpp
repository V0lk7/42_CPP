/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:14:56 by jduval            #+#    #+#             */
/*   Updated: 2023/07/25 09:02:44 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.hpp"
#include <new>
#include <iostream>

int	main(void)
{
	Zombie	*hordes;
	int		N;

	N = 0;
	hordes = zombieHorde(N, "ROGER");
	if (hordes == NULL)
		std::cout << "Hordes == NULL " << "Bad allocation for N = " << N << std::endl;
	else
		delete[] hordes;
	N = -10;
	hordes = zombieHorde(N, "ROGER");
	if (hordes == NULL)
		std::cout << "Hordes == NULL " << "Bad allocation for N = " << N << std::endl;
	else
		delete[] hordes;
	N = 2147483647;
	hordes = zombieHorde(N, "ROGER");
	if (hordes == NULL)
		std::cout << "Hordes == NULL " << "Bad allocation for N = " << N << std::endl;
	else
		delete[] hordes;
	N = 10;
	hordes = zombieHorde(N, "ROGER");
	if (hordes == NULL)
		std::cout << "Hordes == NULL " << "Bad allocation for N = " << N << std::endl;
	else
	{
		int	i = 0;
		while (i < N)
			i++;
		std::cout << "i = " << i << std::endl;
		delete[] hordes;
	}
	return (0);
}
