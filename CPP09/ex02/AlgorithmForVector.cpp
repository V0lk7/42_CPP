/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlgorithmForVector.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:45:07 by jduval            #+#    #+#             */
/*   Updated: 2023/10/02 15:57:12 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

static void	DisplayVList(std::vector<int> &VList);
static void	MergeSortMax(std::vector<int> &MaxList);

void	MergeInsertSortVector(std::vector<int> &VList)
{
	int	OddValue = -1;
	std::vector<int>	Pend;

	if (VList.size() % 2 != 0)
	{
		OddValue = *(VList.end() - 1);
		VList.pop_back();
	}
	MergeSortMax(VList);
}

static void	MergeSortMax(std::vector<int> &MaxList)
{
	std::vector<int>			SubMaxList;

	DisplayVList(MaxList);
	if (MaxList.size() < 2)
		return ;

	std::vector<int>::iterator	ItFirst = MaxList.begin();
	std::vector<int>::iterator	ItSecond = MaxList.begin() + 1;

	while (ItFirst != MaxList.end())
	{
		if ((*ItFirst) <= (*ItSecond))
			SubMaxList.push_back((*ItSecond));
		else
			SubMaxList.push_back((*ItFirst));
		ItFirst = ItFirst + 2;
		ItSecond = ItSecond + 2;
	}
	MergeSortMax(SubMaxList);
}

static void	DisplayVList(std::vector<int> &VList)
{
	std::vector<int>::iterator	ItBegin = VList.begin();

	while (ItBegin != VList.end())
	{
		std::cout << (*ItBegin) << " ";
		ItBegin++;
	}
	std::cout << std::endl;
}
