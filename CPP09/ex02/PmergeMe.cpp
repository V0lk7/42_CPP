/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:24:06 by jduval            #+#    #+#             */
/*   Updated: 2023/10/07 15:10:30 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*====================Parsing=========================*/

#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <stdexcept>
#include "PmergeMe.hpp"
#include <algorithm>

static void	IsValidCharacters(char *str);
static int	ConvertToValidInteger(char *str);

void	CreateNumberVector(std::vector<int> &UnsortedNumbers, char **av)
{
	int	Value;

	for (int i = 1; av[i] != NULL; i++)
	{
		IsValidCharacters(av[i]);
		Value = ConvertToValidInteger(av[i]);
		UnsortedNumbers.push_back(Value);
	}
	return ;
}

void	CreateNumberDeque(std::deque<int> &UnsortedNumbers, char **av)
{
	int	Value;

	for (int i = 1; av[i] != NULL; i++)
	{
		IsValidCharacters(av[i]);
		Value = ConvertToValidInteger(av[i]);
		UnsortedNumbers.push_back(Value);
	}
	return ;
}

static void	IsValidCharacters(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]) == 0)
			throw (std::runtime_error("Non valid argument."));
	}
}

static int	ConvertToValidInteger(char *str)
{
	long int	Value = strtol(str, NULL, 10);

	if (errno == ERANGE || Value > 2147483647)
		throw (std::runtime_error("Value out of range."));
	else 
		return (static_cast<int>(Value));
}

/*====================MergeInsertSortVector========================*/

static void	MergeVector(std::vector<int> &MaxVector, std::vector<int> &SortedVector);
static void	InsertOddElement(int Element, std::vector<int> &SortedVector);

void	MergeInsertSortVector(std::vector<int> &UnsortedVector, std::vector<int> &SortedVector)
{
	MergeVector(UnsortedVector, SortedVector);
	if (UnsortedVector.size() % 2 != 0)
		InsertOddElement(UnsortedVector.back(), SortedVector);
	return ;
}

static void	InsertSortVector(	std::vector<int> &SubMaxVector,
								std::vector<Content> &PairVector,
								std::vector<int> &SortedVector);
static void	CreateVectorPairs(std::vector<int> &MaxVector, std::vector<Content> &PairedVector);
static void	CreateSubMaxVector(std::vector<Content> &PairedVector, std::vector<int> &SubMaxVector);

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

static std::vector<int>::iterator	BinarySearchPosition(	Content Pair,
															std::vector<int> &SortedVector);
static std::vector<int>::iterator	BinarySearch(int Element, std::vector<int> &SortedVector);

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

static int	JacobsthalGenerator(int n);
static void	InsertFirstMin(	std::vector<Content> &PairVector,
							std::vector<int> &SortedVector);


