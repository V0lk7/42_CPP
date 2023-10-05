/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:26:42 by jduval            #+#    #+#             */
/*   Updated: 2023/10/05 12:09:24 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_HPP
# define UTILITIES_HPP

# include <vector>
# include <deque>

struct	Content
{
	int		max;
	int		min;
};

void	CreateNumberVector(std::vector<int> &UnsortedNumbers, char **av);
void	CreateDeque(std::vector<int> &UnsortedVector, std::deque<int> &Unsorteddeque);

double	MergeInsertSortVector(std::vector<int> &Vdeque);
void	CreateVectorPairs(std::vector<int> &MaxVector, std::vector<Content> &PairVector);
void	CreateSubMaxVector(std::vector<Content> &PairedVector, std::vector<int> &SubMaxVector);

double	MergeInsertSortdeque(std::deque<int> &Vdeque);
void	CreatedequePairs(std::deque<int> &Maxdeque, std::deque<Content> &Pairdeque);
void	CreateSubMaxdeque(std::deque<Content> &Pairdeque, std::deque<int> &SubMaxdeque);

std::vector<int>::iterator	BinarySearchPosition(Content Pair, std::vector<int> &SortedVector);
std::vector<int>::iterator	BinarySearch(int Element, std::vector<int> &SortedVector);

std::deque<int>::iterator	BinarySearchPosition(Content Pair, std::deque<int> &Sorteddeque);
std::deque<int>::iterator	BinarySearch(int Element, std::deque<int> &Sorteddeque);

int		JacobsthalGenerator(int n);

#endif
