/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchVector.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:26:24 by jduval            #+#    #+#             */
/*   Updated: 2023/10/04 15:53:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include "Utilities.hpp"

std::vector<int>::iterator	BinarySearchPosition(Content Pair, std::vector<int> &SortedVector)
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

std::vector<int>::iterator	BinarySearch(int Element, std::vector<int> &SortedVector)
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
