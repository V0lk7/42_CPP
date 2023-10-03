/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:26:42 by jduval            #+#    #+#             */
/*   Updated: 2023/10/03 13:01:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_HPP
# define UTILITIES_HPP

# include <vector>

struct	Content
{
	int	max;
	int	min;
};

void	CreateVList(std::vector<int> &VList, char **av);
void	MergeInsertSortVector(std::vector<int> &VList);

#endif
