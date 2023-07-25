/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:03:58 by jduval            #+#    #+#             */
/*   Updated: 2023/07/25 09:45:41 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>
#include <sstream>

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*new_zombie;

	if (N <= 0)
		return (NULL);
	new_zombie = new (std::nothrow) Zombie[N];
	if (new_zombie == NULL)
		return (NULL);
	for (int i = 0; i < N; i++)
	{
		std::ostringstream	convert;
		std::string	result;
		convert << i;
		result = name;
		result += convert.str();
		new_zombie[i].get_a_name(result);
		new_zombie[i].announce();
	}
	return (new_zombie);
}
