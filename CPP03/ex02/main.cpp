/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:46:08 by jduval            #+#    #+#             */
/*   Updated: 2023/08/07 15:23:31 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	n1("Steve");
	FragTrap	n2("Marty");

	n1.highFivesGuys();
	n2.attack(n1.getName());
	n1.beRepaired(10);
	n1.displayStats();
	n2.displayStats();
	return (0);
}
