/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:35:22 by jduval            #+#    #+#             */
/*   Updated: 2023/10/12 15:01:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "PmergeMe.hpp"
#include <time.h> 

static bool	CheckArgsNumber(int ac);
static bool	AllElementsAreHere(std::vector<int> &Unsorted, std::vector<int> &Sorted);
static bool	AllElementsAreHere(std::deque<int> &Unsorted, std::deque<int> &Sorted);

int	main(int ac, char **av)
{
	if (CheckArgsNumber(ac) == false)
		return (1);

	std::deque<int>		UnsortedDeque, SortedDeque;
	std::vector<int>	UnsortedVector, SortedVector;
	clock_t				ClockTime;
	float				VectorTime, DequeTime;

	try{
		ClockTime = clock();
		CreateNumbers(UnsortedVector, av);
		MergeInsertSort(UnsortedVector, SortedVector);
		VectorTime = (clock() - ClockTime);

		std::cout << "Before :" << std::endl;
		Display(UnsortedVector);
		std::cout << "After :" << std::endl;
		Display(SortedVector);

		ClockTime = clock();
		CreateNumbers(UnsortedDeque, av);
		MergeInsertSort(UnsortedDeque, SortedDeque);
		DequeTime = (clock() - ClockTime);

		if (VerifySorted(SortedVector) == true &&
			AllElementsAreHere(UnsortedVector, SortedVector) == true)
			std::cout << "Vector is Sorted" << std::endl;
		else
			std::cout << "Vector isn't Sorted" << std::endl;

		if (VerifySorted(SortedDeque) == true &&
			AllElementsAreHere(UnsortedDeque, SortedDeque) == true)
			std::cout << "Deque is Sorted" << std::endl;
		else
			std::cout << "Deque isn't Sorted" << std::endl;

		VectorTime = (VectorTime / CLOCKS_PER_SEC) * 1000000;
		DequeTime = (DequeTime / CLOCKS_PER_SEC) * 1000000;

		std::cout	<< "Time to process a range of " << UnsortedVector.size()
					<< " elements with std::vector : " << VectorTime << " μs" << std::endl;
		std::cout	<< "Time to process a range of " << UnsortedDeque.size()
					<< " elements with std::deque : " << DequeTime << " μs" << std::endl;
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

static void	FindValue(int Value, std::vector<int> &Sorted);
static void	FindValue(int Value, std::deque<int> &Sorted);

static bool	AllElementsAreHere(std::vector<int> &Unsorted, std::vector<int> &Sorted)
{
	std::vector<int>	SortedB(Sorted);

	for (size_t i = 0; i < Unsorted.size(); i++)
		FindValue(Unsorted[i], SortedB);
	if (SortedB.size() == 0)
		return (true);
	else
		return (false);
}

static bool	AllElementsAreHere(std::deque<int> &Unsorted, std::deque<int> &Sorted)
{
	std::deque<int>	SortedB(Sorted);

	for (size_t i = 0; i < Unsorted.size(); i++)
		FindValue(Unsorted[i], SortedB);
	if (SortedB.size() == 0)
		return (true);
	else
		return (false);
}

static void	FindValue(int Value, std::vector<int> &Sorted)
{
	for (size_t j = 0; j < Sorted.size(); j++)
	{
		if (Value == Sorted[j])
		{
			Sorted.erase(Sorted.begin() + j, Sorted.begin() + j + 1);
			break ;
		}
	}
	return ;
}

static void	FindValue(int Value, std::deque<int> &Sorted)
{
	for (size_t j = 0; j < Sorted.size(); j++)
	{
		if (Value == Sorted[j])
		{
			Sorted.erase(Sorted.begin() + j, Sorted.begin() + j + 1);
			break ;
		}
	}
	return ;
}
