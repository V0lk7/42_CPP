/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/08/04 18:42:27 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	protected	:

		std::string		_name;
		int				_hit_points;
		int				_energy_points;
		int				_attack_damage;

	public	:

		ClapTrap();					//Default constructor
		ClapTrap(ClapTrap const &src);	//Copy constructor
		~ClapTrap();					//Destructor
		ClapTrap(std::string);

		virtual void	attack(std::string const &target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);

		int				getAttackDamage() const;
		int				getEnergyPoints(void) const;
		int				getHitPoints(void) const;
		std::string		getName() const;

		void			displayStats(void) const;
		
		ClapTrap	&operator=(ClapTrap const &rhs);
};

#endif
