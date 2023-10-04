/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:26:42 by jduval            #+#    #+#             */
/*   Updated: 2023/10/04 09:45:40 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_HPP
# define UTILITIES_HPP

# include <vector>

struct	Content
{
	int		max;
	int		min;
	bool	Odd;
};

void	CreateVList(std::vector<int> &VList, char **av);
void	MergeInsertSortVector(std::vector<int> &VList);

#endif
