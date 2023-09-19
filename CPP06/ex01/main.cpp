/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:51:08 by jduval            #+#    #+#             */
/*   Updated: 2023/09/19 11:06:45 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

static void	display(Data *ptr)
{
	std::cout << ptr->a << std::endl;
	std::cout << ptr->b << std::endl;
	return ;
}

int	main(void)
{
	Data		test;
	Data	*test2;
	uintptr_t	convert;

	test.a = 42;
	test.b = 'H';
	display(&test);
	convert = Serializer::serialize(&test);
	std::cout << "uintptr_t convert = " << convert << std::endl;
	test2 = Serializer::deserialize(convert);
	display(test2);
	return (0);
}
