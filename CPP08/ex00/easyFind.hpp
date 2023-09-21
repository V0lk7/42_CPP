/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:19:36 by jduval            #+#    #+#             */
/*   Updated: 2023/09/21 12:57:59 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
bool	easyFind(T container, int valueToFind)
{
	typename T::iterator	itBegin = container.begin();
	typename T::iterator	itEnd = container.end();

	if (find(itBegin, itEnd, valueToFind) != itEnd)
		return (true);
	else
		return (false);
}

#endif
