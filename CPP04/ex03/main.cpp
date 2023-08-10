/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:36:57 by jduval            #+#    #+#             */
/*   Updated: 2023/08/10 10:27:10 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int	main(void)
{
	AMateria	*test = new Cure("Hey");
	AMateria	*lol = new Ice;

	Cure = Ice;

	std::cout << test->getType() << std::endl;

	delete test;
	return (0);
}
