/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsVector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:22:13 by jduval            #+#    #+#             */
/*   Updated: 2023/10/04 15:53:46 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utilities.hpp"

static void	AssignValuesToPairs(Content &Pairs, int a, int b);

void	CreateVectorPairs(std::vector<int> &MaxVector, std::vector<Content> &PairedVector)
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

void	CreateSubMaxVector(std::vector<Content> &PairedVector, std::vector<int> &SubMaxVector)
{
	int	Value;

	for (std::size_t i = 0; i < PairedVector.size(); i++)
	{
		Value = PairedVector[i].max;
		SubMaxVector.push_back(Value);
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
