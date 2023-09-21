/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:36:27 by jduval            #+#    #+#             */
/*   Updated: 2023/09/21 12:58:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyFind.hpp"

int	main(void)
{
	std::vector<int>	container;

	for (int i = 0; i < 5; i++)
		container.push_back(i);
	std::vector<int>::iterator	itBegin = container.begin();
	std::vector<int>::iterator	itEnd = container.end();
	while (itBegin != itEnd){
		std::cout << *itBegin << " ";
		itBegin++;
	}
	std::cout << std::endl;
	std::cout << "Find 8 : " << std::boolalpha << easyFind(container, 8) << std::endl;
	std::cout << "Find 2 : " << std::boolalpha << easyFind(container, 2) << std::endl;
	std::vector<double>	empty;
	std::cout << "Find 5 : " << std::boolalpha << easyFind(container, 5) << std::endl;
	return (0);
}
