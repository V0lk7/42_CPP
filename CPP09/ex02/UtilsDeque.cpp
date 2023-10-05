/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsDeque.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:19:40 by jduval            #+#    #+#             */
/*   Updated: 2023/10/05 14:23:27 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utilities.hpp"

static void	AssignValuesToPairs(Content &Pairs, int a, int b);

void	CreateDequePairs(std::deque<int> &Maxdeque, std::deque<Content> &PairDeque)
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

void	CreateSubMaxDeque(std::deque<Content> &PairDeque, std::deque<int> &SubMaxdeque)
{
	int	Value;

	for (std::size_t i = 0; i < PairDeque.size(); i++)
	{
		Value = PairDeque[i].max;
		SubMaxdeque.push_back(Value);
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
