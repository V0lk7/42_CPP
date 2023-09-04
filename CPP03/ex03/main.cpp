/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:46:08 by jduval            #+#    #+#             */
/*   Updated: 2023/09/04 09:06:34 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	/*
	DiamondTrap	joe("joe");

	joe.whoAmI();
	joe.displayStats();
	joe.attack("nobody");
	joe.beRepaired(10);
	joe.guardGate();
	joe.takeDamage(10);
	*/
	DiamondTrap	joe("joe");
	DiamondTrap francis;

	francis.displayStats();
	std::cout << "--------------------------------------" << std::endl;
	francis = joe;
	joe.SetName("hey");
	std::cout << "--------------------------------------" << std::endl;
	francis.displayStats();
	std::cout << "--------------------------------------" << std::endl;
	joe.displayStats();
	std::cout << "--------------------------------------" << std::endl;
	francis.displayStats();

	return (0);
}
