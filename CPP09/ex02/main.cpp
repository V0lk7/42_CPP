/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:35:22 by jduval            #+#    #+#             */
/*   Updated: 2023/10/12 14:04:30 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "PmergeMe.hpp"
#include <time.h> 

static bool	CheckArgsNumber(int ac);
static bool	AllElementsAreHere(std::vector<int> &Unsorted, std::vector<int> &Sorted);

int	main(int ac, char **av)
{
	if (CheckArgsNumber(ac) == false)
		return (1);

//	std::deque<int>		UnsortedDequeNumbers;
//	std::deque<int>		SortedDequeNumbers;
	clock_t				ClockTime;
	float				VectorTime;
//	float				DequeTime;

	try{
//		std::cout << "====================================================" << std::endl;
//		std::cout << "Using Vector" << std::endl;

		std::vector<int>	UnsortedVector;
		std::vector<int>	SortedVector;

		ClockTime = clock();
		CreateNumbers(UnsortedVector, av);
		MergeInsertSort(UnsortedVector, SortedVector);
		VectorTime = (clock() - ClockTime);

		std::cout << "Before :" << std::endl;
		DisplaySortedNumbers(UnsortedVector);
		std::cout << "After :" << std::endl;
		DisplaySortedNumbers(SortedVector);
//		std::cout << "====================================================" << std::endl;
/*
		std::cout << "Using Deque" << std::endl;
		ClockTime = clock();
		CreateNumberDeque(UnsortedDequeNumbers, av);
		MergeInsertSortDeque(UnsortedDequeNumbers, SortedDequeNumbers);
		DequeTime = (clock() - ClockTime);
		DisplaySortedNumbers(SortedDequeNumbers);
		std::cout << "====================================================" << std::endl;
*/
		if (VerifySorted(SortedVector) == true &&
			AllElementsAreHere(UnsortedVector, SortedVector) == true)
			std::cout << "Vector is Sorted" << std::endl;
		else
			std::cout << "Vector isn't Sorted" << std::endl;
//		if (VerifySorted(SortedDequeNumbers) == true)
//			std::cout << "Deque is Sorted" << std::endl;
//		else
//			std::cout << "Deque isn't Sorted" << std::endl;

		VectorTime = (VectorTime / CLOCKS_PER_SEC) * 1000000;
//		DequeTime = (DequeTime / CLOCKS_PER_SEC) * 1000000;
		std::cout << "Time of sorting using a vector : " << VectorTime << " μs" << std::endl;
//		std::cout << "Time of sorting using a deque : " << DequeTime << " μs" << std::endl;
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

static void	loopAled(int Value, std::vector<int> &lol);

static bool	AllElementsAreHere(std::vector<int> &Unsorted, std::vector<int> &Sorted)
{
	std::vector<int>	SortedB(Sorted);

	for (size_t i = 0; i < Unsorted.size(); i++)
		loopAled(Unsorted[i], SortedB);
	if (SortedB.size() == 0)
		return (true);
	else
		return (false);
}

static void	loopAled(int Value, std::vector<int> &lol)
{
	for (size_t j = 0; j < lol.size(); j++)
	{
		if (Value == lol[j])
		{
			lol.erase(lol.begin() + j, lol.begin() + j + 1);
			break ;
		}
	}
	return ;
}
