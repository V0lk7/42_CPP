/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:40:09 by jduval            #+#    #+#             */
/*   Updated: 2023/10/12 14:04:29 by jduval           ###   ########.fr       */
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
		std::cout << Container[i] << ' ';
	std::cout << std::endl;
}

template<typename T>
void	Display(T const &Container)
{
	for (size_t i = 0; i < Container.size(); i++)
		std::cout << Container[i] << " ";
	std::cout << std::endl;
}

template<typename T>
bool	VerifySorted(T const &Container)
{
	for (size_t i = 0; i < Container.size(); i++)
	{
		if (i + 1 < Container.size() && Container[i] > Container[i + 1])
			return (false);
	}
	return (true);
}

void	CreateNumbers(std::vector<int> &UnsortedNumbers, char **av);
void	CreateNumbers(std::deque<int> &UnsortedNumbers, char **av);

void	MergeInsertSort(std::vector<int> UnsortedVector, std::vector<int> &SortedVector);
//void	MergeInsertSort(std::deque<int> &UnsortedDeque, std::deque<int> &SortedDeque);

#endif
