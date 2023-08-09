/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:36:57 by jduval            #+#    #+#             */
/*   Updated: 2023/08/09 17:10:28 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int	main(void)
{
	AMateria	*test = new Cure("Hey");

	std::cout << test->getType() << std::endl;

	delete test;
	return (0);
}
