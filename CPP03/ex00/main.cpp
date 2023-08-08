/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:46:08 by jduval            #+#    #+#             */
/*   Updated: 2023/08/08 11:12:28 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	n1("Steve");
	ClapTrap	n2("James");
	ClapTrap	n3("Harry");

	ClapTrap	n4 = n1;
	n1.attack(n2.getName());
	n2.takeDamage(n1.getAttackDamage());
	n2.attack(n3.getName());
	n3.beRepaired(10);
	n1.displayStats();
	n2.displayStats();
	n3.displayStats();
	n4.displayStats();
	return (0);
}
