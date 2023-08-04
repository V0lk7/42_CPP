/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/08/04 19:03:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public Claptrap 
{
	public	:

		ScavTrap();						//Default constructor
		ScavTrap(ScavTrap const &src);	//Copy constructor
		~ScavTrap();					//Destructor
		ScavTrap(std::string);

		void	guardGate();

		void	attack(std::string const &target) override;
		void	takeDamage(unsigned int amount) override;
		void	beRepaired(unsigned int amount) override;

		ScavTrap	&operator=(ScavTrap const &rhs);
};

#endif
