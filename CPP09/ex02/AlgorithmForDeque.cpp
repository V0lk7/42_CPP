/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlgorithmForDeque.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:57:21 by jduval            #+#    #+#             */
/*   Updated: 2023/10/05 14:23:29 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include "Utilities.hpp"

static void	MergeDeque(std::deque<int> &MaxDeque, std::deque<int> &SortedDeque);
static void	InsertOddElement(int Element, std::deque<int> &SortedDeque);

void	MergeInsertSortDeque(std::deque<int> &UnsortedDeque, std::deque<int> &SortedDeque)
{
//	std::deque<int>	SortedDeque;

	MergeDeque(UnsortedDeque, SortedDeque);
	if (UnsortedDeque.size() % 2 != 0)
		InsertOddElement(UnsortedDeque.back(), SortedDeque);
	return ;
}

static void	InsertSortDeque(	std::deque<int> &SubMaxDeque,
								std::deque<Content> &PairDeque,
								std::deque<int> &SortedDeque);

static void	MergeDeque(std::deque<int> &MaxDeque, std::deque<int> &SortedDeque)
{
	std::deque<Content>		PairDeque;
	std::deque<int>			SubMaxDeque;

	CreateDequePairs(MaxDeque, PairDeque);
	CreateSubMaxDeque(PairDeque, SubMaxDeque);
	if (MaxDeque.size() > 2)
		MergeDeque(SubMaxDeque, SortedDeque);
	InsertSortDeque(SubMaxDeque, PairDeque, SortedDeque);
}

static void	InsertFirstPair(Content &Pair, std::deque<int> &SortedDeque);
static void	InsertPendMin(	std::deque<Content> &PairDeque,
							std::deque<int> &SortedDeque);

static void	InsertSortDeque(	std::deque<int> &SubMaxDeque,
								std::deque<Content> &PairDeque,
								std::deque<int> &SortedDeque)
{
	int	OddElement;

	if (PairDeque.size() == 1)
		InsertFirstPair(PairDeque[0], SortedDeque);
	else
		InsertPendMin(PairDeque, SortedDeque);
	if (SubMaxDeque.size() % 2 != 0 && SubMaxDeque.size() != 1)
	{
		OddElement = SubMaxDeque.back();
		InsertOddElement(OddElement, SortedDeque);
	}
}

static void	InsertOddElement(int Element, std::deque<int> &SortedDeque)
{
	std::deque<int>::iterator	NewInsertion;

	NewInsertion = BinarySearch(Element, SortedDeque);
	SortedDeque.insert(NewInsertion, Element);
}

static void	InsertFirstPair(Content &Pair, std::deque<int> &SortedDeque)
{
	SortedDeque.push_back(Pair.min);
	SortedDeque.push_back(Pair.max);
	return ;
}

static void	InsertPendMin(	std::deque<Content> &PairDeque,
							std::deque<int> &SortedDeque)
{
	std::deque<int>::iterator		NewInsertion;
	std::deque<Content>::iterator	ItLeft;
	std::deque<Content>::iterator	ItRight;
	std::deque<Content>::iterator	ItTmp;

	int		JacobsthalNumber;
	int		i = 1;

	while (PairDeque.size() > 1)
	{
		JacobsthalNumber = JacobsthalGenerator(i);
		ItLeft = PairDeque.begin();
		if (JacobsthalNumber * 2 >= (int)PairDeque.size())
			ItRight = ItLeft + PairDeque.size() - 1;
		else
			ItRight = ItLeft + JacobsthalNumber - 1;
		ItTmp = ItRight + 1;
		while (ItRight != ItLeft)
		{
			NewInsertion = BinarySearchPosition((*ItRight), SortedDeque);
			SortedDeque.insert(NewInsertion, ItRight->min);
			ItRight--;
		}
		NewInsertion = BinarySearchPosition((*ItLeft), SortedDeque);
		SortedDeque.insert(NewInsertion, ItLeft->min);
		PairDeque.erase(PairDeque.begin(), ItTmp);
		i++;
	}
	return ;
}
