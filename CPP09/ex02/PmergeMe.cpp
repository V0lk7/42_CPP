/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:24:06 by jduval            #+#    #+#             */
/*   Updated: 2023/10/12 14:48:10 by jduval           ###   ########.fr       */
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

/*====================MergeInsertSort========================*/

static std::vector<int>::iterator	BinarySearch(int Value,
									std::vector<int> &Sorted, int flag);
static std::deque<int>::iterator	BinarySearch(int Value,
									std::deque<int> &Sorted, int flag);

static int		JacobsthalGenerator(int n);

static void		EraseSubMaxElements(std::vector<int> &SubMax, size_t index);
static void		EraseSubMaxElements(std::deque<int> &SubMax, size_t index);

static size_t	FindMinOfMax(std::vector<int> &SubMax, int Max, size_t size);
static size_t	FindMinOfMax(std::deque<int> &SubMax, int Max, size_t size);

static void		FillStock(	std::vector<int> &MaxStock, std::vector<int> &Sorted,
							size_t Start, size_t Jacobsthal);
static void		FillStock(	std::deque<int> &MaxStock, std::deque<int> &Sorted,
						size_t Start, size_t Jacobsthal);


static void	InsertRemainMin(std::vector<int> &SubMax, std::vector<int> &Sorted);
static void	InsertRemainMin(std::deque<int> &SubMax, std::deque<int> &Sorted);

static void	InsertSort(std::vector<int> &SubMax, std::vector<int> &Sorted);
static void	InsertSort(std::deque<int> &SubMax, std::deque<int> &Sorted);

static void	CreateSubMax(std::vector<int> &Max, std::vector<int> &SubMax);
static void	CreateSubMax(std::deque<int> &Max, std::deque<int> &SubMax);

void	MergeInsertSort(std::vector<int> Unsorted, std::vector<int> &Sorted)
{
	std::vector<int>			SubMax;
	int							OddNumber;
	bool						flag = false;

	if (Unsorted.size() % 2 != 0)
	{
		OddNumber = Unsorted.back();
		Unsorted.pop_back();
		flag = true;
	}

	CreateSubMax(Unsorted, SubMax);
	if (Unsorted.size() > 2)
		MergeInsertSort(SubMax, Sorted);
	InsertSort(Unsorted, Sorted);
	if (flag == true)
		Sorted.insert(BinarySearch(OddNumber, Sorted, 0), OddNumber);
}

void	MergeInsertSort(std::deque<int> Unsorted, std::deque<int> &Sorted)
{
	std::deque<int>	SubMax;
	int				OddNumber;
	bool			flag = false;

	if (Unsorted.size() % 2 != 0)
	{
		OddNumber = Unsorted.back();
		Unsorted.pop_back();
		flag = true;
	}

	CreateSubMax(Unsorted, SubMax);
	if (Unsorted.size() > 2)
		MergeInsertSort(SubMax, Sorted);
	InsertSort(Unsorted, Sorted);
	if (flag == true)
		Sorted.insert(BinarySearch(OddNumber, Sorted, 0), OddNumber);
}

static void	CreateSubMax(std::vector<int> &Max, std::vector<int> &SubMax)
{
	size_t	size = Max.size();
	int	j = 0;

	for (size_t i = 0; i < size; i += 2)
	{
		if (i + 1 == size)
			SubMax.push_back(Max[i]);
		else if (Max[i] >= Max[i + 1])
			SubMax.push_back(Max[i]);
		else
			SubMax.push_back(Max[i + 1]);
		j++;
	}
}

static void	CreateSubMax(std::deque<int> &Max, std::deque<int> &SubMax)
{
	size_t	size = Max.size();
	int	j = 0;

	for (size_t i = 0; i < size; i += 2)
	{
		if (i + 1 == size)
			SubMax.push_back(Max[i]);
		else if (Max[i] >= Max[i + 1])
			SubMax.push_back(Max[i]);
		else
			SubMax.push_back(Max[i + 1]);
		j++;
	}
}

static void	InsertSort(std::vector<int> &SubMax, std::vector<int> &Sorted)
{
	//Insert the first Pair. 
	if (SubMax.size() == 2)
	{
		if (SubMax[0] > SubMax[1])
		{
			Sorted.push_back(SubMax[1]);
			Sorted.push_back(SubMax[0]);
		}
		else
		{
			Sorted.push_back(SubMax[0]);
			Sorted.push_back(SubMax[1]);
		}
	}
	//Insert at first the first min appaired to the first max in Sorted
	//Insert the other min using Jacobsthal sequence.
	else
	{		
		size_t	Index = FindMinOfMax(SubMax, Sorted[0], SubMax.size());
		Sorted.insert(Sorted.begin(), SubMax[Index]);
		EraseSubMaxElements(SubMax, Index);
		if (SubMax.size() != 0)
			InsertRemainMin(SubMax, Sorted);
	}
}

static void	InsertSort(std::deque<int> &SubMax, std::deque<int> &Sorted)
{
	//Insert the first Pair. 
	if (SubMax.size() == 2)
	{
		if (SubMax[0] > SubMax[1])
		{
			Sorted.push_back(SubMax[1]);
			Sorted.push_back(SubMax[0]);
		}
		else
		{
			Sorted.push_back(SubMax[0]);
			Sorted.push_back(SubMax[1]);
		}
	}
	//Insert at first the first min appaired to the first max in Sorted
	//Insert the other min using Jacobsthal sequence.
	else
	{		
		size_t	Index = FindMinOfMax(SubMax, Sorted[0], SubMax.size());
		Sorted.insert(Sorted.begin(), SubMax[Index]);
		EraseSubMaxElements(SubMax, Index);
		if (SubMax.size() != 0)
			InsertRemainMin(SubMax, Sorted);
	}
}

