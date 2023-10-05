/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchDeque.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:50:05 by jduval            #+#    #+#             */
/*   Updated: 2023/10/05 11:46:59 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include "Utilities.hpp"

std::deque<int>::iterator	BinarySearchPosition(Content Pair, std::deque<int> &SortedDeque)
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

std::deque<int>::iterator	BinarySearch(int Element, std::deque<int> &SortedDeque)
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
