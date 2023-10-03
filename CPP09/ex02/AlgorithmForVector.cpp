/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlgorithmForVector.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:45:07 by jduval            #+#    #+#             */
/*   Updated: 2023/10/03 17:49:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <algorithm>
#include "Utilities.hpp"

static void	DisplayVector(std::vector<int> &MaxVector);
static void	DisplayPairedVector(std::vector<Content> &PairedVector);
static void	MergeVector(std::vector<int> &MaxVector, std::vector<int> &SortedVector);

void	MergeInsertSortVector(std::vector<int> &UnsortedVector)
{
	std::vector<int>	SortedVector;

	MergeVector(UnsortedVector, SortedVector);
	return ;
}

static void	CreateVectorPairs(std::vector<int> &MaxVector, std::vector<Content> &PairedVector);
static void	CreateSubMaxVector(std::vector<Content> &PairedVector, std::vector<int> &SubMaxVector);
static void	InsertSortVector(size_t size,	std::vector<Content> &PairedVector,
											std::vector<int> &SortedVector);

static void	MergeVector(std::vector<int> &MaxVector, std::vector<int> &SortedVector)
{
	std::vector<Content>		PairedVector;
	std::vector<int>			SubMaxVector;

	CreateVectorPairs(MaxVector, PairedVector);
	CreateSubMaxVector(PairedVector, SubMaxVector);
	DisplayPairedVector(PairedVector);
	if (MaxVector.size() > 2)
		MergeVector(SubMaxVector, SortedVector);
	InsertSortVector(SubMaxVector.size(), PairedVector, SortedVector);
	DisplayVector(SortedVector);
}

static void	InsertFirstPair(Content &Pair, std::vector<int> &SortedVector);
static void	InsertPendMin(size_t size,		std::vector<Content> &PairedVector,
										std::vector<int> &SortedVector);

static void	InsertSortVector(size_t size,	std::vector<Content> &PairedVector,
											std::vector<int> &SortedVector)
{
	if (PairedVector.size() == 1)
		InsertFirstPair(PairedVector[0], SortedVector);
	else
		InsertPendMin(size, PairedVector, SortedVector);
}

static void	InsertFirstPair(Content &Pair, std::vector<int> &SortedVector)
{
	SortedVector.push_back(Pair.min);
	SortedVector.push_back(Pair.max);
	return ;
}

static std::vector<int>::iterator	BinarySearchPosition(	Content Pair,
															std::vector<int> &SortedVector);

static void	InsertPendMin(size_t size,	std::vector<Content> &PairedVector,
										std::vector<int> &SortedVector)
{
	Content	Pair;
	std::vector<int>::iterator	NewInsertion;

	size_t	len = size - 1;
	for (size_t i = 0; i < len; i++)
	{
		Pair = PairedVector[i];
		NewInsertion = BinarySearchPosition(Pair, SortedVector);
		SortedVector.insert(NewInsertion, Pair.min);
	}
	return ;
}

static std::vector<int>::iterator	BinarySearchPosition(	Content Pair,
															std::vector<int> &SortedVector)
{
	std::vector<int>::iterator MaxLimit;
	std::vector<int>::iterator MinLimit;
	std::vector<int>::iterator Mid;


	MaxLimit = std::find(SortedVector.begin(), SortedVector.end(), Pair.max);
	MinLimit = SortedVector.begin();
	Mid = MinLimit + (std::distance(MinLimit, MaxLimit) / 2);
	while (Mid != MinLimit && Mid != MaxLimit)
	{
		if (Pair.min == *Mid)
			return (Mid);
		else if (Pair.min < *Mid)
		{
			MaxLimit = Mid;
			Mid = MinLimit + (std::distance(MinLimit, MaxLimit) / 2);
		}
		else
		{
			MinLimit = Mid;
			Mid = MinLimit + (std::distance(MinLimit, MaxLimit) / 2);
		}
	}
	std::cout << "Pair " << Pair.min << " Mid : " << *Mid << std::endl;
	std::cout << "MinLimit = " << *MinLimit << " MaxLimit = " << *MaxLimit << std::endl;
	if (Mid == MinLimit)
		return (MaxLimit);
	else
		return (MinLimit);
}

/*========================CreateVectors/Pairs===============================*/

static void	AssignValuesToPairs(Content &Pairs, int a, int b);

static void	CreateVectorPairs(std::vector<int> &MaxVector, std::vector<Content> &PairedVector)
{
	Content	Pairs;	
	for (size_t i = 0; i < MaxVector.size(); i += 2)
	{
		if (i + 1 < MaxVector.size())
			AssignValuesToPairs(Pairs, MaxVector[i], MaxVector[i + 1]);
		else
			AssignValuesToPairs(Pairs, MaxVector[i], 0);
		PairedVector.push_back(Pairs);
	}
}

static void	AssignValuesToPairs(Content &Pairs, int a, int b)
{
	if (a <= b)
	{
		Pairs.max = b;
		Pairs.min = a;
	}
	else
	{
		Pairs.max = a;
		Pairs.min = b;
	}
}

static void	CreateSubMaxVector(std::vector<Content> &PairedVector, std::vector<int> &SubMaxVector)
{
	int	Value;

	for (size_t i = 0; i < PairedVector.size(); i++)
	{
		Value = PairedVector[i].max;
		SubMaxVector.push_back(Value);
	}
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
