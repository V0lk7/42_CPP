/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:56:23 by jduval            #+#    #+#             */
/*   Updated: 2023/07/25 11:29:09 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

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
