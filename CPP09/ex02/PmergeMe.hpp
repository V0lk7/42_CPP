/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:40:09 by jduval            #+#    #+#             */
/*   Updated: 2023/10/05 15:46:48 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>

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

struct	Content
{
	int		max;
	int		min;
};

void	CreateNumberVector(std::vector<int> &UnsortedNumbers, char **av);
void	CreateNumberDeque(std::deque<int> &UnsortedNumbers, char **av);

void	MergeInsertSortVector(std::vector<int> &UnsortedVector, std::vector<int> &SortedVector);
void	MergeInsertSortDeque(std::deque<int> &UnsortedDeque, std::deque<int> &SortedDeque);

#endif
