/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:03:58 by jduval            #+#    #+#             */
/*   Updated: 2023/08/03 16:45:07 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

Zombie	*newZombie(std::string name)
{
	Zombie	*new_zombie;

	new_zombie = new Zombie(name);
	new_zombie->announce();
	return (new_zombie);
}
