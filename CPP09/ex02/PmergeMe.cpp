/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:24:06 by jduval            #+#    #+#             */
/*   Updated: 2023/10/11 16:27:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*====================Parsing=========================*/

#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <stdexcept>
#include "PmergeMe.hpp"
#include <algorithm>

/*#################PARSING#######################*/

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

static std::vector<int>::iterator	BinarySearch(int Value,
									std::vector<int> &SortedVector, int flag);

static void		InsertOddElement(int Value, std::vector<int> &SortedVector);
static int		JacobsthalGenerator(int n);
static void		EraseSubMaxElements(std::vector<int> &SubMaxVector, size_t index);
static size_t	FindMinOfMax(std::vector<int> &SubMaxVector, int Max, size_t size);

static void	FillStock(std::vector<int> &MaxStock, std::vector<int> &SortedVector, size_t Start, size_t Jacobsthal);
static void	InsertRemainMin(std::vector<int> &SubMaxVector, std::vector<int> &SortedVector);
static void	InsertFirstPair(std::vector<int> &SubMaxVector, std::vector<int> &SortedVector);
static void	InsertFirst(std::vector<int> &SubMaxVector, std::vector<int> &SortedVector);
static void	InsertSortVector(std::vector<int> &SubMaxVector, std::vector<int> &SortedVector);
static void	CreateSubMaxVector(std::vector<int> MaxVector, std::vector<int> &SubMaxVector);
//static void	MergeVector(std::vector<int> &MaxVector, std::vector<int> &SortedVector);

/*void	MergeInsertSortVector(std::vector<int> &UnsortedVector, std::vector<int> &SortedVector)
{
	MergeVector(UnsortedVector, SortedVector);
	return ;
}*/

void	MergeInsertSortVector(std::vector<int> UnsortedVector, std::vector<int> &SortedVector)
{
	std::vector<int>			SubMaxVector;
	int							OddNumber;
	bool						flag = false;

	if (UnsortedVector.size() % 2 != 0)
	{
		OddNumber = UnsortedVector.back();
		UnsortedVector.pop_back();
		flag = true;
	}
	CreateSubMaxVector(UnsortedVector, SubMaxVector);
	if (UnsortedVector.size() > 2)
		MergeInsertSortVector(SubMaxVector, SortedVector);
	InsertSortVector(UnsortedVector, SortedVector);
	if (flag == true)
		InsertOddElement(OddNumber, SortedVector);
}

static void	CreateSubMaxVector(std::vector<int> MaxVector, std::vector<int> &SubMaxVector)
{
	size_t	size = MaxVector.size();
	int	j = 0;

	SubMaxVector.assign((size / 2), 0);
	for (size_t i = 0; i < size; i += 2)
	{
		if (i + 1 == size)
			SubMaxVector[j] = MaxVector[i];
		else if (MaxVector[i] >= MaxVector[i + 1])
			SubMaxVector[j] = MaxVector[i];
		else
			SubMaxVector[j] = MaxVector[i + 1];
		j++;
	}
}

static void	InsertSortVector(std::vector<int> &SubMaxVector, std::vector<int> &SortedVector)
{
	size_t	size = SubMaxVector.size();

	if (size == 2)
		InsertFirstPair(SubMaxVector, SortedVector);
	else
	{
		InsertFirst(SubMaxVector, SortedVector);
		if (SubMaxVector.size() != 0)
			InsertRemainMin(SubMaxVector, SortedVector);
	}
}

static void	InsertFirstPair(std::vector<int> &SubMaxVector, std::vector<int> &SortedVector)
{
	if (SubMaxVector[0] > SubMaxVector[1])
	{
		SortedVector.push_back(SubMaxVector[1]);
		SortedVector.push_back(SubMaxVector[0]);
	}
	else
	{
		SortedVector.push_back(SubMaxVector[0]);
		SortedVector.push_back(SubMaxVector[1]);
	}
}

