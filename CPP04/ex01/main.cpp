/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:34:09 by jduval            #+#    #+#             */
/*   Updated: 2023/09/05 13:32:15 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int	main(void)
{
	{
		std::cout << "-------------TEST SUBJECT------------------" << std::endl;

		Animal	*array[10];
		for (int i = 0; i < 10; i++)
		{
			if (i < 10 / 2)
				array[i] = new Cat();
			else
				array[i] = new Dog();
		}
		for (int i = 0; i < 10; i++)
			delete array[i];

		std::cout << "------------------------------------" << std::endl;
		const	Animal	*j = new Dog();
		const	Animal	*i = new Cat();
		delete	j;
		delete	i;
		std::cout << "------------------------------------" << std::endl;
	}
	{

		std::cout << "------------------TEST DEEP COPY--------------" << std::endl;
		Cat	*chacha = new Cat();

		std::cout << "Type = " << chacha->getType() << std::endl;
		for (int i = 0; i < 100; i++)
			chacha->setIdeaInBrain(i, "a");
		Cat	*chat	= new Cat(*chacha);
		for (int i = 0; i < 100; i++)
		{
			if (i > 30 && i < 80)
				continue ;
			std::cout << "chacha :" << std::endl;
			chacha->printIdea(i);
			std::cout << "chat :" << std::endl;
			chat->printIdea(i);
		}
		std::cout	<< "modification of the value at the index = 0 in chacha brain"
					<< std::endl;
		std::cout << "chacha :" << std::endl;
		chacha->setIdeaInBrain(0, "B");
		chacha->printIdea(0);
		std::cout << "chat :" << std::endl;
		chat->printIdea(0);

		Cat	*test = new Cat();
		for (int i = 0; i < 100; i++)
			test->setIdeaInBrain(i, "Z");
		*chat = *test;
		for (int i = 0; i < 100; i++)
		{
			if (i > 30 && i < 80)
				continue ;
			chat->printIdea(i);
		}
		delete chacha;
		delete chat;
		delete test;
	}
	return 0;
}