static void	InsertPendMin(	std::vector<Content> &PairVector,
							std::vector<int> &SortedVector)
{
	std::vector<int>::iterator		NewInsertion;

	std::vector<Content>::iterator	ItLeft;
	std::vector<Content>::iterator	ItRight;
	std::vector<Content>::iterator	ItTmp;

	int		JacobsthalNumber;
	int		i = 1;

	InsertFirstMin(PairVector, SortedVector);
	if (PairVector.size() == 0)
		return ;
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

static void	InsertFirstMin(	std::vector<Content> &PairVector,
							std::vector<int> &SortedVector)
{
	std::vector<int>::iterator		NewInsertion;
	std::vector<Content>::iterator	Pair = PairVector.begin();

	if (Pair == PairVector.end())
		return ;
	NewInsertion = BinarySearchPosition(*Pair, SortedVector);
	SortedVector.insert(NewInsertion, Pair->min);
	PairVector.erase(Pair, Pair + 1);
}


/*====================MergeInsertSortDeque===========================*/

static void	MergeDeque(std::deque<int> &MaxDeque, std::deque<int> &SortedDeque);
static void	InsertOddElement(int Element, std::deque<int> &SortedDeque);

void	MergeInsertSortDeque(std::deque<int> &UnsortedDeque, std::deque<int> &SortedDeque)
{
	MergeDeque(UnsortedDeque, SortedDeque);
	if (UnsortedDeque.size() % 2 != 0)
		InsertOddElement(UnsortedDeque.back(), SortedDeque);
	return ;
}

static void	InsertSortDeque(	std::deque<int> &SubMaxDeque,
								std::deque<Content> &PairDeque,
								std::deque<int> &SortedDeque);
static void	CreateDequePairs(std::deque<int> &Maxdeque, std::deque<Content> &PairDeque);
static void	CreateSubMaxDeque(std::deque<Content> &PairDeque, std::deque<int> &SubMaxdeque);

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

static std::deque<int>::iterator	BinarySearchPosition(Content Pair, std::deque<int> &SortedDeque);
static std::deque<int>::iterator	BinarySearch(int Element, std::deque<int> &SortedDeque);

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

static void	InsertFirstMin(	std::deque<Content> &PairDeque,
							std::deque<int> &SortedDeque);

static void	InsertPendMin(	std::deque<Content> &PairDeque,
							std::deque<int> &SortedDeque)
{
	std::deque<int>::iterator		NewInsertion;
	std::deque<Content>::iterator	ItLeft;
	std::deque<Content>::iterator	ItRight;
	std::deque<Content>::iterator	ItTmp;

	int		JacobsthalNumber;
	int		i = 1;

	InsertFirstMin(PairDeque, SortedDeque);
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

static void	InsertFirstMin(	std::deque<Content> &PairDeque,
							std::deque<int> &SortedDeque)
{
	std::deque<int>::iterator		NewInsertion;
	std::deque<Content>::iterator	Pair = PairDeque.begin();

	if (Pair == PairDeque.end())
		return ;
	NewInsertion = BinarySearchPosition(*Pair, SortedDeque);
	SortedDeque.insert(NewInsertion, Pair->min);
	PairDeque.erase(Pair, Pair + 1);
}

/*=======================BinarySearchsVector=====================*/

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
	if (Pair.min <= *MinLimit)
		return (MinLimit);
	else 
		return (MaxLimit);
}

static std::vector<int>::iterator	BinarySearch(int Element, std::vector<int> &SortedVector)
{
	std::vector<int>::iterator MaxLimit;
	std::vector<int>::iterator MinLimit;
	std::vector<int>::iterator Mid;


	MaxLimit = SortedVector.end() - 1;
	MinLimit = SortedVector.begin();
	Mid = MinLimit + (std::distance(MinLimit, MaxLimit) / 2);
	while (Mid != MinLimit && Mid != MaxLimit)
	{
		if (Element == *Mid)
			return (Mid);
		else if (Element < *Mid)
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
	if (Element <= *MinLimit)
		return (MinLimit);
	else if (Element > *MaxLimit) 
		return (MaxLimit + 1);
	else
		return (MaxLimit);
}

/*=======================BinarySearchsDeque=====================*/

static std::deque<int>::iterator	BinarySearchPosition(Content Pair, std::deque<int> &SortedDeque)
{
	std::deque<int>::iterator MaxLimit;
	std::deque<int>::iterator MinLimit;
	std::deque<int>::iterator Mid;


	MaxLimit = std::find(SortedDeque.begin(), SortedDeque.end(), Pair.max);
	MinLimit = SortedDeque.begin();
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
	if (Pair.min <= *MinLimit)
		return (MinLimit);
	else 
		return (MaxLimit);
}

static std::deque<int>::iterator	BinarySearch(int Element, std::deque<int> &SortedDeque)
{
	std::deque<int>::iterator MaxLimit;
	std::deque<int>::iterator MinLimit;
	std::deque<int>::iterator Mid;


	MaxLimit = SortedDeque.end() - 1;
	MinLimit = SortedDeque.begin();
	Mid = MinLimit + (std::distance(MinLimit, MaxLimit) / 2);
	while (Mid != MinLimit && Mid != MaxLimit)
	{
		if (Element == *Mid)
			return (Mid);
		else if (Element < *Mid)
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
	if (Element <= *MinLimit)
		return (MinLimit);
	else if (Element > *MaxLimit) 
		return (MaxLimit + 1);
	else
		return (MaxLimit);
}

/*========================UtilsVector====================*/

static void	AssignValuesToPairs(Content &Pairs, int a, int b);

static void	CreateVectorPairs(std::vector<int> &MaxVector, std::vector<Content> &PairedVector)
{
	Content	Pairs;
	std::size_t	size = MaxVector.size();

	if (size % 2 != 0)
		size--;
	for (std::size_t i = 0; i < size; i += 2)
	{
		AssignValuesToPairs(Pairs, MaxVector[i], MaxVector[i + 1]);
		PairedVector.push_back(Pairs);
	}
}

static void	CreateSubMaxVector(std::vector<Content> &PairedVector, std::vector<int> &SubMaxVector)
{
	int	Value;

	for (std::size_t i = 0; i < PairedVector.size(); i++)
	{
		Value = PairedVector[i].max;
		SubMaxVector.push_back(Value);
	}
}

/*========================UtilsDeque====================*/

static void	CreateDequePairs(std::deque<int> &Maxdeque, std::deque<Content> &PairDeque)
{
	Content	Pairs;
	std::size_t	size = Maxdeque.size();

	if (size % 2 != 0)
		size--;
	for (std::size_t i = 0; i < size; i += 2)
	{
		AssignValuesToPairs(Pairs, Maxdeque[i], Maxdeque[i + 1]);
		PairDeque.push_back(Pairs);
	}
}

static void	CreateSubMaxDeque(std::deque<Content> &PairDeque, std::deque<int> &SubMaxdeque)
{
	int	Value;

	for (std::size_t i = 0; i < PairDeque.size(); i++)
	{
		Value = PairDeque[i].max;
		SubMaxdeque.push_back(Value);
	}
}

/*=====================UTILS=====================*/

static int	JacobsthalGenerator(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return (JacobsthalGenerator(n - 1) + 2 * JacobsthalGenerator(n - 2));
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
