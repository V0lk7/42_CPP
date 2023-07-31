/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:14:56 by jduval            #+#    #+#             */
/*   Updated: 2023/07/31 15:32:39 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.hpp"
#include <new>

int	main(void)
{
	Zombie	*VAL = newZombie("VV");
	randomChump("ALED");
	randomChump("HEY");
	Zombie	*THIBS = newZombie("LeTHIBS");
	randomChump("LE LEO");
	delete VAL;
	delete THIBS;
	return (0);
}
