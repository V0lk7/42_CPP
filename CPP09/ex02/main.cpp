/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:35:22 by jduval            #+#    #+#             */
/*   Updated: 2023/10/02 15:57:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Utilities.hpp"

static bool	CheckArgsNumber(int ac);
//static void	DisplayVList(std::vector<int> &VList);

int	main(int ac, char **av)
{
	if (CheckArgsNumber(ac) == false)
		return (1);

	std::vector<int>	VList;
	try{
		CreateVList(VList, av);
		MergeInsertSortVector(VList);
	}
	catch (std::exception &e){
		std::cout << "PmergMe: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}

static bool	CheckArgsNumber(int ac)
{
	if (ac <= 2)
	{
		std::cout << "Need at least two arguments." << std::endl;
		return (false);
	}
	return (true);
}
/*
static void	DisplayVList(std::vector<int> &VList)
{
	std::vector<int>::iterator	ItBegin = VList.begin();

	while (ItBegin != VList.end())
	{
		std::cout << (*ItBegin) << " ";
		ItBegin++;
	}
	std::cout << std::endl;
}*/
