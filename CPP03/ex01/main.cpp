/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:46:08 by jduval            #+#    #+#             */
/*   Updated: 2023/08/07 08:32:19 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	n1("Steve");
	ScavTrap	n2("Marty");

	n1.guardGate();
	n2.attack(n1.getName());
	n1.beRepaired(10);
	n1.displayStats();
	n2.displayStats();
	return (0);
}
