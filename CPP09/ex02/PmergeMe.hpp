/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:40:09 by jduval            #+#    #+#             */
/*   Updated: 2023/10/12 15:02:07 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>

template<typename T>
void	Display(T const &Container)
{
	size_t	size = Container.size();
	bool	TooMuch = false;

	if (size > 15)
	{
		size = 10;
		TooMuch = true;
	}
	for (size_t i = 0; i < size; i++)
		std::cout << Container[i] << " ";
	if (TooMuch == true)
		std::cout << "[...]" << std::endl;
	else
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

void	MergeInsertSort(std::vector<int> Unsorted, std::vector<int> &Sorted);
void	MergeInsertSort(std::deque<int> Unsorted, std::deque<int> &Sorted);

#endif
