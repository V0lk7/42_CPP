/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:14:56 by jduval            #+#    #+#             */
/*   Updated: 2023/07/25 09:46:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.hpp"
#include <new>

int	main(void)
{
	Zombie	*VAL = newZombie("VAL");
	randomChump("RAPH");
	randomChump("FRANCIS");
	Zombie	*THIBS = newZombie("LeTHIBS");
	randomChump("EL_KENNY");
	delete VAL;
	delete THIBS;
	return (0);
}