static void	InsertFirst(std::vector<int> &SubMaxVector, std::vector<int> &SortedVector)
{
	size_t	IndexMin = FindMinOfMax(SubMaxVector, SortedVector[0], SubMaxVector.size());

	SortedVector.insert(SortedVector.begin(), SubMaxVector[IndexMin]);
	EraseSubMaxElements(SubMaxVector, IndexMin);
	return ;
}

static void	InsertRemainMin(std::vector<int> &SubMaxVector, std::vector<int> &SortedVector)
{
	std::vector<int>			MaxStock;
	std::vector<int>::iterator	MinPos;
	size_t						Jacobsthal;
	size_t						Next = 2;
	size_t						IndexMin;
	size_t						count = 1;

	while (SubMaxVector.size() > 0)
	{
		Jacobsthal = JacobsthalGenerator(count) * 2;
		FillStock(MaxStock, SortedVector, Next, Jacobsthal);
		for (int i = MaxStock.size() - 1; i >= 0; i--)
		{
			IndexMin = FindMinOfMax(SubMaxVector, MaxStock[i], SubMaxVector.size());
			MinPos = BinarySearch(SubMaxVector[IndexMin], SortedVector, 0);
			SortedVector.insert(MinPos, SubMaxVector[IndexMin]);
			EraseSubMaxElements(SubMaxVector, IndexMin);
		}
		MaxStock.clear();
		Next = Next + (Jacobsthal * 2);
		count++;
	}
	return ;
}

static void	FillStock(std::vector<int> &MaxStock, std::vector<int> &SortedVector, size_t start, size_t Jacobsthal)
{
	size_t	size = SortedVector.size();
	size_t	end;

	if (start + Jacobsthal > size)
		end = size;
	else
		end = start + Jacobsthal;
	while (start < end)
	{
		MaxStock.push_back(SortedVector[start]);
		start++;
	}
}

static size_t	FindMinOfMax(std::vector<int> &SubMaxVector, int Max, size_t size)
{

	for (size_t i = 0; i < size; i++)
	{
		if (SubMaxVector[i] == Max)
		{
			if (i % 2 == 0 && SubMaxVector[i + 1] <= Max)
				return (i + 1);
			else if (i % 2 != 0 && SubMaxVector[i - 1] <= Max)
				return (i - 1);
			else
				continue ;
		}
	}
	return (0);
}

static void	EraseSubMaxElements(std::vector<int> &SubMaxVector, size_t index)
{
	std::vector<int>::iterator	first;
	std::vector<int>::iterator	second;

	if (index % 2 == 0)
		first = SubMaxVector.begin() + index;
	else
		first = SubMaxVector.begin() + (index - 1);
	second = first + 2;
	SubMaxVector.erase(first, second);
}

static int	JacobsthalGenerator(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return (JacobsthalGenerator(n - 1) + 2 * JacobsthalGenerator(n - 2));
}

static std::vector<int>::iterator	BinarySearch(int Value, std::vector<int> &SortedVector, int flag)
{
	std::vector<int>::iterator MaxLimit;
	std::vector<int>::iterator MinLimit;
	std::vector<int>::iterator Mid;


	if (flag == 1)
		MaxLimit = std::find(SortedVector.begin(), SortedVector.end(), Value);
	else 
		MaxLimit = SortedVector.end();
//	if (MaxLimit == SortedVector.end())
//		MaxLimit = SortedVector.end() -  1;
//	else
	MaxLimit--;
	MinLimit = SortedVector.begin();
	Mid = MinLimit + (std::distance(MinLimit, MaxLimit) / 2);
	while (Mid != MinLimit && Mid != MaxLimit)
	{
		if (Value == *Mid)
			return (Mid);
		else if (Value < *Mid)
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
	if (Value <= *MinLimit)
		return (MinLimit);
	else if (Value > *MaxLimit) 
		return (MaxLimit + 1);
	else
		return (MaxLimit);
}

static void	InsertOddElement(int Value, std::vector<int> &SortedVector)
{
	std::vector<int>::iterator	OddPos;

	OddPos = BinarySearch(Value, SortedVector, 1);
	SortedVector.insert(OddPos, Value);
}

/*
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
}*/
