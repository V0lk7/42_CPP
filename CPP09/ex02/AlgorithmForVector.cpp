/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlgorithmForVector.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:45:07 by jduval            #+#    #+#             */
/*   Updated: 2023/10/05 14:20:31 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include "Utilities.hpp"

static void	MergeVector(std::vector<int> &MaxVector, std::vector<int> &SortedVector);
static void	InsertOddElement(int Element, std::vector<int> &SortedVector);

void	MergeInsertSortVector(std::vector<int> &UnsortedVector, std::vector<int> &SortedVector)
{
//	std::vector<int>	SortedVector;

	MergeVector(UnsortedVector, SortedVector);
	if (UnsortedVector.size() % 2 != 0)
		InsertOddElement(UnsortedVector.back(), SortedVector);
	return ;
}

static void	InsertSortVector(	std::vector<int> &SubMaxVector,
								std::vector<Content> &PairVector,
								std::vector<int> &SortedVector);

static void	MergeVector(std::vector<int> &MaxVector, std::vector<int> &SortedVector)
{
	std::vector<Content>		PairVector;
	std::vector<int>			SubMaxVector;

	CreateVectorPairs(MaxVector, PairVector);
	CreateSubMaxVector(PairVector, SubMaxVector);
	if (MaxVector.size() > 2)
		MergeVector(SubMaxVector, SortedVector);
	InsertSortVector(SubMaxVector, PairVector, SortedVector);
}

static void	InsertFirstPair(Content &Pair, std::vector<int> &SortedVector);
static void	InsertPendMin(	std::vector<Content> &PairVector,
							std::vector<int> &SortedVector);

static void	InsertSortVector(	std::vector<int> &SubMaxVector,
								std::vector<Content> &PairVector,
								std::vector<int> &SortedVector)
{
	int	OddElement;

	if (PairVector.size() == 1)
		InsertFirstPair(PairVector[0], SortedVector);
	else
		InsertPendMin(PairVector, SortedVector);
	if (SubMaxVector.size() % 2 != 0 && SubMaxVector.size() != 1)
	{
		OddElement = SubMaxVector.back();
		InsertOddElement(OddElement, SortedVector);
	}
}

static void	InsertOddElement(int Element, std::vector<int> &SortedVector)
{
	std::vector<int>::iterator	NewInsertion;

	NewInsertion = BinarySearch(Element, SortedVector);
	SortedVector.insert(NewInsertion, Element);
}

static void	InsertFirstPair(Content &Pair, std::vector<int> &SortedVector)
{
	SortedVector.push_back(Pair.min);
	SortedVector.push_back(Pair.max);
	return ;
}

static void	InsertPendMin(	std::vector<Content> &PairVector,
							std::vector<int> &SortedVector)
{
	std::vector<int>::iterator		NewInsertion;

	std::vector<Content>::iterator	ItLeft;
	std::vector<Content>::iterator	ItRight;
	std::vector<Content>::iterator	ItTmp;

	int		JacobsthalNumber;
	int		i = 1;

	while (PairVector.size() > 1)
	{
		JacobsthalNumber = JacobsthalGenerator(i);
		ItLeft = PairVector.begin();
		if (JacobsthalNumber * 2 >= (int)PairVector.size())
			ItRight = ItLeft + PairVector.size() - 1;
		else
			ItRight = ItLeft + JacobsthalNumber - 1;
		ItTmp = ItRight + 1;
		while (ItRight != ItLeft)
		{
			NewInsertion = BinarySearchPosition((*ItRight), SortedVector);
			SortedVector.insert(NewInsertion, ItRight->min);
			ItRight--;
		}
		NewInsertion = BinarySearchPosition((*ItLeft), SortedVector);
		SortedVector.insert(NewInsertion, ItLeft->min);
		PairVector.erase(PairVector.begin(), ItTmp);
		i++;
	}
	return ;
}