static void	InsertRemainMin(std::vector<int> &SubMax, std::vector<int> &Sorted)
{
	std::vector<int>			MaxStock;
	std::vector<int>::iterator	MinPos;
	size_t						Jacobsthal = 0, Next = 2, IndexMin = 0, count = 1;

	while (SubMax.size() > 0)
	{
		Jacobsthal = JacobsthalGenerator(count) * 2;
		FillStock(MaxStock, Sorted, Next, Jacobsthal);
		for (int i = MaxStock.size() - 1; i >= 0; i--)
		{
			IndexMin = FindMinOfMax(SubMax, MaxStock[i], SubMax.size());
			MinPos = BinarySearch(SubMax[IndexMin], Sorted, 0);
			Sorted.insert(MinPos, SubMax[IndexMin]);
			EraseSubMaxElements(SubMax, IndexMin);
		}
		MaxStock.clear();
		Next = Next + (Jacobsthal * 2);
		count++;
	}
	return ;
}

static void	InsertRemainMin(std::deque<int> &SubMax, std::deque<int> &Sorted)
{
	std::deque<int>			MaxStock;
	std::deque<int>::iterator	MinPos;
	size_t						Jacobsthal = 0, Next = 2, IndexMin = 0, count = 1;

	while (SubMax.size() > 0)
	{
		Jacobsthal = JacobsthalGenerator(count) * 2;
		FillStock(MaxStock, Sorted, Next, Jacobsthal);
		for (int i = MaxStock.size() - 1; i >= 0; i--)
		{
			IndexMin = FindMinOfMax(SubMax, MaxStock[i], SubMax.size());
			MinPos = BinarySearch(SubMax[IndexMin], Sorted, 0);
			Sorted.insert(MinPos, SubMax[IndexMin]);
			EraseSubMaxElements(SubMax, IndexMin);
		}
		MaxStock.clear();
		Next = Next + (Jacobsthal * 2);
		count++;
	}
	return ;
}

static void	FillStock(std::vector<int> &MaxStock, std::vector<int> &Sorted,
						size_t start, size_t Jacobsthal)
{
	size_t	size = Sorted.size();
	size_t	end;

	if (start + Jacobsthal > size)
		end = size;
	else
		end = start + Jacobsthal;
	while (start < end)
	{
		MaxStock.push_back(Sorted[start]);
		start++;
	}
}

static void	FillStock(std::deque<int> &MaxStock, std::deque<int> &Sorted,
						size_t start, size_t Jacobsthal)
{
	size_t	size = Sorted.size();
	size_t	end;

	if (start + Jacobsthal > size)
		end = size;
	else
		end = start + Jacobsthal;
	while (start < end)
	{
		MaxStock.push_back(Sorted[start]);
		start++;
	}
}

static size_t	FindMinOfMax(std::vector<int> &SubMax, int Value, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (SubMax[i] == Value)
		{
			if (i % 2 == 0 && SubMax[i + 1] <= Value)
				return (i + 1);
			else if (i % 2 != 0 && SubMax[i - 1] <= Value)
				return (i - 1);
			else
				continue ;
		}
	}
	return (0);
}

static size_t	FindMinOfMax(std::deque<int> &SubMax, int Value, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (SubMax[i] == Value)
		{
			if (i % 2 == 0 && SubMax[i + 1] <= Value)
				return (i + 1);
			else if (i % 2 != 0 && SubMax[i - 1] <= Value)
				return (i - 1);
			else
				continue ;
		}
	}
	return (0);
}

static void	EraseSubMaxElements(std::vector<int> &SubMax, size_t index)
{
	std::vector<int>::iterator	first;
	std::vector<int>::iterator	second;

	if (index % 2 == 0)
		first = SubMax.begin() + index;
	else
		first = SubMax.begin() + (index - 1);
	second = first + 2;
	SubMax.erase(first, second);
}

static void	EraseSubMaxElements(std::deque<int> &SubMax, size_t index)
{
	std::deque<int>::iterator	first;
	std::deque<int>::iterator	second;

	if (index % 2 == 0)
		first = SubMax.begin() + index;
	else
		first = SubMax.begin() + (index - 1);
	second = first + 2;
	SubMax.erase(first, second);
}

static std::vector<int>::iterator	BinarySearch(int Value, std::vector<int> &Sorted, int flag)
{
	std::vector<int>::iterator MaxLimit;
	std::vector<int>::iterator MinLimit = Sorted.begin();
	std::vector<int>::iterator Mid;


	if (flag == 1)
		MaxLimit = std::find(Sorted.begin(), Sorted.end(), Value) - 1;
	else 
		MaxLimit = Sorted.end() - 1;
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

static std::deque<int>::iterator	BinarySearch(int Value, std::deque<int> &Sorted, int flag)
{
	std::deque<int>::iterator MaxLimit;
	std::deque<int>::iterator MinLimit = Sorted.begin();
	std::deque<int>::iterator Mid;


	if (flag == 1)
		MaxLimit = std::find(Sorted.begin(), Sorted.end(), Value) - 1;
	else 
		MaxLimit = Sorted.end() - 1;
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

static int	JacobsthalGenerator(int n)
{
	if (n == 0)
		return (0);
    if (n == 1)
        return (1);
    return (JacobsthalGenerator(n - 1) + 2 * JacobsthalGenerator(n - 2));
}
