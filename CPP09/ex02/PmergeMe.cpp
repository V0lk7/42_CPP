/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:24:06 by jduval            #+#    #+#             */
/*   Updated: 2023/10/12 14:04:27 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <stdexcept>
#include "PmergeMe.hpp"
#include <algorithm>

/*#################PARSING#######################*/

static void	IsValidCharacters(char *str);
static int	ConvertToValidInteger(char *str);

void	CreateNumbers(std::vector<int> &UnsortedNumbers, char **av)
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

void	CreateNumbers(std::deque<int> &UnsortedNumbers, char **av)
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

static int		JacobsthalGenerator(int n);
static void		EraseSubMaxElements(std::vector<int> &SubMaxVector, size_t index);
static size_t	FindMinOfMax(std::vector<int> &SubMaxVector, int Max, size_t size);

static void	FillStock(std::vector<int> &MaxStock, std::vector<int> &SortedVector, size_t Start, size_t Jacobsthal);
static void	InsertRemainMin(std::vector<int> &SubMaxVector, std::vector<int> &SortedVector);
static void	InsertSortVector(std::vector<int> &SubMaxVector, std::vector<int> &SortedVector);
static void	CreateSubMaxVector(std::vector<int> &MaxVector, std::vector<int> &SubMaxVector);

void	MergeInsertSort(std::vector<int> UnsortedVector, std::vector<int> &SortedVector)
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
		MergeInsertSort(SubMaxVector, SortedVector);
	InsertSortVector(UnsortedVector, SortedVector);
	if (flag == true)
		SortedVector.insert(BinarySearch(OddNumber, SortedVector, 0), OddNumber);
}

static void	CreateSubMaxVector(std::vector<int> &MaxVector, std::vector<int> &SubMaxVector)
{
	size_t	size = MaxVector.size();
	int	j = 0;

	for (size_t i = 0; i < size; i += 2)
	{
		if (i + 1 == size)
			SubMaxVector.push_back(MaxVector[i]);
		else if (MaxVector[i] >= MaxVector[i + 1])
			SubMaxVector.push_back(MaxVector[i]);
		else
			SubMaxVector.push_back(MaxVector[i + 1]);
		j++;
	}
}

static void	InsertSortVector(std::vector<int> &SubMaxVector, std::vector<int> &SortedVector)
{
	//Insert the first Pair. 
	if (SubMaxVector.size() == 2)
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
	//Insert at first the first min appaired to the first max in Sorted
	//Insert the other min using Jacobsthal sequence.
	else
	{		
		size_t	Index = FindMinOfMax(SubMaxVector, SortedVector[0], SubMaxVector.size());
		SortedVector.insert(SortedVector.begin(), SubMaxVector[Index]);
		EraseSubMaxElements(SubMaxVector, Index);
		if (SubMaxVector.size() != 0)
			InsertRemainMin(SubMaxVector, SortedVector);
	}
}

static void	InsertRemainMin(std::vector<int> &SubMaxVector, std::vector<int> &SortedVector)
{
	std::vector<int>			MaxStock;
	std::vector<int>::iterator	MinPos;
	size_t						Jacobsthal = 0, Next = 2, IndexMin = 0, count = 1;

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

static size_t	FindMinOfMax(std::vector<int> &SubMaxVector, int Value, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (SubMaxVector[i] == Value)
		{
			if (i % 2 == 0 && SubMaxVector[i + 1] <= Value)
				return (i + 1);
			else if (i % 2 != 0 && SubMaxVector[i - 1] <= Value)
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
		return (0);
    if (n == 1)
        return (1);
    return (JacobsthalGenerator(n - 1) + 2 * JacobsthalGenerator(n - 2));
}

static std::vector<int>::iterator	BinarySearch(int Value, std::vector<int> &SortedVector, int flag)
{
	std::vector<int>::iterator MaxLimit;
	std::vector<int>::iterator MinLimit = SortedVector.begin();
	std::vector<int>::iterator Mid;


	if (flag == 1)
		MaxLimit = std::find(SortedVector.begin(), SortedVector.end(), Value) - 1;
	else 
		MaxLimit = SortedVector.end() - 1;
	Mid = MinLimit + (std::distance(MinLimit, MaxLimit) / 2);
	while (Mid != MinLimit && Mid != MaxLimit)
	{
		if (Value == *Mid)
			return (Mid);
		else if (Value < *Mid)
			MaxLimit = Mid;
		else
			MinLimit = Mid;
		Mid = MinLimit + (std::distance(MinLimit, MaxLimit) / 2);
	}
	if (Value <= *MinLimit)
		return (MinLimit);
	else if (Value > *MaxLimit) 
		return (MaxLimit + 1);
	else
		return (MaxLimit);
}
