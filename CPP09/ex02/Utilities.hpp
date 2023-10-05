/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:26:42 by jduval            #+#    #+#             */
/*   Updated: 2023/10/05 15:07:30 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_HPP
# define UTILITIES_HPP

# include <vector>
# include <deque>
# include <iostream>

struct	Content
{
	int		max;
	int		min;
};

void	CreateNumberVector(std::vector<int> &UnsortedNumbers, char **av);
void	CreateNumberDeque(std::deque<int> &UnsortedNumbers, char **av);

void	MergeInsertSortVector(std::vector<int> &UnsortedVector, std::vector<int> &SortedVector);
void	CreateVectorPairs(std::vector<int> &MaxVector, std::vector<Content> &PairVector);
void	CreateSubMaxVector(std::vector<Content> &PairedVector, std::vector<int> &SubMaxVector);

void	MergeInsertSortDeque(std::deque<int> &UnsortedDeque, std::deque<int> &SortedDeque);
void	CreateDequePairs(std::deque<int> &MaxDeque, std::deque<Content> &PairDeque);
void	CreateSubMaxDeque(std::deque<Content> &PairDeque, std::deque<int> &SubMaxDeque);

std::vector<int>::iterator	BinarySearchPosition(Content Pair, std::vector<int> &SortedVector);
std::vector<int>::iterator	BinarySearch(int Element, std::vector<int> &SortedVector);

std::deque<int>::iterator	BinarySearchPosition(Content Pair, std::deque<int> &SortedDeque);
std::deque<int>::iterator	BinarySearch(int Element, std::deque<int> &SortedDeque);

int		JacobsthalGenerator(int n);

template<typename T>
void	DisplaySortedNumbers(T const &Container)
{
	for (size_t i = 0; i < Container.size(); i++)
	{
		if (i % 10 == 0 && i > 0)
			std::cout << std::endl;
		std::cout << Container[i] << ' ';
	}
	std::cout << std::endl;
}

#endif
