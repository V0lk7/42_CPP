/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:02:25 by jduval            #+#    #+#             */
/*   Updated: 2023/09/19 15:20:47 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename Type>
void	swap(Type &a, Type &b)
{
	Type	tmp = a;
	a = b;
	b = tmp;
	return ;
}

template<typename Type>
Type const	&min(Type const &a, Type const &b)
{
	return (a < b ? a : b);
}

template<typename Type>
Type const	&max(Type const &a, Type const &b)
{
	return (a > b ? a : b);
}
