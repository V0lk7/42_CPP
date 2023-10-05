/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:35:22 by jduval            #+#    #+#             */
/*   Updated: 2023/10/05 15:07:28 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Utilities.hpp"
#include <time.h> 

static bool	CheckArgsNumber(int ac);

int	main(int ac, char **av)
{
	if (CheckArgsNumber(ac) == false)
		return (1);

	std::vector<int>	UnsortedVectorNumbers;
	std::vector<int>	SortedVectorNumbers;
	std::deque<int>		UnsortedDequeNumbers;
	std::deque<int>		SortedDequeNumbers;
	clock_t				ClockTime;
	float				VectorTime;
	float				DequeTime;

	try{
		std::cout << "====================================================" << std::endl;
		std::cout << "Using Vector" << std::endl;
		ClockTime = clock();
		CreateNumberVector(UnsortedVectorNumbers, av);
		MergeInsertSortVector(UnsortedVectorNumbers, SortedVectorNumbers);
		VectorTime = (clock() - ClockTime);
		DisplaySortedNumbers(SortedVectorNumbers);

		std::cout << "====================================================" << std::endl;
		std::cout << "Using Deque" << std::endl;
		ClockTime = clock();
		CreateNumberDeque(UnsortedDequeNumbers, av);
		MergeInsertSortDeque(UnsortedDequeNumbers, SortedDequeNumbers);
		DequeTime = (clock() - ClockTime);
		DisplaySortedNumbers(SortedDequeNumbers);
		std::cout << "====================================================" << std::endl;

		VectorTime = (VectorTime / CLOCKS_PER_SEC) * 1000;
		DequeTime = (DequeTime / CLOCKS_PER_SEC) * 1000;
		std::cout << "Time of sorting using a vector : " << VectorTime << " ms" << std::endl;
		std::cout << "Time of sorting using a deque : " << DequeTime << " ms" << std::endl;
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
