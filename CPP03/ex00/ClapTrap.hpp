/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/08/03 16:42:07 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap
{
	private	:

		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public	:

		ClapTrap();					//Default constructor
		ClapTrap(ClapTrap const &src);	//Copy constructor
		~ClapTrap();					//Destructor
		ClapTrap(std::string);
		void	Setname(std::string);
		std::string	Getname(void) const;
		ClapTrap	&operator=(ClapTrap const &rhs);
};

#endif
