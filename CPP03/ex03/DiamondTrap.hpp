/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/09/04 09:06:33 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private	:
		
		std::string	_diamond_name;
		using FragTrap::_hit_points;
		using ScavTrap::_energy_points;
		using FragTrap::_attack_damage;

	public	:

		DiamondTrap();						//Default constructor
		DiamondTrap(DiamondTrap const &src);	//Copy constructor
		~DiamondTrap();					//Destructor
		DiamondTrap	&operator=(DiamondTrap const &rhs);

		DiamondTrap(std::string);

		using ScavTrap::attack;
		using ClapTrap::beRepaired;
		using ClapTrap::takeDamage;
		using FragTrap::highFivesGuys;
		using ScavTrap::guardGate;

		std::string	getDiamondName(void) const;
		void	whoAmI(void) const;
		void	SetName(std::string name);
};

#endif
