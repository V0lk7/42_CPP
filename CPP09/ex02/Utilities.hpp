/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:26:42 by jduval            #+#    #+#             */
/*   Updated: 2023/10/04 15:52:15 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_HPP
# define UTILITIES_HPP

# include <vector>

struct	Content
{
	int		max;
	int		min;
};

void	CreateVList(std::vector<int> &VList, char **av);


void	MergeInsertSortVector(std::vector<int> &VList);
void	CreateVectorPairs(std::vector<int> &MaxVector, std::vector<Content> &PairedVector);
void	CreateSubMaxVector(std::vector<Content> &PairedVector, std::vector<int> &SubMaxVector);

std::vector<int>::iterator	BinarySearchPosition(Content Pair, std::vector<int> &SortedVector);
std::vector<int>::iterator	BinarySearch(int Element, std::vector<int> &SortedVector);

int		JacobsthalGenerator(int n);

#endif
