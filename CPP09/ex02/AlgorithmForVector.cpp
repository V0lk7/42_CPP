/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlgorithmForVector.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:45:07 by jduval            #+#    #+#             */
/*   Updated: 2023/10/04 15:53:47 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <algorithm>
#include "Utilities.hpp"

static void	DisplayVector(std::vector<int> &MaxVector);
static void	DisplayPairedVector(std::vector<Content> &PairedVector);
static void	MergeVector(std::vector<int> &MaxVector, std::vector<int> &SortedVector);

static bool	is_sorted(std::vector<int> &SortedVector);

void	MergeInsertSortVector(std::vector<int> &UnsortedVector)
{
	std::vector<int>	SortedVector;

	MergeVector(UnsortedVector, SortedVector);
//	if (is_sorted(SortedVector) == true)
//		std::cout << "It's Fucking Sorted OMG !!!" << std::endl;
//	else
//		std::cout << "Aled ça marche pas...." << std::endl;
	DisplayVector(SortedVector);
	return ;
}

static bool	is_sorted(std::vector<int> &SortedVector)
{
	for (size_t i = 0; i < SortedVector.size(); i++)
	{
		if (i + 1 < SortedVector.size() && SortedVector[i] > SortedVector[i + 1])
			return (false);
	}
	return (true);
}

static void	InsertSortVector(	std::vector<int> &SubMaxVector,
								std::vector<Content> &PairedVector,
								std::vector<int> &SortedVector);

static void	MergeVector(std::vector<int> &MaxVector, std::vector<int> &SortedVector)
{
	std::vector<Content>		PairedVector;
	std::vector<int>			SubMaxVector;

	CreateVectorPairs(MaxVector, PairedVector);
	CreateSubMaxVector(PairedVector, SubMaxVector);
	DisplayPairedVector(PairedVector);
	DisplayVector(SubMaxVector);
	if (MaxVector.size() > 2)
		MergeVector(SubMaxVector, SortedVector);
	InsertSortVector(SubMaxVector, PairedVector, SortedVector);
}

static void	InsertFirstPair(Content &Pair, std::vector<int> &SortedVector);
static void	InsertPendMin(	std::vector<Content> &PairedVector,
							std::vector<int> &SortedVector);
static void	InsertOddElement(int Element, std::vector<int> &SortedVector);


static void	InsertSortVector(	std::vector<int> &SubMaxVector,
								std::vector<Content> &PairedVector,
								std::vector<int> &SortedVector)
{
	std::cout << "===================================" << std::endl;
	DisplayPairedVector(PairedVector);
	int	OddElement;
	if (PairedVector.size() == 1)
		InsertFirstPair(PairedVector[0], SortedVector);
	else
		InsertPendMin(PairedVector, SortedVector);
	if (SubMaxVector.size() % 2 != 0 && SubMaxVector.size() != 1)
	{
		OddElement = SubMaxVector.back();
		InsertOddElement(OddElement, SortedVector);
	}
	DisplayVector(SortedVector);
	std::cout << "===================================" << std::endl;
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

static void	InsertPendMin(	std::vector<Content> &PairedVector,
							std::vector<int> &SortedVector)
{
	std::vector<int>::iterator		NewInsertion;
	std::vector<Content>::iterator	ItLeft;
	std::vector<Content>::iterator	ItRight;
	std::vector<Content>::iterator	ItTmp;
	int		JacobsthalNumber;
	int		i = 1;

	while (PairedVector.size() > 1)
	{
		JacobsthalNumber = JacobsthalGenerator(i);
		ItLeft = PairedVector.begin();
		if (JacobsthalNumber * 2 >= (int)PairedVector.size())
			ItRight = ItLeft + PairedVector.size() - 1;
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
		PairedVector.erase(PairedVector.begin(), ItTmp);
		i++;
	}
	return ;
}

/*========================DisplayVectors===============================*/

static void	DisplayPairedVector(std::vector<Content> &PairedVector)
{
	for (size_t i = 0; i < PairedVector.size(); i++)
	{
		std::cout << '(' << PairedVector[i].max << ',' << PairedVector[i].min << ')' << ' ';
	}
	std::cout << std::endl;
}

static void	DisplayVector(std::vector<int> &MaxVector)
{
	for (size_t i = 0; i < MaxVector.size(); i++)
	{
		std::cout << MaxVector[i] << ' ';
	}
	std::cout << std::endl;
}
