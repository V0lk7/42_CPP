/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:56:23 by jduval            #+#    #+#             */
/*   Updated: 2023/07/27 10:13:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private	:
		std::string	name;
	public	:
		Zombie();
		~Zombie();
		void 	announce(void);
		void	get_a_name(std::string);
};

#endif
