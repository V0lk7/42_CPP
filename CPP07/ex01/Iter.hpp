/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:02:25 by jduval            #+#    #+#             */
/*   Updated: 2023/10/05 14:04:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename type, typename returnType>
void	iter(type *array, int length, returnType (*funcPtr))
{
	for (int i = 0; i < length; i++)
		(*funcPtr)(array[i]);
}

#endif
