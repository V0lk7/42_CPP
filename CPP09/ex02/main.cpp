/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:35:22 by jduval            #+#    #+#             */
/*   Updated: 2023/10/05 12:09:23 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Utilities.hpp"

static bool	CheckArgsNumber(int ac);

int	main(int ac, char **av)
{
	if (CheckArgsNumber(ac) == false)
		return (1);

	std::vector<int>	UnsortedVectorNumbers;
	std::deque<int>		UnsortedDequeNumbers;
	double				VectorTime;
	double				DequeTime;

	try{
		CreateNumberVector(UnsortedVectorNumbers, av);
		CreateDeque(UnsortedVectorNumbers, UnsortedDequeNumbers);
		VectorTime = MergeInsertSortVector(UnsortedVectorNumbers);
		DequeTime = MergeInsertSortdeque(UnsortedDequeNumbers);
		std::cout << "VectorTime = " << std::setprecision(10) << VectorTime << std::endl;
		std::cout << "DequeTime = " << std::setprecision(10) << DequeTime << std::endl;
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
