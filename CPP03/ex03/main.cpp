/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:46:08 by jduval            #+#    #+#             */
/*   Updated: 2023/08/08 11:46:05 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	joe("joe");

	joe.whoAmI();
	joe.displayStats();
	joe.attack("nobody");
	joe.beRepaired(10);
	joe.guardGate();
	joe.takeDamage(10);
	return (0);
}
