/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:36:57 by jduval            #+#    #+#             */
/*   Updated: 2023/09/05 10:45:47 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

static void	test(void)
{
	Character		*joe = new Character("joe");
	Character		*dave = new Character("dave");
	AMateria		*weapon;
	MateriaSource	*source = new MateriaSource();
	MateriaSource	*deepcopy = new MateriaSource();

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			source->learnMateria(new Ice());
			deepcopy->learnMateria(new Ice());
		}
		else
		{
			source->learnMateria(new Cure());
			deepcopy->learnMateria(new Cure());
		}
	}

	std::cout << "------------------Test deepcopy Materiasource--------------------" << std::endl;
	*deepcopy = *source;
	std::cout << "Deepcopy ->" << std::endl << *deepcopy << std::endl;
	std::cout << "Source ->" << std::endl << *source << std::endl;

	std::cout << "-----------------Test deepcopy Character--------------------" << std::endl;

	weapon = source->createMateria("cure");
	joe->equip(weapon);
	weapon = source->createMateria("ice");
	joe->equip(weapon);

	weapon = source->createMateria("cure");
	dave->equip(weapon);
	weapon = source->createMateria("ice");
	dave->equip(weapon);

	std::cout << *joe << std::endl;
	std::cout << *dave << std::endl;

	weapon = source->createMateria("ice");
	joe->equip(weapon);
	*dave = *joe;
	std::cout << "---JOE---" << std::endl;
	std::cout << *joe << std::endl;
	std::cout << "---DAVE---" << std::endl;
	std::cout << *dave << std::endl;

	std::cout << "-----------------Test Use--------------------" << std::endl;
	joe->use(0, *dave);
	joe->use(2, *dave);
	joe->use(2147483647, *dave);
	joe->use(-2147483648, *dave);
	std::cout << "test use on null target" << std::endl;
	Character	*null = NULL;
	joe->use(0, *null);

	std::cout << "-----------------learn and equip full--------------------" << std::endl;
	source->learnMateria(new Ice());
	source->learnMateria(new Ice());
	source->learnMateria(new Ice());
	weapon = source->createMateria("ice");
	joe->equip(weapon);
	weapon = source->createMateria("cure");
	joe->equip(weapon);
	delete weapon;

	std::cout << "-----------------unequip--------------------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		AMateria	*tmp = joe->getItem(i);
		if (tmp == NULL)
			continue ;
		else
		{
			joe->unequip(i);
			delete tmp;
		}
	}
	std::cout << "---JOE---" << std::endl;
	std::cout << *joe << std::endl;

	delete deepcopy;
	delete source;
	delete joe;
	delete dave;
}

int	main(void)
{
	test();
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	return (0);
}
