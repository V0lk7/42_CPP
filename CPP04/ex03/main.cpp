/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:36:57 by jduval            #+#    #+#             */
/*   Updated: 2023/08/21 15:43:54 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int	main(void)
{
	AMateria	*test = new Ice("Hey");

	ICharacter	*persona1 = new Character("1");
	ICharacter	*persona2 = new Character("2");
	persona1->equip(test);
	persona2->equip(test);
	persona1->use(0, *persona2);
	*persona1 = *persona2;
	delete persona1;
	delete persona2;
	return (0);
}
