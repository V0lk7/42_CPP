/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlgorithmForDeque.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:57:21 by jduval            #+#    #+#             */
/*   Updated: 2023/10/05 12:09:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include "Utilities.hpp"

static void	Displaydeque(std::deque<int> &Maxdeque);
static void	DisplayPairdeque(std::deque<Content> &Pairdeque);
static void	Mergedeque(std::deque<int> &Maxdeque, std::deque<int> &Sorteddeque);

static bool	is_sorted(std::deque<int> &Sorteddeque);

static void	InsertOddElement(int Element, std::deque<int> &Sorteddeque);

double	MergeInsertSortdeque(std::deque<int> &Unsorteddeque)
{
	std::deque<int>	Sorteddeque;
	time_t				now = time(NULL);
	double				TimeElapsed;

	Mergedeque(Unsorteddeque, Sorteddeque);
	if (Unsorteddeque.size() % 2 != 0)
		InsertOddElement(Unsorteddeque.back(), Sorteddeque);
	TimeElapsed = difftime(time(NULL), now);
	if (is_sorted(Sorteddeque) == true && Unsorteddeque.size() == Sorteddeque.size())
		std::cout << "It's Fucking Sorted OMG !!!" << std::endl;
	else
		std::cout << "Aled ça marche pas...." << std::endl;
	return (TimeElapsed);
}

static bool	is_sorted(std::deque<int> &Sorteddeque)
{
	for (size_t i = 0; i < Sorteddeque.size(); i++)
	{
		if (i + 1 < Sorteddeque.size() && Sorteddeque[i] > Sorteddeque[i + 1])
			return (false);
	}
	return (true);
}

static void	InsertSortdeque(	std::deque<int> &SubMaxdeque,
								std::deque<Content> &Pairdeque,
								std::deque<int> &Sorteddeque);

static void	Mergedeque(std::deque<int> &Maxdeque, std::deque<int> &Sorteddeque)
{
	std::deque<Content>		Pairdeque;
	std::deque<int>			SubMaxdeque;

	CreatedequePairs(Maxdeque, Pairdeque);
	CreateSubMaxdeque(Pairdeque, SubMaxdeque);
//	DisplayPairdeque(Pairdeque);
//	Displaydeque(SubMaxdeque);
	if (Maxdeque.size() > 2)
		Mergedeque(SubMaxdeque, Sorteddeque);
	InsertSortdeque(SubMaxdeque, Pairdeque, Sorteddeque);
}

static void	InsertFirstPair(Content &Pair, std::deque<int> &Sorteddeque);
static void	InsertPendMin(	std::deque<Content> &Pairdeque,
							std::deque<int> &Sorteddeque);

static void	InsertSortdeque(	std::deque<int> &SubMaxdeque,
								std::deque<Content> &Pairdeque,
								std::deque<int> &Sorteddeque)
{
//	std::cout << "===================================" << std::endl;
//	DisplayPairdeque(Pairdeque);
	int	OddElement;

	if (Pairdeque.size() == 1)
		InsertFirstPair(Pairdeque[0], Sorteddeque);
	else
		InsertPendMin(Pairdeque, Sorteddeque);
	if (SubMaxdeque.size() % 2 != 0 && SubMaxdeque.size() != 1)
	{
		OddElement = SubMaxdeque.back();
		InsertOddElement(OddElement, Sorteddeque);
	}
//	Displaydeque(Sorteddeque);
//	std::cout << "===================================" << std::endl;
}

static void	InsertOddElement(int Element, std::deque<int> &Sorteddeque)
{
	std::deque<int>::iterator	NewInsertion;

	NewInsertion = BinarySearch(Element, Sorteddeque);
	Sorteddeque.insert(NewInsertion, Element);
}

static void	InsertFirstPair(Content &Pair, std::deque<int> &Sorteddeque)
{
	Sorteddeque.push_back(Pair.min);
	Sorteddeque.push_back(Pair.max);
	return ;
}

static void	InsertPendMin(	std::deque<Content> &Pairdeque,
							std::deque<int> &Sorteddeque)
{
	std::deque<int>::iterator		NewInsertion;
	std::deque<Content>::iterator	ItLeft;
	std::deque<Content>::iterator	ItRight;
	std::deque<Content>::iterator	ItTmp;
	int		JacobsthalNumber;
	int		i = 1;

	while (Pairdeque.size() > 1)
	{
		JacobsthalNumber = JacobsthalGenerator(i);
		ItLeft = Pairdeque.begin();
		if (JacobsthalNumber * 2 >= (int)Pairdeque.size())
			ItRight = ItLeft + Pairdeque.size() - 1;
		else
			ItRight = ItLeft + JacobsthalNumber - 1;
		ItTmp = ItRight + 1;
		while (ItRight != ItLeft)
		{
			NewInsertion = BinarySearchPosition((*ItRight), Sorteddeque);
			Sorteddeque.insert(NewInsertion, ItRight->min);
			ItRight--;
		}
		NewInsertion = BinarySearchPosition((*ItLeft), Sorteddeque);
		Sorteddeque.insert(NewInsertion, ItLeft->min);
		Pairdeque.erase(Pairdeque.begin(), ItTmp);
		i++;
	}
	return ;
}

/*========================Displaydeques===============================*/

static void	DisplayPairdeque(std::deque<Content> &Pairdeque)
{
	for (size_t i = 0; i < Pairdeque.size(); i++)
		std::cout << '(' << Pairdeque[i].max << ',' << Pairdeque[i].min << ')' << ' ';
	std::cout << std::endl;
}

static void	Displaydeque(std::deque<int> &Maxdeque)
{
	for (size_t i = 0; i < Maxdeque.size(); i++)
		std::cout << Maxdeque[i] << ' ';
	std::cout << std::endl;
}
